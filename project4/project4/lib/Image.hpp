#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstdint>
#include <string>
#include <vector>


// RGBA pixel
struct Pixel {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t alpha;
};

// equality operators for Pixel struct
inline bool operator==(const Pixel &a, const Pixel &b) {
    return (a.red == b.red) && (a.green == b.green) && (a.blue == b.blue) &&
         (a.alpha == b.alpha);
}

inline bool operator!=(const Pixel &a, const Pixel &b) {
    return !(a == b); 
}

// Pixel constants for common colors
static const Pixel BLACK = {0, 0, 0, 255};
static const Pixel WHITE = {255, 255, 255, 255};
static const Pixel RED = {255, 0, 0, 255};
static const Pixel GREEN = {0, 255, 0, 255};
static const Pixel BLUE = {0, 0, 255, 255};



/** A simple image class.
 * An image is a rectangular array of type Pixel. */ 
class Image {
public:
  /** Construct an image given height and width.
   * @param height number of rows in the image
   * @param width number of columns in the image */ 
  Image(std::size_t height = 0, std::size_t width = 0);

  /** Get the width (columns) of the image */
  std::size_t width() const;

  /** Get the height (rows) of the image */
  std::size_t height() const;

  /** Get a reference to the pixel (T) at the specified location (r,c).
   * Use to assign the value of the pixel at this location.
   * @param r row index of pixel
   * @param c column index of pixel
   * @throws std::out_of_range if r >= height or c >= width */
  Pixel& operator()(std::size_t r, std::size_t c);

  /** Get a copy of the pixel (T) at the specified location (r,c).
   * Use to inspect the value of the pixel at this location.
   * @param r row index of pixel
   * @param c column index of pixel
   * @throws std::out_of_range if r >= height or c >= width */
  Pixel operator()(std::size_t r, std::size_t c) const;

private:
  std::size_t _width, _height;
  std::vector<Pixel> _data;
};

// read an Image of RGBA pixels from the PNG formatted file fname
// throws std::runtime_error on failure
Image readFromFile(std::string fname);

// write an Image of RGBA pixels from the PNG formatted file fname
// throws std::runtime_error on failure
void writeToFile(const Image& im, std::string fname);

#endif // IMAGE_HPP
