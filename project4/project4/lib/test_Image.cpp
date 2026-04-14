#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "Image.hpp"

TEST_CASE( "Image test", "[Image]" ) {

  Image im(200,100);
    
  REQUIRE( im.height() == 200 );
  REQUIRE( im.width() == 100 );

  for(int r = 0; r < im.height(); r++)
    for(int c = 0; c < im.width(); c++){
      im(r,c).red = 0;
      im(r,c).green = 0;
      im(r,c).blue = 0;
      im(r,c).alpha = 255;
    }

  writeToFile(im, "temp.png");

  Image imcopy = readFromFile("temp.png");

  for(int r = 0; r < im.height(); r++)
    for(int c = 0; c < im.width(); c++){
      REQUIRE(imcopy(r,c).red == 0);
      REQUIRE(imcopy(r,c).green == 0);
      REQUIRE(imcopy(r,c).blue == 0);
      REQUIRE(imcopy(r,c).alpha == 255);
    }
}
