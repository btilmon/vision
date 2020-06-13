#include <stdlib.h>
#include "utils/image.h"

int main()
{
  image im = load_image("/home/bjt/Documents/research/vision/src/keble_a.jpg", 3);
  save_image(im, "/home/bjt/Documents/research/vision/src/test_save.jpg"); 
  free(im.data); // ALWAYS prevent memory leak by deleting pointer to image data
}
