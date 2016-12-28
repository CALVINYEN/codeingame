#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n;
    int *value;
    int maxloss = 0;
	int maxpoit;
    scanf("%d", &n);
    value = (int *)malloc( (sizeof (int) * n));
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        *(value++) = v;
    }
    value -= n;
	maxpoit = value[0];
    for (int i = 0; i < n; i++) {
		if (value[i] >= maxpoit) {
			maxpoit = value[i];
			for (int j = (i + 1); j < n; j++) {
				int temp = (value[i] - value[j]);
				if (temp > maxloss) {
					maxloss = temp;
				}
			}
		}    
    }
    //printf("value[0] = %d\n", value[0]);

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n", (0 - maxloss));
    free(value);
    return 0;
}