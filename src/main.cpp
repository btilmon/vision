#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <Eigen/Dense>
#include "image.h"


using namespace std;
using namespace std::chrono;
//using Eigen::MatrixXd;

int main()
  {
    Image ref = rgb2gray(load_image("/home/bjt/Documents/research/vision/src/img/keble_b.jpg"));
    Image left = rgb2gray(load_image("/home/bjt/Documents/research/vision/src/img/keble_a.jpg"));
    
    /*
      1. Calculate corners and describe corners
      3. Match features and estimate homography simultaneously using RANSAC
      4. combine images with homography matrix
    */
    
    Image test(2,2,1); //test(0,0,0)=1; test(0,1,0)=2; test(1,0,0)=3; test(1,1,0)=4;

    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>> test_eig(ref.data, ref.h, ref.w);
    ref.data = test_eig.data();

    ref.save_image("/home/bjt/Documents/research/vision/src/test.jpg");
    
    vector<Descriptor> ref_d = harris_corner_detector(ref);
    
  }


