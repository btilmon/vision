#ifndef IMAGE_H
#define IMAGE_H

typedef struct{
  int h,w,c;
    float *data;
} image;


// load image
image load_image(char *filename);
image make_image(int h, int w, int c);

#endif
