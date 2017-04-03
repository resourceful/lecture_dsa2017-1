#include <stdio.h>

#define row 5
#define col 5

void route(int maze[row][col]);

int main(){
	int i, j;
	int maze[row][col]; // 0 for open, 1 for wall
                        // maze opens at [0][0]

	// read a maze file
	FILE *fd = fopen("maze.txt", "r");

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			fscanf(fd, "%d", &maze[i][j]); // read from a file
		
	route(maze); // run maze solver

	fclose(fd);
	return 0;
}

void route(int maze[row][col]){
	int i = 0,  j = 0; // i for row, j for col

	/* advance horizontally first when possible
       otherwise move vertically downwards
    */
	while (i < row){
		if ((maze[i][j] == 0) && (j < col))
			printf("%d, %d\n", i, j++); // go horizontally
		 else{
			--j, i++; // back a position and move down
		}
	}
}