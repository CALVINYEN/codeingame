#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    struct node {
        int x1, y1;
        int x2, y2;
        int x3, y3;
    };
   /* struct node_grid {
        int x, y;
    }
    struct node_grid node_grid_1[900] = [-1];*/
    struct node node_1;
    char grid[32][32] = {'.'};
    int width; // the number of cells on the X axis
    scanf("%d", &width);
    int height; // the number of cells on the Y axis
    scanf("%d", &height); fgetc(stdin);
    
    for (int i = 0; i < height; i++) {
        char line[32]; // width characters, each either 0 or .
        fgets(line, 32, stdin); // width characters, each either 0 or .
        for (int j = 0; j < width; j++)
        {
            grid[i][j] = line[j];
        }
    }
    
    /*for (int i = 0; i < height; i++)
    {
        int a = 0, b = 0;
        for (int j = 0; j < width; j++)
        {
            if(grid[i][j] == '0') node_grid_1[a++]{}
        }
    }*/
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (grid[i][j] == '0'){
                node_1.x1 = j, node_1.y1 = i;
                for (int a = j + 1;a <= width;a++)
                {
                    if (a == width)
                    {
                        node_1.x2 = -1, node_1.y2 = -1;
                        break;
                    }
                    if (grid[i][a] == '0') 
                    {
                        node_1.x2 = a, node_1.y2 = i;
                        break;
                    }
                    else node_1.x2 = -1, node_1.y2 = -1;
                }
                for (int a = i + 1;a <= height;a++)
                {
                    if (a == height)
                    {
                        node_1.x3 = -1, node_1.y3 = -1;
                        break;
                    }
                    if (grid[a][j] == '0') 
                    {
                        node_1.x3 = j, node_1.y3 = a;
                        break;
                    }
                    else node_1.x3 = -1, node_1.y3 = -1;
                }
                /*if (grid[i][j+1] == '0') node_1.x2 = j + 1, node_1.y2 = i;
                else node_1.x2 = -1, node_1.y2 = -1;
                if (grid[i+1][j] == '0') node_1.x3 = j, node_1.y3 = i+1;
                else node_1.x3 = -1, node_1.y3 = -1;*/
                printf("%d %d %d %d %d %d\n",node_1.x1, node_1.y1, node_1.x2, node_1.y2, node_1.x3, node_1.y3);
            }
        }
    }

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    //printf("0 0 1 0 0 1\n");

    return 0;
}