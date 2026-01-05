#include <stdint.h>
#include "../kernel/util.h"

void clear_screen() {
for(int i = 0; i < (320*200); i++){
    putpixel(i, 0, 0x00);
}
}




void putpixel(int pos_x, int pos_y, unsigned char VGA_COLOR)
{
    unsigned char* location = (unsigned char*)0xA0000 + 320 * pos_y + pos_x;
    *location = VGA_COLOR;
}


void BlackBlock(int x, int y)
{
    x = x*10;
    y = y*10;
    int sqaure_size = 10;

     for (int i = x; i < x + sqaure_size; i++) {
        for (int j = y; j < y + sqaure_size; j++) {
            putpixel(i, j, 0x00);
        }
     }
    
}

void Grayblock(int x , int y)
    {
    x = x*10;
    y = y*10;
    int sqaure_size = 10;
    
    
    for (int i = x; i < x + sqaure_size; i++) {
        for (int j = y; j < y + sqaure_size; j++) {
            //light sides
            if(i - x == 0){
                putpixel(i, j, 0x1c);
            }
            else if(j - y == 0){
                putpixel(i, j, 0x1c);
            }
            //dark sides
            else if(i - x == 9){
                putpixel(i, j, 8);
            }
            else if(j - y == 9){
                putpixel(i, j, 8);
            }
            //fill
            else{
                putpixel(i, j, 7);
            }
            
        }
    }
    }



        void Pinkblock(int x , int y)
    {
    x = x*10;
    y = y*10;
    int sqaure_size = 10;
    
    for (int i = x; i < x + sqaure_size; i++) {
        for (int j = y; j < y + sqaure_size; j++) {
            //light sides
            if(i - x == 0){
                putpixel(i, j, 0x3d);
            }
            else if(j - y == 0){
                putpixel(i, j, 0x3d);
            }
            //dark sides
            else if(i - x == 9){
                putpixel(i, j, 5);
            }
            else if(j - y == 9){
                putpixel(i, j, 5);
            }
            //fill
            else{
                putpixel(i, j, 13);
            }
            
        }
    }

}


void Yellowblock(int x , int y)
    {
    x = x*10;
    y = y*10;
    int sqaure_size = 10;
    
    for (int i = x; i < x + sqaure_size; i++) {
        for (int j = y; j < y + sqaure_size; j++) {
            //light sides
            if(i - x == 0){
                putpixel(i, j, 0x5c);
            }
            else if(j - y == 0){
                putpixel(i, j, 0x5c);
            }
            //dark sides
            else if(i - x == 9){
                putpixel(i, j, 0x2b);
            }
            else if(j - y == 9){
                putpixel(i, j, 0x2b);
            }
            //fill
            else{
                putpixel(i, j, 14);
            }
            
        }
    }

}


void Cyanblock(int x , int y)
    {
    x = x*10;
    y = y*10;
    int sqaure_size = 10;
    
    for (int i = x; i < x + sqaure_size; i++) {
        for (int j = y; j < y + sqaure_size; j++) {
            //light sides
            if(i - x == 0){
                putpixel(i, j, 0x64);
            }
            else if(j - y == 0){
                putpixel(i, j, 0x64);
            }
            //dark sides
            else if(i - x == 9){
                putpixel(i, j, 3);
            }
            else if(j - y == 9){
                putpixel(i, j, 3);
            }
            //fill
            else{
                putpixel(i, j, 11);
            }
            
        }
    }

}



void Blueblock(int x , int y)
    {
    x = x*10;
    y = y*10;
    int sqaure_size = 10;
    
    for (int i = x; i < x + sqaure_size; i++) {
        for (int j = y; j < y + sqaure_size; j++) {
            //light sides
            if(i - x == 0){
                putpixel(i, j, 0x36);
            }
            else if(j - y == 0){
                putpixel(i, j, 0x36);
            }
            //dark sides
            else if(i - x == 9){
                putpixel(i, j, 1);
            }
            else if(j - y == 9){
                putpixel(i, j, 1);
            }
            //fill
            else{
                putpixel(i, j, 9);
            }
            
        }
    }

}


void Orangeblock(int x , int y)
    {
    x = x*10;
    y = y*10;
    int sqaure_size = 10;
    
    for (int i = x; i < x + sqaure_size; i++) {
        for (int j = y; j < y + sqaure_size; j++) {
            //light sides
            if(i - x == 0){
                putpixel(i, j, 0x2b);
            }
            else if(j - y == 0){
                putpixel(i, j, 0x2b);
            }
            //dark sides
            else if(i - x == 9){
                putpixel(i, j, 6);
            }
            else if(j - y == 9){
                putpixel(i, j, 6);
            }
            //fill
            else{
                putpixel(i, j, 0x2a);
            }
            
        }
    }

}


void Greenblock(int x , int y)
    {
    x = x*10;
    y = y*10;
    int sqaure_size = 10;
    
    for (int i = x; i < x + sqaure_size; i++) {
        for (int j = y; j < y + sqaure_size; j++) {
            //light sides
            if(i - x == 0){
                putpixel(i, j, 0x31);
            }
            else if(j - y == 0){
                putpixel(i, j, 0x31);
            }
            //dark sides
            else if(i - x == 9){
                putpixel(i, j, 2);
            }
            else if(j - y == 9){
                putpixel(i, j, 2);
            }
            //fill
            else{
                putpixel(i, j, 10);
            }
            
        }
    }

}


void Redblock(int x , int y)
    {
    x = x*10;
    y = y*10;
    int sqaure_size = 10;
    
    for (int i = x; i < x + sqaure_size; i++) {
        for (int j = y; j < y + sqaure_size; j++) {
            //light sides
            if(i - x == 0){
                putpixel(i, j, 0x40);
            }
            else if(j - y == 0){
                putpixel(i, j, 0x40);
            }
            //dark sides
            else if(i - x == 9){
                putpixel(i, j, 4);
            }
            else if(j - y == 9){
                putpixel(i, j, 4);
            }
            //fill
            else{
                putpixel(i, j, 12);
            }
            
        }
    }

}

