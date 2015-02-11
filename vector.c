
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "course.h"
#include "student.h"

void initialize1(Class** classes, int* size)
{
  *classes = (Class*) malloc(100*sizeof(Class)); 
  *size = 100;
}//initialize1

void initialize2(Students** students, int* size)
{
  *students = (Students*) malloc(10*sizeof(Students));
  *size = 10;
}//initialize2

void resize1(Class **classes, int* size)
{
  int i;
  Class *temp_classes;
 
  temp_classes = (Class*) malloc(2*(*size)*sizeof(Class));

  for(i = 0; i < *size; i++)
  {
    temp_classes[i] = (*classes)[i];
  }//for i

  free(*classes);
  *classes = temp_classes;

  *size = (*size)*2;
}//resize1

void resize2(Students **students, int* size)
{
  int i;
  Students *student_temp;

  student_temp = (Students*) malloc(2*(*size)*sizeof(Students));

  for(i = 0; i < *size; i++)
    student_temp[i] = (*students)[i];

  free(*students);
  *students = student_temp;

  *size = (*size)*2;
}//resize

void deallocate(Class *classes, Students *students, int stud_count)
{
  int i;

  for(i = 0; i < stud_count; i++)
  {
    free(students[i].first);
    free(students[i].last);
  }//for i

  free(classes);
  free(students);
  
}//deallocate
