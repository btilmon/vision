#ifndef IMAGE_H
#define IMAGE_H

struct image{
  int h,w,c;
  float *data; 
};


// load image
image make_image(int h, int w, int c);
image make_empty_image(int h, int w, int c);
image load_image(char *filename, int channels);
void save_image(image im, const char *name);

// misc
void determine_cpp_version();

#endif
