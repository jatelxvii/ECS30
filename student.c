#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include "vector.h"

void read_students(char* filename, Students **students, int* size, int* count)
{
  FILE* fp = fopen(filename, "r");
  char line[1000], *token;

  if(fp == NULL)
  {
    printf("Cannot read file %s.\n", filename);
    exit(1);
  }//cannot open file

  initialize2(students, size);
  *count = 0;

  while(fgets(line, 1000, fp))
  {
    if(*count == *size)
      resize2(students, size);

    token = strtok(line, ",");
    (*students)[*count].first = (char*) malloc(strlen(token)+1);
    strcpy((*students)[*count].first, token);
    token = strtok(NULL, ",");
    (*students)[*count].last = (char*) malloc(strlen(token)+1);
    strcpy((*students)[*count].last, token);
    strcpy((*students)[*count].SID, strtok(NULL, ",\n"));

    (*students)[*count].count = 0;

    while((token = strtok(NULL, ",\n")))
      (*students)[*count].CRNs[(*students)[*count].count++] = atoi(token);

    (*count)++;
  }//parsing
  
  
}//read_students

int find_student(Students *students, int count)
{
  int i;
  char SID[15];

  printf("Please enter the SID of the student: ");
  scanf("%s", SID);

  for(i = 0; i < count; i++)
  {
    if(strcmp(SID, students[i].SID) == 0)
      return i;
  }//for i

  printf("A student with SID #%s was not found.\n", SID);
  return -1;
}//find_student

