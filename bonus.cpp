// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: filters.cpp // Last Modification Date: 5/4/2022
      // Author1 and ID : Osama Maher Masoued    20210060
     // Author2 and ID : Nada Essam El_Din Essa 20211104
     // Author3 and ID : Sara Adel Hanafy Bayoumi 20211046
     // Group : S1 - S2
     // Teaching Assistant: Nesma
     // Purpose: create a program that apply filters to photos

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char new_image[SIZE][SIZE][RGB];

void loadImage ();
void loadImage2();
void saveImage ();
void save_newImage();
void black_and_white();
void invert_image();
void flip_image();
void mirror_image();
void merge_images();
void detect_edges();
void rotate_image();
void darken_and_lighten_image();
void shrink_image();
void enlarge_image();
void shuffle_image();

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
  cout <<"    8- detect image " << endl;
  cout <<"    9- Shrink image " << endl;
  cout <<"    10- enlarge image " << endl;
  cout <<"    11- shuffle image " << endl;
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
    loadImage2();
    merge_images();
    save_newImage();
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

  else if (choice == 8){
    loadImage();
    detect_edges();
    save_newImage();
  }

  else if (choice == 9) {
      loadImage();
      shrink_image();
      save_newImage();
  }
    else if (choice == 10) {
      loadImage();
    enlarge_image();
      save_newImage();
  }
  
    else if (choice == 11) {
      loadImage();
    shuffle_image();
      save_newImage();
  }
  
  else if (choice == 0){
    return 0;
  }
  else{
      cout << "Invalid Input";
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
   readRGBBMP(imageFileName, image);
}

//_________________________________________
void loadImage2() {
    char imageFileName[100];

    // Get gray scale image 2 file name
    cout << "Enter the source image 2 file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image 2
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image2);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

//_________________________________________
void save_newImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, new_image);
}

//_________________________________________
void black_and_white() {
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (image[i][j][0] + image[i][j][1] + image[i][j][2]  >= 128 * 3){
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
            else{
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;            
            }
        }
    }
}

//_________________________________________
void invert_image() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0 ; k < RGB; k++){

            image[i][j][k] = 255 - image[i][j][k];

        }
    }
}
}

//_________________________________________
void merge_images() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0 ; k < RGB; k++){
              new_image[i][j][k] = (image[i][j][k] + image2[i][j][k]) / 2;
            }
        }
    }
}
//_________________________________________
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

  if (choice == 1){
    // flip horizontally
    for (int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE / 2; j++){
          swap(image[i][j][0],image[i][SIZE - j][0]);
          swap(image[i][j][1],image[i][SIZE - j][1]);
          swap(image[i][j][2],image[i][SIZE - j][2]);
      }
    }
    
  }
}
//_________________________________________
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
                    for (int k = 0;k < RGB;k++) {
                        int temp = image[i][j][k];
                        image[i][j][k] = image[j][i][k];
                        image[j][i][k] = temp;
                    }
                }
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0;k < RGB;k++) {
                    int temp = image[i][j][k];
                    image[i][j][k] = image[i][SIZE - j - 1][k];
                    image[i][SIZE - j - 1][k] = temp;
                }
                }
            }
    }

    if (choice == 2) {
        // Rotate the image clockwise by 180

        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0;k < RGB;k++) {
                    int temp = image[i][j][k];
                    image[i][j][k] = image[SIZE - i - 1][j][k];
                    image[SIZE - i - 1][j][k] = temp;
                }
            }
        }
    }

    if (choice == 3) {
    
        // Rotate the image clockwise by 270
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = i; j < SIZE; j++) {
                
                if (i != j) {
                    for (int k = 0;k < RGB;k++) {
                        int temp = image[i][j][k];
                        image[i][j][k] = image[j][i][k];
                        image[j][i][k] = temp;
                    }
                }
            }
        }

    }

}
//_________________________________________
void darken_and_lighten_image() {

  int choice;
	cout << "What you want to do in the image?" << endl;
	cout << "1- Lighten the image" << endl;
	cout << "2- Darken the image" << endl;
	cin >> choice;

	//lighten image
	if (choice == 1) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    image[i][j][k] = ((image[i][j][k]) + 255) / 2;
                }
			}

		}
	}
	//darken image
	if (choice == 2) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    image[i][j][k] = (image[i][j][k]) / 2;
                }
			}
		}
	}

}

