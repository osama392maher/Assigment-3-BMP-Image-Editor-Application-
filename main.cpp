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
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];

void loadImage();
void loadImage2();
void saveImage();
void save_newImage();
void black_and_white();
void invert_image();
void merge_images();
void flip_image();
void rotate_image();
void darken_and_lighten_image();
void mirror_image();
void enlarge_image();
void shrink_image();
void detect_edges();
void shuffle_image();
void blur_image();

int main()
{
    int choice;

    cout << "  Helloo 😁" << endl;
    cout << "  Please select a filter to apply or 0 to exit:" << endl;
    cout << "    1- Black & White Filter" << endl;
    cout << "    2- Invert Filter" << endl;
    cout << "    3- Merge Filter" << endl;
    cout << "    4- Flip Image" << endl;
    cout << "    5- Rotate Image" << endl;
    cout << "    6- Darken and Lighten Image" << endl;
    cout << "    7- mirror " << endl;
    cout << "    8- detect image " << endl;
    cout << "    9- enlarge image " << endl;
    cout << "    10- Shrink image " << endl;
    cout << "    11- shuffle image " << endl;
    cout << "    12- Blur image " << endl;
    cout << "    0- exit" << endl;

    cin >> choice;

    if (choice == 1)
    {
        loadImage();
        black_and_white();
        saveImage();
    }

    else if (choice == 2)
    {
        loadImage();
        invert_image();
        saveImage();
    }

    else if (choice == 3)
    {
        loadImage();
        loadImage2();
        merge_images();
        save_newImage();
    }

    else if (choice == 4)
    {
        loadImage();
        flip_image();
        saveImage();
    }

    else if (choice == 5)
    {
        loadImage();
        rotate_image();
        saveImage();
    }

    else if (choice == 6)
    {
        loadImage();
        darken_and_lighten_image();
        saveImage();
    }

    else if (choice == 7)
    {
        loadImage();
        mirror_image();
        saveImage();
    }

    else if (choice == 8)
    {
        loadImage();
        detect_edges();
        save_newImage();
    }
    else if (choice == 9)
    {
        loadImage();
        enlarge_image();
        save_newImage();
    }

    else if (choice == 10)
    {
        loadImage();
        shrink_image();
        save_newImage();
    }
    else if (choice == 11)
    {
        loadImage();
        shuffle_image();
        save_newImage();
    }
    else if (choice == 12)
    {
        loadImage();
        blur_image();
        saveImage();
    }
    else if (choice == 0)
    {
        return 0;
    }
    else
    {
        cout << "Invalid Input";
    }
}

//_________________________________________
void loadImage()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_________________________________________
void loadImage2()
{
    char imageFileName[100];

    // Get gray scale image 2 file name
    cout << "Enter the source image 2 file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image 2
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image2);
}

//_________________________________________
void saveImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________
void save_newImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, new_image);
}

//_________________________________________
void black_and_white()
{
    //creating sum variable
    long long sum = 0;

    //get the average of all pixles
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum += image[i][j];

        }
    }

    //creating the average varible and calucalte it
    long long average = sum / (256 * 256);

    //comapare every pixel to the average
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // if pixel is above average then be white else black
            if (image[i][j] > average)
            {
                image[i][j] = 255;
            }
            else
            {
                image[i][j] = 0;
            }

        }
    }
}

//_________________________________________
void invert_image()
{
    //go to every pixel and substract 255 from it
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = 255 - image[i][j];

        }
    }
}

//_________________________________________
void merge_images()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            //get the average of the corresponding pixels in the two images and get the average and store it in new image
            new_image[i][j] = (image[i][j] + image2[i][j]) / 2;
        }
    }
}

//_________________________________________
void flip_image()
{
    //ask the user how he want to filp the image
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
            for (int j = 0; j < SIZE / 2; j++)
            {
                swap(image[i][j], image[i][SIZE - j]);
            }
        }

    }
}

