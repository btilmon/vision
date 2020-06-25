#include <math.h>
#include <iostream>
#include <assert.h>
#include "image.h"

using namespace std;

#define PI 3.14159265

//////////
// Filters
//////////

void normalize(Image& im)
  {
    float sum;
  for(int c=0; c<im.c; ++c){
    for(int h=0; h<im.h; ++h){
      for(int w=0; w<im.w; ++w){
        sum += im(h,w,c);
      }
    }
  }
  
  for(int c=0; c<im.c; ++c){
    for(int h=0; h<im.h; ++h){
      for(int w=0; w<im.w; ++w){
	im(h,w,c) /= sum;
      }
    }
  }
  }

void feature_normalize(Image& im)
{
  assert(im.h*im.w && im.c==1 && "Empty image");
  float minimum=min(im);
  float maximum=max(im);
  float range = maximum-minimum;
  
  for(int h=0; h<im.h; ++h){
    for(int w=0; w<im.w; ++w){
      im(h,w,0) = (im(h,w,0)-minimum)/range; 
    }
  }
}


pair<Image, Image> gaussian_kernel(float sigma)
  {
    // seperable gaussian kernel 
    //assert(sigma<=2 && "Kernel too big");
    int size = 5;//sigma*6;
    if(size%2==0) {size-=1;}

    Image k1(size,1,1); Image k2(1,size,1);
    float r, s = 2*sigma*sigma;

    for(int n = -(k1.h - 1)/2; n <= (k1.h - 1)/2; ++n){
      r = n*n;
      k1(n+(k1.h - 1)/2, 0, 0) = exp(-r/(2*sigma*sigma)) / (2*PI*sigma*sigma);
      k2(0, n+(k2.w - 1)/2, 0) = exp(-r/(2*sigma*sigma)) / (2*PI*sigma*sigma);
    }

    normalize(k1); normalize(k2);
    return {k1, k2};
  }

Image blur(const Image& im, float sigma)
{
  pair<Image, Image> kern = gaussian_kernel(sigma);
  return convolve(convolve(im, kern.first), kern.second);
}

// sobel
Image sobel_gx(const Image& im)
{
  assert(im.c==1 && "Image must be grayscale.");
  Image k1(3,1,1);
  k1(0,0,0)=1; k1(1,0,0)=2; k1(2,0,0)=1;
  Image k2(1,3,1);
  k2(0,0,0)=1; k2(0,1,0)=0; k2(0,2,0)=-1;
  Image gx = convolve(convolve(im, k2), k1);
  return gx;
}

Image sobel_gy(const Image& im)
{
  assert(im.c==1 && "Image must be grayscale.");
  Image k1(3,1,1);
  k1(0,0,0)=1; k1(1,0,0)=0; k1(2,0,0)=-1;
  Image k2(1,3,1);
  k2(0,0,0)=1; k2(0,1,0)=2; k2(0,2,0)=1;
  Image gy = convolve(convolve(im, k1), k2);
  return gy;
}

pair<Image,Image> sobel(const Image& im)
{
  // calculate G
  Image G(im.h,im.w,im.c);
  Image gx = sobel_gx(im); Image gy = sobel_gy(im);
  for(int h=0; h<G.h; ++h){
    for(int w=0; w<G.w; ++w){
      G(h,w,0) = sqrt( pow(gx(h,w,0),2) + pow(gy(h,w,0),2) );
    }
  }

  G.feature_normalize();
  
  // calcuate Theta
  Image Theta(im.h,im.w,im.c);
  for(int h=0; h<Theta.h; ++h){
    for(int w=0; w<Theta.w; ++w){
      Theta(h,w,0) = atan(  gy(h,w,0)/gx(h,w,0) ) * 180/PI;
    }
  }
  return {G, Theta};
}


/*
image highpass()
{
  image highpass = make_image(3, 3, 1);
  set_pixel(highpass, 0, 1, 0, -1);
  set_pixel(highpass, 2, 1, 0, -1);
  set_pixel(highpass, 1, 0, 0, -1);
  set_pixel(highpass, 1, 2, 0, -1);
  set_pixel(highpass, 1, 1, 0, 4);
  return highpass;
}
*/


//////////////
// Convolution
/////////////

float get_pixel_conv(const Image& im, int n, int m, int c)
{
  // zero pad
  if (n < 0 || m < 0 || n >= im.h || m >= im.w) return 0;
  return im(n, m, c);
}

Image convolve(const Image& im, const Image& kern)
{
  int stride = 1;
  int pad_h = ((im.h - 1)*stride - im.h + kern.h)/2; // output size == input size
  int pad_w = ((im.w - 1)*stride - im.w + kern.w)/2;

  int output_w = (im.w - kern.w + 2*pad_w)/stride + 1;
  int output_h = (im.h - kern.h + 2*pad_h)/stride + 1;
  
  Image X(output_h, output_w, im.c);
  //print_size(X);
  int recept_fields = kern.w*kern.h; 
  int col_idx = 0;
  
  for (int c = 0; c < im.c; ++c){
    for (int n = 0; n < output_h; ++n){
      for (int m = 0; m < output_w; ++m){
	for (int n_k = 0; n_k < kern.h; ++n_k){
	  for (int m_k = 0; m_k < kern.w; ++m_k){
	    int im_row = n + n_k - pad_h;
	    int im_col = m + m_k - pad_w;
	    X(n,m,c) += get_pixel_conv(im, im_row, im_col, c)*kern(n_k, m_k, 0);
	  }
	}
      }
    }
  }    
  return X;
}

///////////////////
// member functions
///////////////////
void Image::feature_normalize(void) {::feature_normalize(*this);}
