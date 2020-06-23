#include <iostream>
#include <cmath>
#define STB_IMAGE_IMPLEMENTATION
#include "vision/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "vision/stb_image_write.h"
#include "image.h"

using namespace std;

void determine_cpp_version()
{
  if (__cplusplus == 201703L)
    std::cout << "C++17" << endl;
  else if (__cplusplus == 201402L)
    std::cout << "C++14" << endl;
  else if (__cplusplus == 201103L)
    std::cout << "C++11" << endl;
  else if (__cplusplus == 199711L)
    std::cout << "C++98" << endl;
  else
    std::cout << "pre-standard C++" << endl;
}

void print_size(const Image& im)
  {
  cout << "Image [HxWxC]: [" << im.h << ", " << im.w << ", " << im.c << "]" << endl;
  }


// Image I/O
Image load_image_stb(const string& filename)
  {
  //channels = 1 for grayscale, 3 for rgb 
  int h, w, ch, channels = 3;
  unsigned char* data = stbi_load(filename.c_str(), &w, &h, &ch, channels);
  if (!data) {
    cout << "COULD NOT LOAD IMAGE, WRONG PATH." << endl;
  }

  Image im(h, w, ch);
  for(int k = 0; k < ch; ++k){
    for(int n = 0; n < h; ++n){
      for(int m = 0; m < w; ++m){
	int src_idx =  k + m*ch + n*w*ch;
	int dst_idx =  w*h*k + w*n + m;	  
	im.data[dst_idx] = (float)data[src_idx]/255.;
      }
    }
  }
  delete[] data;
  return im;
  }

void save_image_stb(const Image& im, const string& name)
  {

  unsigned char *data = new unsigned char[im.h*im.w*im.c]();
  for(int k = 0; k < im.c; ++k){
    for(int i = 0; i < im.h*im.w; ++i){
      data[i*im.c + k] = (unsigned char)roundf((255.*im.data[i + k*im.h*im.w]));
    }
  }
  int success = stbi_write_jpg(name.c_str(), im.w, im.h, im.c, data, 100);
  delete[] data;
  
  }

// pixel indexing
int pixel_address(const Image& im, int n, int m, int c)
  {
  assert(n<=im.h && n>=0 && m<=im.w && m>=0 && c<=im.c && c>=0);
  return c*im.h*im.w + n*im.w + m;
  }

void set_pixel(Image& im, int n, int m, int c, float val)
  {
  assert( (n < im.h) && (m < im.w) && (c < im.c) );
  //im.data[c*im.h*im.w + n*im.w + m] = val;
  }

// color space

Image rgb2gray(const Image& im)
  {
  Image gray(im.h, im.w, 1);
  float scale[] = {.299, 0.587, 0.114};
  for(int c=0; c<im.c; ++c){
    for(int h=0; h<im.h; ++h){
      for(int w=0; w<im.w; ++w){
	gray(h,w,0) += scale[c]*im(h,w,c);
      }
    }
  }
	
  return gray;
  }

void clamp_image(Image& im)
{
  for(int c=0; c<im.c; ++c){
    for(int h=0; h<im.h; ++h){
      for(int w=0; w<im.w; ++w){
	if(im(h,w,c)>1.0) {im(h,w,c) = 1.0;}
	if(im(h,w,c)<0.0) {im(h,w,c) = 0.0;}
      }
    }
  }
}

// data ranges
float min(const Image& im)
  {
  float min = im(0,0,0);
  for(int h=0; h<im.h; ++h){
    for(int w=0; w<im.w; ++w){
      if(im(h,w,0) < min)
	{
	min = im(h,w,0);
	}
    }
  }
  return min;
  }

float max(const Image& im)
  {
  float max = im(0,0,0);
  for(int h=0; h<im.h; ++h){
    for(int w=0; w<im.w; ++w){
      if(im(h,w,0) > max)
	{
	max = im(h,w,0);
	}
    }
  }
  return max;
  }

// member functions
void Image::load_image(const string& filename) { *this=load_image_stb(filename); }
void Image::save_image(const string& name) const { save_image_stb(*this, name); }
void Image::clamp(void) {clamp_image(*this);}
