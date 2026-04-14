#include <stdexcept>

#include "Image.hpp"

#include "lodepng.h" // for file I/O

Image::Image(std::size_t height, std::size_t width)
    : _height(height), _width(width) {

  _data.resize(_height * _width);
}

std::size_t Image::width() const { return _width; }

std::size_t Image::height() const { return _height; }

Pixel& Image::operator()(std::size_t r, std::size_t c) {

  if ((r >= _height) || (c >= _width))
    throw std::out_of_range("Image: Invalid location in operator()");

  return _data[r * _width + c];
}


Pixel Image::operator()(std::size_t r, std::size_t c) const {

  if ((r >= _height) || (c >= _width))
    throw std::out_of_range("Image: Invalid location in operator()");

  return _data[r * _width + c];
}


Image readFromFile(std::string fname) {

  std::vector<unsigned char> raw;
  unsigned h, w;

  // decode the png
  unsigned error = lodepng::decode(raw, w, h, fname.c_str());

  if (error)
    throw std::runtime_error(lodepng_error_text(error));

  Image im(h, w);
  std::size_t idx = 0;
  for (std::size_t r = 0; r < im.height(); r++)
    for (std::size_t c = 0; c < im.width(); c++) {
      im(r, c).red = raw[idx++];
      im(r, c).green = raw[idx++];
      im(r, c).blue = raw[idx++];
      im(r, c).alpha = raw[idx++];
    }

  return im;
}


void writeToFile(const Image &im, std::string fname) {

  std::vector<unsigned char> raw(4 * im.width() * im.height());

  std::size_t idx = 0;
  for (std::size_t r = 0; r < im.height(); r++)
    for (std::size_t c = 0; c < im.width(); c++) {
      raw[idx++] = im(r, c).red;
      raw[idx++] = im(r, c).green;
      raw[idx++] = im(r, c).blue;
      raw[idx++] = im(r, c).alpha;
    }

  // encode the image
  unsigned error = lodepng::encode(fname.c_str(), raw, im.width(), im.height());

  if (error)
    throw std::runtime_error(lodepng_error_text(error));
}
