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

  // TODO: breadth-first search

  // TODO: Write solution image to file
  
}