//_________________________________________
void mirror_image(){

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
            for (int j = 0; j < SIZE; j++){  
                image[i][j][0] = image[SIZE - i][j][0];
                image[i][j][1] = image[SIZE - i][j][1];
                image[i][j][2] = image[SIZE - i][j][2];
        }
        }
        break;

      case 2:
      //lower 1/2
      for (int i = 0; i < SIZE / 2; i++){
        for (int j = 0; i < SIZE; j++){
                image[SIZE - i][j][0] = image[i][j][0];
                image[SIZE - i][j][1] = image[i][j][1];
                image[SIZE - i][j][2] = image[i][j][2];
  
        }
        }
        break;
      case 3:
      // Right 1/2
      for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE; j++){
          image[i][j][0] = image[i][SIZE - j][0];
          image[i][j][1] = image[i][SIZE - j][1];
          image[i][j][2] = image[i][SIZE - j][2];

        }
      }
      break;

      case 4:
      // left 1/2
      for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE / 2; j++){
          image[i][SIZE - j][0] = image[i][j][0];
          image[i][SIZE - j][1] = image[i][j][1];
          image[i][SIZE - j][2] = image[i][j][2];

          
        }
      }
      break;
  
}
}
//_________________________________________

void detect_edges() {

int gx_val[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};

int gy_val[3][3] = {{-1,-2,-1},
                    {0, 0, 0},
                    {1, 2, 1}};

double gx_red, gy_red, gx_blue, gy_blue, gx_green, gy_green;
int i_index = 0;
int j_index = 0;
int red_val, green_val, blue_val;

for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++){
        gx_red = 0;
        gx_green = 0;
        gx_blue = 0;
        gy_red = 0;
        gy_green = 0;
        gy_blue = 0;

        for (int x = 0; x < 3; x++){
            for (int y = 0; y < 3; y++){

                i_index = (i - 1) + x;
                j_index = (j - 1) + y;

                if (0 <= i_index && i_index <= 255 && 0 <= j_index && j_index <= 255){
                    gx_red += image[i_index][j_index][0] * gx_val[x][y];
                    gx_green += image[i_index][j_index][1] * gx_val[x][y];
                    gx_blue += image[i_index][j_index][2] * gx_val[x][y];
                    gy_red += image[i_index][j_index][0] * gy_val[x][y];
                    gy_green += image[i_index][j_index][1] * gy_val[x][y];
                    gy_blue += image[i_index][j_index][2] * gy_val[x][y];
                }
            }
        }

        red_val = round(sqrt((gx_red * gx_red) + (gy_red * gy_red)));
        green_val = round(sqrt((gx_green * gx_green) + (gy_green * gy_green)));
        blue_val = round(sqrt((gx_blue * gx_blue) + (gy_blue * gy_blue)));

        if (red_val > 255) {
          red_val = 255;
        }
        if (green_val > 255) {
          green_val = 255;
        }
        if (blue_val > 255) {
          blue_val = 255;
        }
        
        new_image[i][j][0] = red_val;
        new_image[i][j][1] = green_val;
        new_image[i][j][2] = blue_val;
    }
}
}

