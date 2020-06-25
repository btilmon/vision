#include <Eigen/Dense>
#include <iostream>
#include "image.h"

using std::cout;
using std::endl;

Image elementwise_multiply(const Image& A, const Image& B)
{
  // for normal multplication
  //Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>> A_eig(A.data, A.h, A.w);
  //Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>> B_eig(B.data, B.h, B.w);

  // elemntwise
  //Eigen::Map<Eigen::ArrayXf> A_eig(A.data, A.h*A.w);
  //Eigen::Map<Eigen::ArrayXf> B_eig(B.data, B.h*B.w);

  Image hadamard(A.h, A.w, 1);
  for(int h=0; h<A.h; ++h){
    for(int w=0; w<A.w; ++w){
      hadamard(h,w,0) = A(h,w,0) * B(h,w,0);
    }
  }
  
  return hadamard;
}
