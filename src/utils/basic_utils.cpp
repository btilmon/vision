// image I/O

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

image make_empty_image(int h, int w, int c)
{
  image out;
  out.data = 0;
  out.h = h;
  out.w = w;
  out.c = c;
  return out;
}

image make_image(int h, int w, int c)
{
    image out = make_empty_image(h,w,c);
    out.data = new float[h*w*c](); //dynamically allocate memory
    return out;
}

image load_image(char *filename, int channels)
{
  //channels = 1 for grayscale, 3 for rgb 
  int h, w, ch;
  unsigned char* data = stbi_load(filename, &w, &h, &ch, channels);
  if (!data) {
    cout << "COULD NOT LOAD IMAGE, WRONG PATH." << endl;
  }

  image im = make_image(h, w, ch);
  for(int k = 0; k < ch; ++k)
    for(int n = 0; n < h; ++n)
      for(int m = 0; m < w; ++m){
	int src_idx =  k + m*ch + n*w*ch;
	int dst_idx =  w*h*k + w*n + m;	  
	im.data[dst_idx] = (float)data[src_idx]/255.;
	}
  free(data);
  return im;
}

void save_image(image im, const char *name)
{
  char buff[256];
  sprintf(buff, "%s", name);
  unsigned char *data = new unsigned char[im.h*im.w*im.c]();
  for(int k = 0; k < im.c; ++k)
    for(int i = 0; i < im.h*im.w; ++i){
      data[i*im.c + k] = (unsigned char)roundf((255.*im.data[i + k*im.h*im.w]));
    }
  int success = stbi_write_jpg(buff, im.w, im.h, im.c, data, 100);
  free(data);
  if(!success) fprintf(stderr, "Failed to write image %s\n", buff);
}


