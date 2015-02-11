#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_path(int i, int j, char maze[8][8]);


int main(int argc, char *argv[])
{

  FILE *fp;
  fp = fopen(argv[1], "r");

  char maze_arr[8][8];
  int a, b;
  int i = 7;
  int j = 7;

  for(a = 0; a < 8; a++)
  {
    for(b = 0; b < 8; b++)
      fscanf(fp, "%c", &maze_arr[a][b]);
      fgetc(fp);
  }//scan in array	

  if(find_path(i, j, maze_arr) == 0)
    printf("No path was found.\n");
   
  return 0;

}//main


int find_path(int i,int j, char maze[8][8])
{

  if(i < 0 || j < 0)
    return 0;
	
  if(maze[i][j] == 'X')  
    return 0; 
	
  if(i == 0 && j == 1)
  {	
    printf("(0, 1)\n");
    return 1;
  }//print 0,1 because all maze begin with this
  
	
  if( i > 7 || j > 7)
    return 0;


	
  maze[i][j]= 'X';
	
  if (find_path(i-1, j, maze) || find_path(i, j-1, maze) || find_path(i+1, j, maze) || find_path(i, j+1, maze))
  {	
    printf("(%d, %d)\n", i, j);
    return 1;
  }//find path around x and print coordinate

  return 0;
//find_path
}



