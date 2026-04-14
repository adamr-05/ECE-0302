
INCLUDE_DIRECTORIES(${PS4_SOURCE_DIR}/lib)

LINK_DIRECTORIES(${PS4_BINARY_DIR}/lib)

ADD_LIBRARY(image Image.hpp Image.cpp lodepng.h lodepng.cpp)
set_property(TARGET image PROPERTY CXX_STANDARD 11)

# create unittests
ADD_EXECUTABLE(test-image test_Image.cpp)
TARGET_LINK_LIBRARIES(test-image image)

