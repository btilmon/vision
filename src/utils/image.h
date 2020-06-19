#ifndef IMAGE_H
#define IMAGE_H

struct image{
  int h,w,c;
  float *data; 
};

// pixel indexing
float get_pixel(image im, int h, int w, int c);
void set_pixel(image im, int h, int w, int c, float val);

// image inits
image make_image(int h, int w, int c);
image make_empty_image(int h, int w, int c);
image copy_image(image src);
void print_size(image im);

// image I/O
image load_image(char *filename);
void save_image(image im, const char *name);

// color space
image rgb2gray(image im);

// misc
void determine_cpp_version();
void normalize(image im);

#endif
