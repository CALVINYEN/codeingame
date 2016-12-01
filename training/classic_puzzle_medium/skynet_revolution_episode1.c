#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int queue[512];
int net[512][512];
int gateway_node[512];
int head = 0, tail = 0;

void enqueue(int q)
{
    if (tail == 511)
        tail = 0;
	queue[tail++] = q;
}

int dequeue(void)
{
    if (head == 511)
        head = 0;
	return queue[head++];
}

int is_empty(void)
{
	return head == tail;
}

int search(int N)
{
    int si;
    si = dequeue();
	for (int i = 0; i < N; i++){
	        //printf("%d,%d.", i, si);
		    if (net[si][i] == 1|| net[i][si] == 1) {
		       //printf("(%d)", i);
		        if (gateway_node[i] == 1) {
				    printf("%d %d\n", si, i);
				    head = 0, tail = 0;
				    return 0;
			    }
			    else {
	    		    enqueue(i);
	    		    //printf("%d.", head);
	    		    continue;
			    }
		    
	    }
		
	}
	return 0;
}

int main()
{
    memset(queue, -1, sizeof(queue));
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    scanf("%d%d%d", &N, &L, &E);
	
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        scanf("%d%d", &N1, &N2);
		net[N1][N2] = 1;
		//printf("%d %d %d\n", N1, N2, net[N1][N2]);
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        scanf("%d", &EI);
		gateway_node[EI] = 1;
		//printf("%d\n", EI);
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        scanf("%d", &SI);
        //printf("%d\n", SI);
		enqueue(SI);
		//printf("%d\n", is_empty());
		while (!is_empty()) {
		    //printf("%d", dequeue());
			search(N);
		}
		//printf("exit\n");
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
    }

        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        

    return 0;
}