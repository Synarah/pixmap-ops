// Copyright 2021, Aline Normoyle, alinen

#include "image.h"

#include <cassert>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

namespace agl {


Image::Image() {
   myw = 0;
   myh = 0;
}

Image::Image(int width, int height)  {
   myw = width;
   myh = height;
   numchannels = 3;
   mydata = new Pixel[width * height];  
}

Image::Image(const Image& orig) {
   myw = orig.myw;
   myh = orig.myh;
   numchannels = orig.numchannels;
   mydata = orig.mydata;
  
}

Image& Image::operator=(const Image& orig) {
  if (&orig == this) {
    return *this;
  }
   int nw = orig.myw;
   int nh = orig.myh;
   Pixel* ndata = orig.mydata;
   myw = nw;
   myh = nh;
   mydata = ndata;
  return *this;
}

Image::~Image() {
}

int Image::width() const { 
   return myw;
}

int Image::height() const {
   return myh;
}

char* Image::data() const {
   return (char*)mydata;
}

void Image::set(int width, int height, unsigned char* data) {
   myw = width;
   myh = height;
   mydata = (Pixel*) data;
}

bool Image::load(const std::string& filename, bool flip) {
  mydata = (Pixel*) stbi_load(filename.c_str(),&myw, &myh, &numchannels, 3);
  if(mydata == NULL){
      return false; 
  }
  else{
     return true;
  }
  
}


bool Image::save(const std::string& filename, bool flip) const {
   if(mydata == NULL){
      return false;
   }
   else{
      stbi_write_png(filename.c_str(), myw, myh, numchannels, mydata, myw*3);
      return true;
   }
  
}

Pixel Image::get(int row, int col) const {
   Pixel temp = mydata[row*myw + col];
   return temp;
}

void Image::set(int row, int col, const Pixel& color) {
   mydata[row*myw + col] = color;
}


Pixel Image::get(int i) const{
   Pixel temp = mydata[i];
   return temp;
}

void Image::set(int i, const Pixel& c){
   mydata[i] = c;
}

Image Image::resize(int w, int h) const {
   Image result(w, h);
   float propr, propc;
   int oldr, oldc;
   for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
         propr = (float) i / (h-1);
         oldr = floor(propr * (myh - 1));
         propc = (float) j / (w - 1);
         oldc = floor(propc * (myw - 1));
         result.set(i, j, get(oldr, oldc));
      }
   }
   return result;
}

Image Image::flipHorizontal() const {
   Image result(myw, myh);
   int newh = 0;
   int oldh = myh;
   int curCol = 0;
   while (newh < myh){
      while(curCol < myw){
         result.set(newh, curCol, get(oldh,curCol));
         curCol++;
      }
      newh++;
      oldh--;
      curCol = 0;
   }
   return result;

}

Image Image::flipVertical() const {
   Image result(0, 0);
   return result;
}

Image Image::rotate90() const {
   Image result(0, 0);
  
   return result;
}

Image Image::subimage(int startx, int starty, int w, int h) const {
   Image sub(w, h);
   for(int i = starty; i < starty + h; i++){
      for(int j = startx; j < startx + w; j++){
         sub.set(i - starty, j - startx, get(i,j));
      }
   }
    return sub;
}

void Image::replace(const Image& image, int startx, int starty) {
   for(int i = starty; i < (starty + image.height()); i++){
      for(int j = startx; j < (startx + image.width()); j++){
         set(i, j, image.get(i - starty,j - startx));
      }
   }
}

Image Image::swirl() const {
   Image result(0, 0);
   return result;
}

Image Image::add(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::subtract(const Image& other) const {
   Image result(0, 0);
   
   return result;
}

Image Image::multiply(const Image& other) const {
   Image result(0, 0);
   
   return result;
}

Image Image::difference(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::lightest(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::darkest(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::gammaCorrect(float gamma) const {
   Image result(myw, myh);
   float red,green,blue;
   for(int i = 0; i < myh; i++){
      for(int j = 0; j < myw; j++){
         struct Pixel temp =  get(i,j);
            red = pow(((float)temp.r / 255), (1/gamma));
            temp.r = red * 255;
            green = pow(((float)temp.g / 255), (1/gamma));
            temp.g = green * 255;
            blue = pow(((float)temp.b / 255), (1/gamma));
            temp.b = blue * 255;
            result.set(i,j,temp);
      }
   }
   return result;
}

Image Image::alphaBlend(const Image& other, float alpha) const {
   Image result(myw, myh);
   for(int i = 0; i < myh; i++){
      for(int j = 0; j < myw; j++){
         Pixel thisIm = get(i,j);
         Pixel otherIm = other.get(i,j);
         Pixel temp;
         temp.r = (thisIm.r * alpha) + (otherIm.r * (1 - alpha));
         temp.g = (thisIm.g * alpha) + (otherIm.g * (1 - alpha));
         temp.b = (thisIm.b * alpha) + (otherIm.b * (1 - alpha));
         result.set(i,j,temp);
      }
   }
   return result;
}

Image Image::invert() const {
   Image image(0, 0);
   
   return image;
}

Image Image::grayscale() const {
   Image result(myw, myh);
   for(int i = 0; i < myh; i++){
      for(int j = 0; j < myw; j++){
         Pixel temp = get(i,j);
         unsigned char inten = (temp.r * 0.3) + (temp.g * 0.59) + (temp.b * 0.11);
         Pixel correct = {inten,inten,inten};
         result.set(i,j,correct);
      }
   }
   return result;
}

Image Image::colorJitter(int size) const {
   Image image(0, 0);
  
   return image;
}

Image Image::bitmap(int size) const {
   Image image(0, 0);
   
   return image;
}

void Image::fill(const Pixel& c) {
  }

}  // namespace agl

