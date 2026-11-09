#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<math.h>


const int cubeWidth = 40;
const int width = 180;
const int height = 44;

float A = 0;
float B = 0;
float C = 0;

int distance = 50;
float k1 = 10;
float zBuffer[width*height];
char Buffer[width*height];
int ascii_background_code = ' ';
float ooz;
int xp, yp, idx;

float calculateX(float i, float j, float k){
    return k*sin(B) + i*cos(B)*cos(C) -j*cos(B)*sin(C);
}

float calculateY(float i, float j, float k){
    return i*(cos(A)*sin(C) + cos(C)*sin(A)*sin(B)) 
    + j*(cos(A)*cos(C) - sin(A)*sin(B)*sin(C)) - k*cos(B)*sin(A);
}

float calculateZ(float i, float j, float k){
    return i*(sin(A)*sin(C) - cos(A)*cos(C)*sin(B)) 
    + j*(cos(C)*sin(A) + cos(A)*sin(B)*sin(C)) + k*cos(A)*cos(B);
}

void calculatePoint(float i, float j, float k, float ascii_cube_code){
    int x = calculateX(i, j, k);
    int y = calculateY(i, j, k);
    int z = calculateZ(i, j, k) + distance;


    ooz = 1.0f/z;

    xp = (int)(width/2 + x * k1 * ooz * 2);
    yp = (int)(height/2 + y * k1 * ooz);

    idx = xp + yp * width;

    if(idx >= 0 && idx < width*height){
        if(ooz>zBuffer[idx]){
            zBuffer[idx] = ooz;
            Buffer[idx] = ascii_cube_code;
        }
    }
}

int main(int argc, char **argv){


    printf("\x1b[2J");

    while(1){
        memset(Buffer, ascii_background_code, height*width);
        memset(zBuffer, 0, height*width*4);

        
        for(float i = -cubeWidth/2; i < cubeWidth /2; i+=0.15){
            for(float j = -cubeWidth/2; j < cubeWidth /2; j+=0.15){
                calculatePoint(i, j, -cubeWidth/2, '#');
                calculatePoint(i, j, cubeWidth/2, '@');
                calculatePoint(i, cubeWidth/2, j, '!');
                calculatePoint(i, -cubeWidth/2, j, '&');
            }
        }

        printf("\x1b[H");

        for (int y = 0; y< height; y++){
            for(int x = 0; x<width; x++){
                putchar(Buffer[x+y*width]);
            }
            putchar('\n');
        }

        usleep(8000);
        A+=0.02;
        B+=0.02;
        C+=0.005;

    }    
    return 0;



}