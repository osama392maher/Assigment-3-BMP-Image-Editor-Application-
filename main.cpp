
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
void black_and_white();
void invert_image();
void merge_images();
void flip_image();
void rotate_image();
void darken_and_lighten_image();

int main()
{
  int choice;

  cout <<"  Helloo 😁" << endl;
  cout <<"  Please select a filter to apply or 0 to exit:" << endl;
  cout <<"    1- Black & White Filter" << endl ;
  cout <<"    2- Invert Filter" << endl;
  cout <<"    3- Merge Filter" << endl;
  cout <<"    4- Flip Image" << endl;
  cout <<"    5- Rotate Image" << endl;
  cout <<"    6- Darken and Lighten Image" << endl;

  cin >> choice;
  
  if (choice == 1){
    loadImage();
    black_and_white();
    saveImage();
  }

  else if (choice == 2){
    loadImage();
    invert_image();
    saveImage();
  }

  else if (choice == 3){
    loadImage();
    merge_images();
    saveImage();
  }
  
  else if (choice == 4){
    loadImage();
    flip_image();
    saveImage();
  }

  else if (choice == 5){
    loadImage();
    rotate_image();
    saveImage();
  }

  else if (choice == 6){
    loadImage();
    darken_and_lighten_image();
    saveImage();
  }
  
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
void black_and_white() {
    
    long long sum = 0;
    
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            sum += image[i][j];

        }
    }

    long long average = sum / (256 * 256);

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (image[i][j] > average)
                image[i][j] = 255;
            else
                image[i][j] = 0;

        }
    }
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

}