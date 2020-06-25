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

#define PI 3.14159265


void test()
{
  Image ref = rgb2gray(load_image("/home/bjt/Documents/research/vision/src/img/keble_b.jpg"));

  Image k1(3,1,1);
  k1(0,0,0) = 1; k1(1,0,0) = 2; k1(2,0,0) = 1;
  
  Image k2(1,3,1);
  k2(0,0,0) = 1; k2(0,1,0) = 2; k2(0,2,0) = 1;

  Image k_norm(3,3,1);// k1(0,0,0)=1; k1(0,1,0)=0; k1(0,2,0)=-1;
  k_norm(0,0,0)=1; k_norm(0,1,0)=0; k_norm(0,2,0)=-1;
  k_norm(1,0,0)=2; k_norm(1,1,0)=0; k_norm(1,2,0)=-2;
  k_norm(2,0,0)=1; k_norm(2,1,0)=0; k_norm(2,2,0)=-1;
  
  auto start = high_resolution_clock::now(); 
  Image filt = convolve(convolve(ref, k1), k2);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout<< "seperable: " << duration.count() << endl;


  start = high_resolution_clock::now(); 
  Image filt2 = convolve(ref, k_norm);
  stop = high_resolution_clock::now();
  duration = duration_cast<milliseconds>(stop - start);
  cout<< "normal: " << duration.count() << endl;
  
  
  print_size(ref);
  print_size(filt);
  print_size(filt2);
}

int main()
  {
      
    /*
      1. Calculate corners and describe corners
      3. Match features and estimate homography simultaneously using RANSAC
      4. combine images with homography matrix
    */

    Image ref = rgb2gray(load_image("/home/bjt/Documents/research/vision/src/img/keble_b.jpg"));
    //Image left = rgb2gray(load_image("/home/bjt/Documents/research/vision/src/img/keble_a.jpg"));

    vector<Descriptor> ref_d = harris_corner_detector(ref);
  
    
    
  }


