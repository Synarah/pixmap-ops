/**
 *Creates an instance of an image and saves a png file and then class functions from 
 the image.cpp class and alter the image
 * @author ssitaf
 * Feb 9, 2023
 */
#include <iostream>
#include "image.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   // todo: make at least one artwork!
   Image image;
   if (!image.load("../images/earth.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }
   Image art = image.boarder(); 
   Image art2 = art;
   art2 = art2.invert();
   Image art3 = art2;
   art3 = art3.blur();
   art3.save("earth-art.png"); 
   return 0;
}

