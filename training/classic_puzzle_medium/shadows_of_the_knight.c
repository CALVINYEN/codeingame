#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void diagonal_ul_dr(int *x0, int *y0, char *dir, int *up_basey, int *down_basey, int *left_basex, int *right_basex)
{
    if ((strcmp(dir, "UL")) == 0) {
        *right_basex = *x0, *down_basey = *y0;
        *x0 = *x0 - ((*x0 - *left_basex) >> 1);
        *y0 = *y0 - ((*y0 - *up_basey) >> 1);
        printf("%d %d\n", *x0, *y0);
    }
    else {
        *left_basex = *x0, *up_basey = *y0;
        *x0 = *x0 + ((*right_basex - *x0) >> 1);
        *y0 = *y0 + ((*down_basey - *y0) >> 1);
        printf("%d %d\n", *x0, *y0);
    }
}

void diagonal_ur_dl(int *x0, int *y0, char *dir, int *up_basey, int *down_basey, int *left_basex, int *right_basex)
{
    if ((strcmp(dir, "UR")) == 0) {
        *left_basex = *x0, *down_basey = *y0;
        *x0 = *x0 + ((*right_basex - *x0) >> 1);
        *y0 = *y0 - ((*y0 - *up_basey) >> 1);
        printf("%d %d\n", *x0, *y0);
    }
    else {
        *right_basex = *x0, *up_basey = *y0;
        *x0 = *x0 - ((*x0 - *left_basex) >> 1);
        *y0 = *y0 + ((*down_basey - *y0) >> 1);
        printf("%d %d\n", *x0, *y0);
    }
}

void up_down_serch(int *x0, int *y0, char *dir, int *up_basey, int *down_basey)
{
    if ((strcmp(dir, "U")) == 0) {
        *down_basey = *y0;
        *y0 = *y0 - ((*y0 - *up_basey)>> 1);
        printf("%d %d\n", *x0, *y0);
    }
    else {
        *up_basey = *y0;
        *y0 = *y0 + ((*down_basey - *y0)>> 1);
        printf("%d %d\n", *x0, *y0);
    }
}

void left_right_serch(int *x0, int *y0, char *dir, int *left_basex, int *right_basex)
{
    if ((strcmp(dir, "L")) == 0) {
        *right_basex = *x0;
        *x0 = *x0 - ((*x0 - *left_basex) >> 1);
        printf("%d %d\n", *x0, *y0);
    }
    else {
        *left_basex = *x0;
        *x0 = *x0 + ((*right_basex - *x0) >> 1);
        printf("%d %d\n", *x0, *y0);
    }
}



int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);
    int *x0 = &X0;
    int *y0 = &Y0;
	
    int up_basey = -1, down_basey = H, left_basex = -1, right_basex = W;
	
    int *upbasey = &up_basey;
    int *downbasey = &down_basey;
    int *leftbasex = &left_basex;
    int *rightbasex = &right_basex;
    
    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);
        if ((strcmp(bombDir, "UL")) == 0 || (strcmp(bombDir, "DR")) == 0)
            diagonal_ul_dr(x0, y0, bombDir, upbasey, downbasey, leftbasex, rightbasex);
        else if ((strcmp(bombDir, "UR")) == 0 || (strcmp(bombDir, "DL")) == 0)
            diagonal_ur_dl(x0, y0, bombDir, upbasey, downbasey, leftbasex, rightbasex);
        else if ((strcmp(bombDir, "U")) == 0 || (strcmp(bombDir, "D")) == 0)
            up_down_serch(x0, y0, bombDir, upbasey, downbasey);
        else {
            left_right_serch(x0, y0, bombDir, leftbasex, rightbasex);
        }
    }

    return 0;
}