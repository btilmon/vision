#ifndef IMAGE_H
#define IMAGE_H

#include <cstring>
#include <assert.h>
#include <vector>


using namespace std;

struct Image;
int pixel_address(const Image& im, int h, int w, int c);
//void set_pixel(Image& im, int h, int w, int c, float val);

struct Image
  {
  int h=0;
  int w=0;
  int c=0;
  float *data=nullptr;

  // constructor
  Image() = default;
  
  Image(int h, int w, int c) : h(h), w(w), c(c), data(nullptr)
    {
    assert(h>=0 && w>=0 && c >=0 && "Invalid image sizes");

    if(h*w*c)
      data = new float[h*w*c]();
    }
  
  // destructor
  ~Image() { delete[] data; }

  // copy constructor
  Image(const Image& from) : data(nullptr) {*this = from;}

  // move constructor
  Image(Image&& from) : data(nullptr) {*this = move(from);}

  //copy assignment
  Image& operator = (const Image& from)
    {
    if(this == &from) return *this;
    if(data) {delete[] data; data = nullptr;}
    w=h=c=0;
    data = new float[from.h*from.w*from.c]();

    h=from.h;
    w=from.w;
    c=from.c;
    memcpy(data, from.data,h*w*c*sizeof(float));
    return *this;
    }

  // move assignment
  Image& operator = (Image&& from)
    {
    if(this == &from) return *this;

    if(data) delete[] data;

    h = from.h;
    w = from.w;
    c = from.c;
    data = from.data;

    from.data = nullptr;
    from.h=from.w=from.c=0;
    return *this;
    }

  // pixel access
  
    float& operator()(int y, int x, int ch)
    {
    assert(ch<c && ch>=0 && x<w && x>=0 && y<h && y>=0 && "access out of bounds");
    return data[pixel_address(*this, y, x, ch)];
    }
  

  const float& operator()(int y, int x, int ch) const
    {
    assert(ch<c && ch>=0 && x<w && x>=0 && y<h && y>=0 && "access out of bounds");
    return data[pixel_address(*this, y, x, ch)];
    }

  void load_image(const string& filename);
  void save_image(const string& filename) const;
  void clamp(void);
  void feature_normalize(void);

  };

// A 2d point.
// float x, y: the coordinates of the point.
struct Point 
  {
  double x, y;
  
  Point() : x(0), y(0) {}
  Point(double x, double y) : x(x), y(y) {}
  };

// A descriptor for a point in an image.
// point p: x,y coordinates of the image pixel.
// vector<float> data: the descriptor for the pixel.
struct Descriptor
  {
  Point p;
  vector<float> data;
  
  Descriptor(){}
  Descriptor(const Point& p) : p(p) {}
  };


// image stitching
vector<Descriptor> harris_corner_detector(const Image& im);
Image structure_matrix(const Image& im);


void print_size(const Image& im);

// Image I/O
inline Image load_image(char *filename) {Image im; im.load_image(filename); return im;};
inline void save_image (const Image& im, const string& filename) { im.save_image (filename); }

// color space
Image rgb2gray(const Image& im);

// misc
void clamp_image(Image& im);
void determine_cpp_version();
void normalize(Image& im);
float min(const Image& im);
float max(const Image& im);

// filtering
Image gaussian_kernel(float sigma);
Image convolve(const Image& im, const Image& kern);
Image blur(const Image& im, float sigma);
Image sobel_gx(const Image& im);
Image sobel_gy(const Image& im);
pair<Image,Image> sobel(const Image& im);
void feature_normalize(Image& im);

#endif
