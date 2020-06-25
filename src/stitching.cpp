#include <vector>
#include <iostream>
#include "image.h"
#include "matrix.h"



Image structure_matrix(const Image& im, float sigma)
{
  Image M(im.h, im.w, 3);
  Image Ix = sobel_gx(im);
  Image Iy = sobel_gy(im);

  Image Ix2 = blur(elementwise_multiply(Ix, Ix), sigma);  
  Image Iy2 = blur(elementwise_multiply(Iy, Iy), sigma);
  Image IxIy = blur(elementwise_multiply(Ix, Iy), sigma); 
  
  for(int h=0; h<M.h; ++h){
    for(int w=0; w<M.w; ++w){
      M(h,w,0) = Ix2(h,w,0);
      M(h,w,1) = Iy2(h,w,0);
      M(h,w,2) = IxIy(h,w,0);
    }
  } 
  return M;
}

Image corner_response(const Image& M)
{
  Image R(M.h, M.w, 1);
  for(int h=0; h<M.h; ++h){
    for(int w=0; w<M.w; ++w){
      float det = M(h,w,0)*M(h,w,1) - M(h,w,2)*M(h,w,2);
      float trace = M(h,w,0) + M(h,w,1);
      R(h,w,0) = det/trace;
    }
  }
  return R;
}

Image non_max_suppression(const Image& im, int window, float thres)
{

  int stride = 1;
  int pad_h = ((im.h - 1)*stride - im.h + window)/2; // output size == input size
  int pad_w = ((im.w - 1)*stride - im.w + window)/2;

  int output_w = (im.w - window + 2*pad_w)/stride + 1;
  int output_h = (im.h - window + 2*pad_h)/stride + 1;  
  Image X = im;//(output_h, output_w, im.c);

  for (int n = 0; n < output_h; ++n){
    for (int m = 0; m < output_w; ++m){
      for (int n_k = 0; n_k < window; ++n_k){
	for (int m_k = 0; m_k < window; ++m_k){
	  int im_row = n + n_k - pad_h;
	  int im_col = m + m_k - pad_w;
	  float pix = get_pixel_conv(im, im_row, im_col, 0);
	  if(pix > X(n,m,0) || X(n,m,0) < thres){
	    X(n,m,0) = 0;
	    }
	}
      }
    }
  }

 
  return X;
}

std::vector<Descriptor> descriptors(const Image& im, const Image& NMS, float thresh, int window)
{
  int count =0;
  for(int n=0; n<im.h; ++n){
    for(int m=0; m<im.w; ++m){
      if(NMS(n,m,0) > 0){
	count += 1;
      }
    }
  }
  std::cout << count << std::endl;
}

std::vector<Descriptor> harris_corner_detector(const Image& im)
{
  Image M = structure_matrix(im, 5);

  Image R = corner_response(M);

  Image NMS = non_max_suppression(R, 5, .15);
  R.save_image("/home/bjt/Documents/research/vision/src/response.jpg");
  NMS.save_image("/home/bjt/Documents/research/vision/src/nms.jpg");

  return descriptors(im, NMS, 1.5, 40);
}
