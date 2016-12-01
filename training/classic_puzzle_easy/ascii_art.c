#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
void printAS(int which_w[], char *ROW, int L)
{
    char wordrow[1024] = "";
	for (int i = 0; which_w[i] != -1; i++) {
			
		for (int j = 0; j < L; j++) {
			wordrow[(i*L) + j] = ROW[(which_w[i] * L) + j];
		}
	}
	printf("%s\n", wordrow);
}
 
int main()
{
    int L;
    scanf("%d", &L);
    int H;
    scanf("%d", &H); fgetc(stdin);
    char T[257];
	int which_w[257];
	memset(which_w, -1, sizeof(which_w));
    fgets(T, 257, stdin);
	
    for (int i = 0; T[i + 1] != '\0'; i++) {
		if (T[i] <= 'Z' && T[i] >= 'A')
			which_w[i] = T[i] - 'A';
		else if (T[i] >= 'a' && T[i] <= 'z')
			which_w[i] = T[i] - 'a';
		else
			which_w[i] = 'Z' - 'A' + 1;
	}
    
    for (int i = 0; i < H; i++) {
        char ROW[1025];
        fgets(ROW, 1025, stdin);
		printAS(which_w, ROW, L);
	}

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    //printf("answer\n");

    return 0;
}