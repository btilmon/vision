#include <vector>
#include <iostream>
#include "image.h"

using namespace std;

Image structure_matrix(const Image& im)
{
  Image S(im.h, im.w, 2);
  Image Ix = sobel_gx(im);
  Image Iy = sobel_gy(im);
  
  //Image Ix2 = matrix_multiply(Ix, Ix); 
  //Image Iy2 =
  //Image IxIy = 

    
  return S;
}

vector<Descriptor> harris_corner_detector(const Image& im)
{
  float sigma = 1;

  Image S = structure_matrix(im);

  vector<Descriptor> test;
  return test;
}
