#include <stdio.h>
#include <stdlib.h>

#define weightScreen 1000
#define lenghtScreen 1000



int brezenham(int** mass, int x1, int y1, int x2, int y2){
    int A = y2 - y1;
    int B = x1 - x2;
    
    int SignA = 0, SignB = 0;
    if(A < 0){
        SignA = -1;
    } else {
        SignA = 1;
    }
    if(B < 0){
        SignB = -1;
    } else {
        SignB = 1;
    }

    int f = 0, x = x1, y = y1;
    // otobrazit tochky
    mass[y][x] = 1;
    if (A * A < B * B){
        do {
            f = f + A * SignA;
            if (f > 0){
                f = f - B*SignB;
                y = y + SignA;
            }
            x = x - SignB;
            //ottbrazit tochky
            mass[y][x] = 1;
        } while(x != x2 || y != y2);
    } else {
        do {
            f = f + B * SignB;
            if (f > 0){
                f = f - A*SignA;
                x = x - SignB;
            }
            y = y + SignA;
            //ottbrazit tochky
            mass[y][x] = 1;
        } while(x != x2 || y != y2);
    }
    return 0;
}

void main(){
    int** arrScreen;
    arrScreen = (int**)malloc(sizeof(int*) * lenghtScreen);
    for (int i = 0; i < lenghtScreen; i++){
        arrScreen[i] = (int*)malloc(sizeof(int) * weightScreen);
    }

    for (int i = 0; i < lenghtScreen; i++){
        for (int j = 0; j < weightScreen; j++){
            arrScreen[i][j] = 0;
        }
    }

    int dotTriangleX1 = 40, dotTriangleY1 = 90;
    int dotTriangleX2 = 100, dotTriangleY2 = 500;
    int dotTriangleX3 = 600, dotTriangleY3 = 900;

    brezenham(arrScreen, dotTriangleX1,dotTriangleY1,dotTriangleX2,dotTriangleY2); 
    brezenham(arrScreen, dotTriangleX1,dotTriangleY1,dotTriangleX3,dotTriangleY3); 
    brezenham(arrScreen, dotTriangleX2,dotTriangleY2,dotTriangleX3,dotTriangleY3); 
    
    //draw(arrScreen,lenghtScreen, weightScreen);
    
    char fileName[] = "triangle.txt";
    FILE * ptrFile = fopen(fileName, "w");
    for (int i = 0; i < lenghtScreen; i++){
        for (int j = 0; j < weightScreen; j++){
            fprintf(ptrFile, "%d",arrScreen[i][j]);
        }
        fprintf(ptrFile, "\n");
    }
    fprintf(ptrFile, "\0");
    fclose(ptrFile);
}
