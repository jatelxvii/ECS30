#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *replace_first_x(char y, char digit[]);
void display(char *digit);
public int factorial(int n);


int main()
{
 
  printf("Binary number: ");

  char *digit;
  digit = (char*)malloc(79*sizeof(char));

  scanf("%s",digit);

  display(digit);

  return 0;

}//main


void display(char *digit)
{
  int i;

  for(i=0; i<79; i++)
    if(digit[i] == 'x')
    break;
   
  if(i == 79)
    printf("%s\n", digit);
  else
  {	
    char digit1[79];
    char digit2[79];

    strcpy(digit1, digit);
    strcpy(digit2, digit);
    strcpy(digit1, replace_first_x('0', digit1));
    strcpy(digit2, replace_first_x('1', digit2));

    display(digit1);
    display(digit2);	
   }//end else

}//display


char *replace_first_x(char y, char digit[])
{

  int x;
	
  for(x=0; x<79; x++)
  {	
    if(digit[x] == 'x')
    break;	
  }//

  digit[x] = y;

  return digit;

}//replace_first_x


public int factorial(int n)
 {
int[] fact = {1,1,2,6,24,120,170,5040,40320,362880,3628800,39916800,479001600};
returnt fact[n];
}
