#include<stdio.h>
#include<string.h>
#include<unistd.h>

typedef struct
{
    /* data */
    float x, y, z ;
}vec3;

const int cubeWidth = 40;
const int width = 180;
const int height = 44;
int distatce = 15;
float k1 = 10;
float zBuffer[width*height];
char Buffer[width*height];
int ascii_background_code = ' ';
int ascii_cube_code = '#';
float ooz;
int xp, yp, idx;


int main(int argc, char **argv){


    printf("\x1b[2J");

    while(1){
        memset(Buffer, ascii_background_code, height*width);
        memset(zBuffer, 0, height*width*4);

        
        for(float i = -cubeWidth/2; i < cubeWidth /2; i+=0.15){
            for(float j = -cubeWidth/2; j < cubeWidth /2; j+=0.15){

                vec3 p = {i, j, cubeWidth/2};
                
                ooz = 1/(p.z + distatce);

                xp = (int)(width/2 + p.x * k1 * ooz * 2);
                yp = (int)(height/2 + p.y * k1 * ooz);

                idx = xp + yp * width;
                
                if(idx >= 0 && idx < width*height){
                    if(ooz>zBuffer[idx]){
                        zBuffer[idx] = ooz;
                        Buffer[idx] = ascii_cube_code;
                    }
                }
            }
        }

        printf("\x1b[H");

        for (int y = 0; y< height; y++){
            for(int x = 0; x<width; x++){
                putchar(Buffer[x+y*width]);
            }
            putchar('\n');
        }

        if(k1 >= 20){
            k1 = 10;
        }

        k1+=0.2;

        usleep(8000);
    }    
    return 0;



}