
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
<<<<<<< HEAD
void black_and_white();
void invert_image();
void merge_images();
void flip_image();
void rotate_image();
void darken_and_lighten_image();
=======
void doSomethingForImage ();
>>>>>>> parent of 159a584 (created the first 6 functions)

int main()
{

  loadImage();
<<<<<<< HEAD
=======
  doSomethingForImage();
>>>>>>> parent of 159a584 (created the first 6 functions)
  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
<<<<<<< HEAD
void black_and_white() {
    //code here

}

void invert_image() {
    //code here

}

void merge_images() {
    //code here

}

void flip_image() {
    //code here

}

void rotate_image() {
    //code here

}

void darken_and_lighten_image() {
    //code here
=======
void doSomethingForImage() {
    
>>>>>>> parent of 159a584 (created the first 6 functions)

}
