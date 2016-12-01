#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
char *dectobin(int dec, char bin[], int binnum)
{
    for (int i = binnum - 1; i >= 0; i--) {
        if ((dec & 0x01) == 1)
            bin[i] = '1';
        else
            bin[i] = '0';
        dec >>= 1;
    }
    bin[binnum] = '\0';
    //printf("%s", bin);
}

void print0(char bin[])
{
    for (int i = 0; bin[i] != '\0';) {
        if (bin[i] == '0') {
            printf("00 ");
            for (; bin[i] == '0' && i >= 0;) {
                printf("0");
                i++;
            }
        }    
        else if (bin[i] == '1'){
            printf("0 ");
            for (; bin[i] == '1' && i >= 0;) {
                printf("0");
                i++;
            }
        }
        if (bin[i] != '\0' )
            printf(" ");
    }
    
}
 
int main()
{
    int decimal;
    char binary[2048];
    binary[0] = '\0';
    char bintmp[8];
    char MESSAGE[101];
    fgets(MESSAGE, 101, stdin); 
    int j = 0;
    while(MESSAGE[j+1] != '\0') {
        decimal = (int)MESSAGE[j];
        dectobin(decimal, bintmp, 7);
        strcat(binary, bintmp);
        //printf("%s",binary);
        j++;
     }
     //printf("%s",binary);
     print0(binary);
   // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    //printf("answer\n");

    return 0;
}