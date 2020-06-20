#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <cstring>
#include "image.h"



using namespace std;
using namespace std::chrono;
  
 
int main()
  {
  Image gray = rgb2gray(load_image("/home/bjt/Documents/research/vision/src/keble_a.jpg"));
  gray.feature_normalize();
  //Image filtered = blur(gray, 1);
  /*
  for(int c=0; c<gauss.c; ++c){
    for(int h=0; h<gauss.h; ++h){
      for(int w=0; w<gauss.w; ++w){
	//cout << gauss(h,w,c) << " ";
      }
      //cout << endl;
    }
  }
  */

  //filtered.save_image("/home/bjt/Documents/research/vision/src/gauss.jpg");
  
  }


