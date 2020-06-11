#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "vision/stb_image.h"
#include "image.h"


using namespace std;


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
    out.data = (float*) calloc(h*w*c, sizeof(float));
    return out;
}


//channels = 1 for grayscale, 3 for rgb 
image load_image(char *filename, int channels)
{
  int h, w, ch;
  unsigned char *data = stbi_load(filename, &w, &h, &ch, channels);
  if (!data) {
    cout << "COULD NOT LOAD IMAGE, WRONG PATH." << endl;
  }

  // convert 1D unsigned char to 3D float
  int i, j, k;
  image im = make_image(h, w, channels)
  for(k = 0; k < channels; ++k){
    for(i = 0; i < h; ++i){
      for(j = 0; j < w; ++j){
	cout < (float)data[]
      }
    }
  }
  
  
  
  //free(img_out);
  
}

int main()
{
  load_image("/home/bjt/Documents/research/vision/src/keble_a.jpg", 3);
}
