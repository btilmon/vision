#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include "utils/image.h"

using namespace std;

//////////
// Filters
//////////
image gaussian_kernel(int size, float sigma, int channels)
{
  assert((size % 2) != 0);
  image gauss = make_image(size, size, channels);
  float r, s = 2*sigma*sigma, sum = 0;

  // fill kernel
  for(int k = 0; k < channels; ++k){
    for(int n = -(gauss.h - 1)/2; n < (gauss.h - 1)/2; ++n){
      for(int m = -(gauss.w - 1)/2; m < (gauss.w - 1)/2; ++m){
	r = n*n + m*m;
        gauss.data[k*gauss.h*gauss.w + (n+(gauss.h - 1)/2)*gauss.w + (m + (gauss.w- 1)/2)] = exp(-r/(2*sigma*sigma)) / (2*M_PI*sigma*sigma);
	sum += gauss.data[k*gauss.h*gauss.w + (n+(gauss.h - 1)/2)*gauss.w + (m + (gauss.w- 1)/2)];
      }
    }
  }
  
  // normalize
  for(int k = 0; k < channels; ++k){
    for(int n = 0; n < gauss.h; ++n){
      for(int m = 0; m < gauss.w; ++m){
	gauss.data[k*gauss.h*gauss.w + n*gauss.w + m] /= sum;
      }
    }
  }
  return gauss;
}

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


//////////////
// Convolution
//////////////
float get_pixel_conv(image im, int n, int m, int c)
{
  if (n < 0 || m < 0 || n >= im.h || m >= im.w) return 0;
  return im.data[c*im.h*im.w + n*im.w + m];
}

image convolve(image im, image kern)
{
  int stride = 1;
  int pad = ((im.w - 1)*stride - im.w + kern.h)/2; // output size == input size
  int output_w = (im.w - kern.w + 2*pad)/stride + 1;
  int output_h = (im.h - kern.h + 2*pad)/stride + 1;
  
  image X = make_image(output_h, output_w, im.c);
  

  int recept_fields = kern.w*kern.h; 
  int col_idx = 0;
  for (int c = 0; c < im.c; ++c){
    for (int n = 0; n < output_h; ++n){
      for (int m = 0; m < output_w; ++m){
	for (int n_k = 0; n_k < kern.h; ++n_k){
	  for (int m_k = 0; m_k < kern.w; ++m_k){
	    int im_row = n + n_k - pad;
	    int im_col = m + m_k - pad;
	    X.data[c*X.w*X.h + n*im.w + m] += get_pixel_conv(im, im_row, im_col, c) * kern.data[n_k*kern.w + m_k];
	  }
	}
      }
    }
  }    
  return X;
}
 
