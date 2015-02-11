#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "course.h"
#include "student.h"

void get_choice(int *choice);
void display_info(Class* Classes, Students *students, int cour_count,
  int stud_count);

int main(int argc, char* argv[2])
{
  int cour_count, stud_count, stud_size;
  Class *classes = NULL;
  Students *students = NULL;

  read_courses(argv[1], &cour_count, &classes);
  read_students(argv[2], &students, &stud_size, &stud_count);
  display_info(classes, students, cour_count, stud_count);
  deallocate(classes, students, stud_count);
  return 0;
}//main

void get_choice(int *choice)
{
  do
  {
    printf("\nRSVP Menu\n0. Done.\n1. Find by CRN.\n2. Find by subject.\n"
      "3. Add course.\n4. Remove course.\nYour choice (0 - 4): ");
    scanf("%d", choice);
    if(*choice < 0 || *choice > 4)
    {
      printf("Your choice is outside the acceptable range."
      "  Please try again.\n");
    }//outside range
  }while(*choice < 0 || *choice > 4);
}//get_choice

void display_info(Class* classes, Students *students, int cour_count, 
  int stud_count)
{
  int choice;

  do
  {
    get_choice(&choice);
    switch(choice)
    {
      case 0: break;
      case 1:
	find_CRN(classes, students, cour_count, stud_count);
        break;
      case 2:
        find_subject(classes, cour_count);
        break; 
      case 3:
        add_course(classes, students, cour_count, stud_count);
        break;
      case 4:
	remove_course(classes, students, cour_count, stud_count);
	break;
    }//switch
  }while(choice != 0);
}//display_info
