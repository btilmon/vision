#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <cstring>
#include "utils/image.h"
#include "utils/filtering.h"


using namespace std;
using namespace std::chrono;
  
 
int main()
{
  image gray = load_image("/home/bjt/Documents/research/vision/src/resize.jpg");

  image k = gaussian_kernel(5,3,1);

  auto start = high_resolution_clock::now();
  //image dest;
  //std::memcpy ( &dest, &gray, sizeof(gray) );
  image filt = convolve(gray, k);
  auto stop = high_resolution_clock::now(); 
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << duration.count() << endl;

  
  save_image(filt, "/home/bjt/Documents/research/vision/src/filt.jpg");
  
  delete gray.data;
  
  //delete kernel.data;
  
}
