#include <cstdlib>
#include <iostream>
#include <string>

#include <vector>
#include <utility>

#include "lib/Image.hpp"
#include "List.hpp"
#include "Queue.hpp"

//row/colum pair "State" (coordinates)
typedef std::pair<std::size_t, std::size_t> State;

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


  //queue of positions to check next
  Queue<State, List<State>> frontier;
  //grid of image height and width with either true/false in each square (true if visited)
  std::vector<std::vector<bool>> visited(image.height(), std::vector<bool>(image.width(), false));
  //starting state is "visited" 
  visited[start_row][start_col] = true;
  //enqueue start State to frontier
  frontier.enqueue(State(start_row, start_col));

  //edge case -- start pixel is already at exit
  if (start_row == 0 || start_row == image.height() - 1 ||
      start_col == 0 || start_col == image.width() - 1)
  {
    image(start_row, start_col) = GREEN; //set pixel to green
    writeToFile(image, output_file);    //write final image
    std::cout << "Solution Found" << std::endl;
    return EXIT_SUCCESS;
  }

  while (frontier.isEmpty() == false)
  {
    //grab next State coordinates from frontier queue, then remove it
    State currentState = frontier.peekFront();
    frontier.dequeue();

    //check its neighbors (up down left right)
    
    //UP conditions. ROW > 0, at top cant go up, not visited yet, and white (empty space -- not a wall)
    if (currentState.first > 0 &&
        !visited[currentState.first - 1][currentState.second] &&
        image(currentState.first - 1, currentState.second) == WHITE)
    {
      //if at edge (solution found)
      //get nextrow and nextcolumn values
      std::size_t nr = currentState.first - 1;
      std::size_t nc = currentState.second;

      if (nr == 0 || nr == image.height() - 1 ||
          nc == 0 || nc == image.width() - 1)
      {
        image(nr, nc) = GREEN; //set pixel to green
        writeToFile(image, output_file);    //write final image
        std::cout << "Solution Found" << std::endl;
        return EXIT_SUCCESS;
      }

      // otherwise mark visited and enqueue
      {
        visited[nr][nc] = true;
        frontier.enqueue(State(nr, nc));
      }
    }







    //DOWN conditions. ROW < edge, at bottom cant go down, not visited yet, and white (empty space -- not a wall)
    if (currentState.first < image.height() - 1 &&
        !visited[currentState.first + 1][currentState.second] &&
        image(currentState.first + 1, currentState.second) == WHITE)
    {
      //if at edge (solution found)
      //get nextrow and nextcolumn values
      std::size_t nr = currentState.first + 1;
      std::size_t nc = currentState.second;

      if (nr == 0 || nr == image.height() - 1 ||
          nc == 0 || nc == image.width() - 1)
      {
        image(nr, nc) = GREEN; //set pixel to green
        writeToFile(image, output_file);    //write final image
        std::cout << "Solution Found" << std::endl;
        return EXIT_SUCCESS;
      }

      // otherwise mark visited and enqueue
      {
        visited[nr][nc] = true;
        frontier.enqueue(State(nr, nc));
      }
    }



    //LEFT conditions. COL > 0, at left edge cant go left, not visited yet, and white (empty space -- not a wall)
    if (currentState.second > 0 &&
        !visited[currentState.first][currentState.second - 1] &&
        image(currentState.first, currentState.second - 1) == WHITE)
    {
      //if at edge (solution found)
      //get nextrow and nextcolumn values
      std::size_t nr = currentState.first;
      std::size_t nc = currentState.second - 1;

      if (nr == 0 || nr == image.height() - 1 ||
          nc == 0 || nc == image.width() - 1)
      {
        image(nr, nc) = GREEN; //set pixel to green
        writeToFile(image, output_file);    //write final image
        std::cout << "Solution Found" << std::endl;
        return EXIT_SUCCESS;
      }

      // otherwise mark visited and enqueue
      {
        visited[nr][nc] = true;
        frontier.enqueue(State(nr, nc));
      }
    }




    //RIGHT conditions. COL < edge, at right edge cant go right, not visited yet, and white (empty space -- not a wall)
    if (currentState.second < image.width() - 1 &&
        !visited[currentState.first][currentState.second + 1] &&
        image(currentState.first, currentState.second + 1) == WHITE)
    {
      //if at edge (solution found)
      //get nextrow and nextcolumn values
      std::size_t nr = currentState.first;
      std::size_t nc = currentState.second + 1;

      if (nr == 0 || nr == image.height() - 1 ||
          nc == 0 || nc == image.width() - 1)
      {
        image(nr, nc) = GREEN; //set pixel to green
        writeToFile(image, output_file);    //write final image
        std::cout << "Solution Found" << std::endl;
        return EXIT_SUCCESS;
      }

      // otherwise mark visited and enqueue
      {
        visited[nr][nc] = true;
        frontier.enqueue(State(nr, nc));
      }
    }
  }
      //no exit found
    writeToFile(image, output_file);
    std::cout << "No Solution Found" << std::endl;
    return EXIT_SUCCESS;
}