//_________________________________________
void rotate_image()
{

    int choice;

    //ask the user how he want to rotate the image
    cout << "How do you want to rotate the image? 😌" << endl;
    cout << "1- To rotate the image clockwise by 90 " << endl;
    cout << "2- To rotate the image clockwise by 180 " << endl;
    cout << "3- To rotate the image clockwise by 270 " << endl;

    cin >> choice;

    if (choice == 1)
    {
        // Rotate the image clockwise by 90
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = i; j < SIZE; j++)
            {
                if (i != j)
                {
                    int temp = image[i][j];
                    image[i][j] = image[j][i];
                    image[j][i] = temp;
                }
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE / 2; j++)
            {
                int temp = image[i][j];
                image[i][j] = image[i][SIZE - j - 1];
                image[i][SIZE - j - 1] = temp;
            }
        }
    }

    if (choice == 2)
    {
        // Rotate the image clockwise by 180

        for (int i = 0; i < SIZE / 2; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                int temp = image[i][j];
                image[i][j] = image[SIZE - i - 1][j];
                image[SIZE - i - 1][j] = temp;
            }
        }
    }

    if (choice == 3)
    {

        // Rotate the image clockwise by 270
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = i; j < SIZE; j++)
            {

                if (i != j)
                {
                    int temp = image[i][j];
                    image[i][j] = image[j][i];
                    image[j][i] = temp;
                }
            }
        }

    }

}

//_________________________________________
void darken_and_lighten_image()
{
    //ask the user if he want to lighten the image or darken it
    int choice;
    cout << "What you want to do in the image?" << endl;
    cout << "1- Lighten the image" << endl;
    cout << "2- Darken the image" << endl;
    cin >> choice;

    //lighten image
    if (choice == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = ((image[i][j]) + 255) / 2;
            }

        }
    }
    //darken image
    if (choice == 2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = (image[i][j]) / 2;


            }
        }
    }

}

//_________________________________________
void mirror_image()
{

    int choice;

    //ask the user how he want to mirror the image
    cout << "how do you want to mirror the image ?" << endl;
    cout << "1- lower 1/2" << endl;
    cout << "2- Upper 1/2" << endl;
    cout << "3- right 1/2" << endl;
    cout << "4- left  1/2 " << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        //Upper 1/2
        for (int i = 0; i < SIZE / 2; i++)
        {
            copy(std::begin(image[i]), std::end(image[i]), std::begin(image[SIZE - i]));
        }
        break;

    case 2:
        //lower 1/2
        for (int i = 0; i < SIZE / 2; i++)
        {
            copy(std::begin(image[SIZE - i]), std::end(image[SIZE - i]), std::begin(image[i]));
        }
        break;

    case 3:
        // Right 1/2
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE / 2; j++)
            {
                image[i][j] = image[i][SIZE - j];
            }
        }
        break;

    case 4:
        // left 1/2
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE / 2; j++)
            {
                image[i][SIZE - j] = image[i][j];
            }
        }
        break;
    }

}

//_________________________________________
void detect_edges()
{
    //create gx and gy matrixs
    int gx_val[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };

    int gy_val[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };

    double gx, gy;
    int i_index = 0;
    int j_index = 0;
    int pixel_val;

    //get the gx/gy sum
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            gx = 0;
            gy = 0;

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {

                    i_index = (i - 1) + x;
                    j_index = (j - 1) + y;

                    if (0 <= i_index && i_index <= 255 && 0 <= j_index && j_index <= 255)
                    {
                        gx += image[i_index][j_index] * gx_val[x][y];
                        gy += image[i_index][j_index] * gy_val[x][y];
                    }
                }
            }

            //calculate the square root 
            pixel_val = round(sqrt((gx * gx) + (gy * gy)));

            //see if the pixel value is greater than 255
            if (pixel_val > 255)
            {
                pixel_val = 255;
            }

            new_image[i][j] = pixel_val;
        }
    }

    // black every non white pixel
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            if (new_image[i][j] != 255)
            {
                new_image[i][j] = 0;
            }
    }

    //invert the image 
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            if (new_image[i][j] == 255)
            {
                new_image[i][j] = 0;
            }
            else if (new_image[i][j] == 0)
            {
                new_image[i][j] = 255;
            }
        }
    }
}

