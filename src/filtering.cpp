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

Image gaussian_kernel(float sigma)
  {
  assert(sigma<=1 && "Kernel too big");
  int size = sigma*6;
  if(size%2==0) {size-=1;}
  Image gauss(size, size, 1);
  float r, s = 2*sigma*sigma;
  
  for(int n = -(gauss.h - 1)/2; n < (gauss.h - 1)/2; ++n){
    for(int m = -(gauss.w - 1)/2; m < (gauss.w - 1)/2; ++m){
      r = n*n + m*m;
      gauss(n+(gauss.h - 1)/2, m + (gauss.w- 1)/2, 0) = exp(-r/(2*sigma*sigma)) / (2*PI*sigma*sigma);
    }
  }
  normalize(gauss);
  return gauss;
  }

// sobel
Image sobel_gx(const Image& im)
{
  assert(im.c==1 && "Image must be grayscale.");
  Image k1(1,3,1); k1={1, 0, -1};
  Image k2(3,1,1); k2={1, 2, 1};
  Image gx = convolve(convolve(im, k1), k2);
  return gx;
}

Image sobel_gy(const Image& im)
{
  assert(im.c==1 && "Image must be grayscale.");
  Image k1(1,3,1); k1={1, 2, 1};
  Image k2(3,1,1); k2={1, 0, -1};
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

  // calcuate Theta
  Image Theta(im.h,im.w,im.c);
  for(int h=0; h<Theta.h; ++h){
    for(int w=0; w<Theta.w; ++w){
      Theta(h,w,0) = 0;//atan(  gy(h,w,0)/gx(h,w,0) ) * 180/PI;
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
Image blur(const Image& im, float sigma)
{
  return convolve(im, gaussian_kernel(sigma));
}

float get_pixel_conv(const Image& im, int n, int m, int c)
{
  // zero pad
  if (n < 0 || m < 0 || n >= im.h || m >= im.w) return 0;
  return im(n, m, c);
}

Image convolve(const Image& im, const Image& kern)
{
  int stride = 1;
  int pad = ((im.w - 1)*stride - im.w + kern.h)/2; // output size == input size
  int output_w = (im.w - kern.w + 2*pad)/stride + 1;
  int output_h = (im.h - kern.h + 2*pad)/stride + 1;
  
  Image X(output_h, output_w, im.c);
  int recept_fields = kern.w*kern.h; 
  int col_idx = 0;
  
  for (int c = 0; c < im.c; ++c){
    for (int n = 0; n < output_h; ++n){
      for (int m = 0; m < output_w; ++m){
	for (int n_k = 0; n_k < kern.h; ++n_k){
	  for (int m_k = 0; m_k < kern.w; ++m_k){
	    int im_row = n + n_k - pad;
	    int im_col = m + m_k - pad;
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
