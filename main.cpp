#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

void loadImage ();
void saveImage ();
void black_and_white();
void invert_image();
void merge_images();
void flip_image();
void rotate_image();
void darken_and_lighten_image();
void mirror_image();

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
  cout <<"    7- mirror " << endl;
  cout <<"    0- exit" << endl;

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

  else if (choice == 7){
    loadImage();
    mirror_image();
    saveImage();
  } 
  else if (choice == 0){
    return 0;
  }
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

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
}
void merge_images() {
    //code

}

void flip_image() {
  int choice;
  cout << "How do you want to flip the image? 😌" << endl;
  cout << "1- Horizontally" << endl;
  cout << "2- Vertically" << endl;
  cin >> choice;

  if (choice == 2)
  {
      // flip vertically
      for (int i = 0; i < SIZE / 2; i++)
      {
          swap(image[i], image[SIZE - i]);
      }
  }
  
  if (choice == 1)
  { 
    // flip horizontally
    for (int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE / 2; j++){
          swap(image[i][j],image[i][SIZE - j]);
      }
    }
    
  }
}

void rotate_image() {

    int choice;
    
    cout << "How do you want to rotate the image? 😌" << endl;
    cout << "1- To rotate the image clockwise by 90 " << endl;
    cout << "2- To rotate the image clockwise by 180 " << endl;
    cout << "3- To rotate the image clockwise by 270 " << endl;
    
    cin >> choice;
    
    if (choice == 1) {
    
        // Rotate the image clockwise by 90 
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = i; j < SIZE; j++) {
                if (i != j) {
                    int temp = image[i][j];
                    image[i][j] = image[j][i];
                    image[j][i] = temp;
                }
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE / 2; j++) {
             
                    int temp = image[i][j];
                    image[i][j] = image[i][SIZE-j-1];
                    image[i][SIZE-j-1] = temp;
                }
            }
    }

    if (choice == 2) {
        // Rotate the image clockwise by 180 
        
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE; j++) {
    
                int temp = image[i][j];
                image[i][j] = image[SIZE-i-1][j];
                image[SIZE-i-1][j] = temp;
            }
        }
    }

    if (choice == 3) {
    
        // Rotate the image clockwise by 270
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = i; j < SIZE; j++) {
                
                if (i != j) {
                    int temp = image[i][j];
                    image[i][j] = image[j][i];
                    image[j][i] = temp;
                }
            }
        }
        
    }

}

void darken_and_lighten_image() {
    //code here

}
void mirror_image() {

    int choice;

    cout << "how do you want to mirror the image ?" << endl;
    cout << "1- lower 1/2" << endl;
    cout << "2- Upper 1/2" << endl;
    cout << "3- right 1/2" << endl;
    cout << "4- left  1/2 " << endl;

    cin >> choice;

    switch (choice) {
      case 1:
      //Upper 1/2 
        for (int i = 0; i < SIZE / 2; i++){
          copy(std::begin(image[i]), std::end(image[i]), std::begin(image[SIZE - i]));
        }
        break;

      case 2:
      //lower 1/2
      for (int i = 0; i < SIZE / 2; i++){
          copy(std::begin(image[SIZE - i]), std::end(image[SIZE - i]), std::begin(image[i]));
        }
        break;

      case 3:
      // Right 1/2
      for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE / 2; j++){
          image[i][j] = image[i][SIZE - j];
        }
      }
      break;

      case 4:
      // left 1/2
      for (int i = 0; i < SIZE; i++)
      { 
        for (int j = 0; j < SIZE / 2; j++){
          image[i][SIZE - j] = image[i][j];
        }
      }
      break; 
  }

}