//_________________________________________
void enlarge_image() {
    
    // see which part user want to enlarge
    int part;
    cout << "please enter the part you want to enlarge: ";
    cin >> part;
    
    // enlarge part 1
    if (part==1){
    int ii = 0, jj = 0;
        for (int i = 0;i < SIZE;i += 2) {
            for (int j = 0; j < SIZE; j += 2) {

                new_image[i][j] = image[ii][jj];
                new_image[i][j + 1] = image[ii][jj];
                new_image[i + 1][j] = image[ii][jj];
                new_image[i + 1][j + 1] = image[ii][jj];
                jj += 1;
            }
            jj = 0;
            ii += 1;
        }
    }
    
    // enlarge part 2
    else if (part == 2) {
        int ii = 0, jj = SIZE / 2;

        for (int i = 0;i < SIZE;i += 2) {
            for (int j = 0; j < SIZE; j += 2) {

                new_image[i][j] = image[ii][jj];
                new_image[i][j + 1] = image[ii][jj];
                new_image[i + 1][j] = image[ii][jj];
                new_image[i + 1][j + 1] = image[ii][jj];
                jj += 1;
            }
            jj = SIZE / 2;
            ii += 1;
        }
    }

    // enlarge part 3
    else if (part == 3) {
        int ii = SIZE / 2, jj = 0;

        for (int i = 0;i < SIZE;i += 2) {
            for (int j = 0; j < SIZE; j += 2) {

                new_image[i][j] = image[ii][jj];
                new_image[i][j + 1] = image[ii][jj];
                new_image[i + 1][j] = image[ii][jj];
                new_image[i + 1][j + 1] = image[ii][jj];
                jj += 1;
            }
            jj = 0;
            ii += 1;
        }
    }

    //enlarge part 4
    else if (part == 4) {

        int ii = SIZE / 2, jj = SIZE / 2;

        for (int i = 0;i < SIZE;i += 2) {
            for (int j = 0; j < SIZE; j += 2) {

                new_image[i][j] = image[ii][jj];
                new_image[i][j + 1] = image[ii][jj];
                new_image[i + 1][j] = image[ii][jj];
                new_image[i + 1][j + 1] = image[ii][jj];
                jj += 1;
            }
            jj = SIZE / 2;
            ii += 1;
        }
    }
    else
    {
        cout<<"sorry,invalid";
    }

}

//_________________________________________
void shrink_image() {

    //ask the user he want to shrink the image
    int choice;
    cout << "How do you want to shrink the photo?" << endl;
    cout << "1- Shrink it to the half " << endl;
    cout << "2- Shrink it to the third " << endl;
    cout << "3- Shrink it to the quarter " << endl;
    cin >> choice;

    int k = 0, l = 0;

    //shrink to 1/2
    if (choice == 1) {
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                new_image[k][l] = image[i][j];
                l++;
            }
            l = 0;
            k++;
        }
    }
    
    //shrink to 1/3
    else if (choice == 2) {
        for (int i = 0; i < SIZE; i += 3) {
            for (int j = 0; j < SIZE; j += 3) {
                new_image[k][l] = image[i][j];
                l++;
            }
            l = 0;
            k++;
        }
    }
    //shrink to 1/4
    else if (choice == 3) {
        int k = 0, z = 0;
        for (int i = 0; i < SIZE; i += 4) {
            for (int j = 0; j < SIZE; j += 4) {
                new_image[k][l] = image[i][j];
                l++;
            }

            l = 0;
            k++;
        }
    }
}

//_________________________________________
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
                new_image[ii][jj] = image[start][secondStart];
                jj++;
            }
            ii++;
            jj = fixed_jj;
        }

    }
}

//_________________________________________
void blur_image() {
   
    long long sum = 0;
    long long average = 0;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // calulate the sum of the pixels in the same row, column and diagonal
            sum = (image[i][j] + image[i + 1][j + 1] + image[i + 2][j + 2] + image[i + 3][j + 3] + image[i + 4][j + 4] + image[i + 5][j + 5] + image[i + 6][j + 6] +
                image[i][j + 6] + image[i + 1][j + 5] + image[i + 2][j + 4] + image[i + 4][j + 2] + image[i + 5][j + 1] + image[i + 6][j] +
                image[i + 3][j] + image[i + 3][j + 1] + image[i + 3][j + 2] + image[i + 3][j + 4] + image[i + 3][j + 5] + image[i + 3][j + 6] +
                image[i][j + 3] + image[i + 1][j + 3] + image[i + 2][j + 3] + image[i + 4][j + 3] + image[i + 5][j + 3] + image[i + 6][j + 3]);
           
            //calculate the average of the pixels
            average = sum / 25;
            image[i + 3][j + 3] = average;

            //blur the parties of the image
            sum = (image[i][j + 1] + image[i][j - 1] + image[i + 1][j + 1] + image[i + 1][j - 1] + image[i + 1][j + 2] + image[i - 1][j - 2] + image[i - 1][j] + image[i][j - 1]);
            average = sum / 8;
            image[i][j] = average;

        }
    }
}
