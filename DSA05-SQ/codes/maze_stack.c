#include <stdio.h>
#include "stack.h"
// not complete

#define row 6
#define col 6

typedef struct _direction {
	short r;
	short c;
} pos;

pos here = {1, 0}, entry = {1, 0};

void push_pos(dstack *s, int r, int c) {
    if (r < 0 || c < 0) 
	    return ; // nowher to go
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		pos tmp;
	}
}

int main() {
	int i, j;
	char maze[row][col]; // 0 for open, 1 for wall
                        
	// read a maze file
	FILE *fd = fopen("maze_stack.txt", "r");

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			fscanf(fd, "%c", &maze[i][j]); // read from a file
		
	route(maze); // run maze solver

	fclose(fd);
	return 0;
}