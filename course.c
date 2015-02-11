#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "course.h"
#include <ctype.h>

void read_courses(char* filename, int* count, Class **classes)
{
  FILE* fp = fopen(filename, "r");
  char line[1000];
  int i, num, size, check;
  
  initialize1(classes, &size);  
  *count = 0;
  if(fp == NULL)
  {
    printf("File cannot be opened.\n");
    exit(1);
  }//null file
 
  while(fgets(line, 1000, fp) != NULL)
  {
    for(i = 0; i < 5; i++)
    {
      if(isdigit(line[i])) 
	check = 1;
      else//notdigits
      {
	check = 0;
        break;
      }//not 5 digits
    }//checking crn lines

    if(check)
    {
      if(*count == size)
	resize1(classes, &size);

      num = atoi(strtok(line, "\t"));
      (*classes)[*count].crn1 = num;

      strcpy((*classes)[*count].subject1, strtok(NULL, "\t"));
      if((*classes)[*count].subject1[0] == '^')
	strcpy((*classes)[*count].subject1, strtok(NULL, "\t"));
   
      strcpy((*classes)[*count].course1, strtok(NULL, "\t"));
   
      (*count)++;
      
    }//parsing
  }//while

}//read_courses

void find_CRN(Class* classes, Students *students, int cour_count,
  int stud_count)
{
  int CRN, i, j, k;

  printf("Please enter a CRN: ");
  scanf("%d", &CRN);

  for(i = 0; i < cour_count; i++)
  {
    if(classes[i].crn1 == CRN)
    { 
      printf("%s %s\n", classes[i].subject1, classes[i].course1);
      for(j = 0; j < stud_count; j++)
      {
        for(k = 0; k < students[j].count; k++)
	{
	  if(students[j].CRNs[k] == CRN)  
            printf("%s %s\n", students[j].first, students[j].last);
 	}//for k
      }//for j
      break;
    }
  }

  if(i == cour_count)
    printf("CRN %d not found.\n", CRN); 
}//get_crn

void find_subject(Class *classes, int count)
{
  char word[3];
  int i, check = 0, dummy = 2;

  printf("Please enter a subject: ");
  do
  {
    scanf("%s", word);
  }while(strlen(word) == 0); 
  for(i = 0; i < count; i++)
  {
    if(strcmp(word, classes[i].subject1) == 0)
    {
      printf("%d %s %s\n", classes[i].crn1, classes[i].subject1,
        classes[i].course1);
      check = 2;
    }//same subjects
  }//for i

  if(check == 0 && dummy == 0)
    printf("No courses were found for %s.\n", word);
}//get_subject

void add_course(Class *classes, Students *students, int cour_count,
  int stud_count)
{
  int i, place, CRN;

  printf("Add Course\n");
  place = find_student(students, stud_count);

  if(place == -1)
    return;

  if(students[place].count == 5)
  {
    printf("You are already taking 5 courses.\n");
    return;
  }//5 courses

  printf("Please enter the CRN: ");
  scanf("%d", &CRN);

  for(i = 0; i < cour_count; i++)
  {
    if(classes[i].crn1 == CRN)
      break;
  }//for i

  if(i == cour_count)
  {
    printf("There is no course with CRN #%d\n", CRN);
    return;
  }//not found

  for(i = 0; i < students[place].count; i++)
  {
    if(students[place].CRNs[i] == CRN)
    {
      printf("You are already taking that course.\n");
      return;
    }//has course
  }//for i

  students[place].CRNs[i] = CRN;
  students[place].count++;
}//add_course

void remove_course(Class* classes, Students *students, int cour_count,
  int stud_count)
{
  int place, i, CRN;

  printf("Remove Course\n");
  
  place = find_student(students, stud_count);

  if(place == -1)
    return;

  printf("Current courses: ");

  for(i = 0; i < students[place].count; i++)
    printf("%d ", students[place].CRNs[i]);

  printf("\nPlease enter the CRN: ");
  scanf("%d", &CRN);

  for(i = 0; i < students[place].count; i++)
  {
    if(students[place].CRNs[i] == CRN)
    {
      students[place].CRNs[i] = students[place].CRNs[--students[place].count];
      return;
    }//found crn
  }//for i

  printf("You are not taking that course.\n");
}//remove_course