//_________________________________________
void shrink_image() {

    int choice;
    cout << "How do you want to shrink the photo?" << endl;
    cout << "1- Shrink it to the half " << endl;
    cout << "2- Shrink it to the third " << endl;
    cout << "3- Shrink it to the quarter " << endl;
    cin >> choice;

    int m = 0, z = 0, l = 0;

    if (choice == 1) {
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                for (int k = 0; k < RGB; k++) {
                    new_image[m][z][l] = image[i][j][k];
                    l++;
                }
                l = 0;
                z++;
            }
            l = 0;
            z = 0;
            m++;
        }
    }

    else if (choice == 2) {
        for (int i = 0; i < SIZE; i += 3) {
            for (int j = 0; j < SIZE; j += 3) {
                for (int k = 0; k < RGB; k++) {
                    new_image[m][z][l] = image[i][j][k];
                    l++;
                }

                l = 0;
                z++;
            }
            l = 0;
            z = 0;
            m++;
        }
    }

    else if (choice == 3) {
        int m = 0, z = 0;
        for (int i = 0; i < SIZE; i += 4) {
            for (int j = 0; j < SIZE; j += 4) {
                for (int k = 0; k < RGB; k++) {
                    new_image[m][z][l] = image[i][j][k];
                    l++;
                }

                l = 0;
                z++;
            }
            l = 0;
            z = 0;
            m++;
        }
    }

}
void enlarge_image() {
    int part;
    cout << "please enter the part you want to enlarge: ";
    cin >> part;
    if (part == 1) {
        int ii = 0, jj = 0;
        for (int i = 0;i < SIZE;i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                for (int k = 0;k < RGB;k++) {
                    new_image[i][j][k] = image[ii][jj][k];
                    new_image[i][j + 1][k] = image[ii][jj][k];
                    new_image[i + 1][j][k] = image[ii][jj][k];
                    new_image[i + 1][j + 1][k] = image[ii][jj][k];
                }
                jj += 1;
            }
            jj = 0;
            ii += 1;
        }
    }
    else if (part == 2) {
        int ii = 0, jj = SIZE / 2;
        for (int i = 0;i < SIZE;i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                for (int k = 0;k < RGB;k++) {
                    new_image[i][j][k] = image[ii][jj][k];
                    new_image[i][j + 1][k] = image[ii][jj][k];
                    new_image[i + 1][j][k] = image[ii][jj][k];
                    new_image[i + 1][j + 1][k] = image[ii][jj][k];
                }
                jj += 1;
            }
            jj = SIZE / 2;
            ii += 1;
        }
    }
    else if (part == 3) {
        int ii = SIZE / 2, jj = 0;
        for (int i = 0;i < SIZE;i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                for (int k = 0;k < RGB;k++) {
                    new_image[i][j][k] = image[ii][jj][k];
                    new_image[i][j + 1][k] = image[ii][jj][k];
                    new_image[i + 1][j][k] = image[ii][jj][k];
                    new_image[i + 1][j + 1][k] = image[ii][jj][k];
                }
                jj += 1;
            }
            jj = 0;
            ii += 1;
        }
    }
    else if (part == 4) {
        int ii = SIZE / 2, jj = SIZE / 2;
        for (int i = 0;i < SIZE;i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                for (int k = 0;k < RGB;k++) {
                    new_image[i][j][k] = image[ii][jj][k];
                    new_image[i][j + 1][k] = image[ii][jj][k];
                    new_image[i + 1][j][k] = image[ii][jj][k];
                    new_image[i + 1][j + 1][k] = image[ii][jj][k];
                }
                jj += 1;
            }
            jj = SIZE / 2;
            ii += 1;
        }
    }
    else
    {
        cout << "sorry,invalid";
    }
}
void shuffle_image() {
    int part, i, j, ii, jj;

    for (int times = 1; times < 5; times++) {

        cout << "enter part " << times << endl;
        cin >> part;
        switch (part) {
        case 1:
            i = 0;
            j = 0;
            break;
        case 2:
            i = 0;
            j = SIZE / 2;
            break;

        case 3:
            i = SIZE / 2;
            j = 0;
            break;
        case 4:
            i = SIZE / 2;
            j = SIZE / 2;
            break;
        default:
            cout << "Invalid input";
        }

        if (times == 1) {
            ii = 0;
            jj = 0;
        }

        else if (times == 2) {
            ii = 0;
            jj = SIZE / 2;
        }
        else if (times == 3) {
            ii = SIZE / 2;
            jj = 0;
        }
        else if (times == 4) {
            ii = SIZE / 2;
            jj = SIZE / 2;
        }
        int fixed_jj = jj;
        for (int start = i; start < i + (SIZE / 2); start++) {
            for (int secondStart = j; secondStart < j + (SIZE / 2); secondStart++) {
                for (int k = 0;k < RGB;k++) {
                    new_image[ii][jj][k] = image[start][secondStart][k];
                }
                jj++;
            }
            ii++;
            jj = fixed_jj;
        }

    }
}