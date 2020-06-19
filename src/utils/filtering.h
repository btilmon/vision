#include "utils/image.h"

// filters
image gaussian_kernel(int size, float sigma, int channels);
image highpass();

//convolution
float get_pixel_conv(image im, int n, int m, int c);
image convolve(image im, image kern);

