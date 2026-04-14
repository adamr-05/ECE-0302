#include <cstdlib>
#include <iostream>
#include <string>

#include "lib/Image.hpp"
#include "List.hpp"
#include "Queue.hpp"

int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // Read input image from file
  Image image = readFromFile(input_file);

  //track startrow and startcol, and redpixels
  std::size_t start_row = 0, start_col = 0;
  int red_count = 0;

  //loop through entire image
  for (std::size_t r = 0; r < image.height(); r++)
  {
    for (std::size_t c = 0; c < image.width(); c++)
    {
      Pixel p = image(r, c);
      
      //if pixel is red, startpos found
      if (p == RED)
      {
        start_row = r;
        start_col = c;
        red_count++;
      }

      //if pixel is not red, black, or white, it is invalid
      else if (p != BLACK && p != WHITE)
      {
        std::cerr << "Error: Invaid pixel color in image" << std::endl;
        return EXIT_FAILURE;
      }
    }
  }

  //check for multiple red or no red pixels
  if (red_count == 0)
  {
    std::cerr << "Error: No red pixel found (start pixel)" << std::endl;
    return EXIT_FAILURE;
  }
  if (red_count > 1)
  {
    std::cerr << "Error: Must be only one red start pixel" << std::endl;
    return EXIT_FAILURE;
  }
    




  // TODO: breadth-first search

  // TODO: Write solution image to file
  
}
