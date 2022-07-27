/*
============================================================================
Name : main.c
Author : Justin Warkus-Fortin (wark0025) >>>
Version : Lab 4
Description : structs in C, Ansi-style
Status :
Builds clean; no warning(s) : << true  >>
Requirement #1 - struct Student : <<  complete >>
Requirement #2 - struct Course : <<  complete >>
Requirement #3 - typedef Course struct : << complete >>
Requirement #4 - Prompt for number of students : << complete >>
Requirement #5 - Prompt for student information: << complete >>
Requirement #6 - Prompt for course information : << complete >>
Requirement #7 - Display registration : << complete >>
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char courseCode[8];
    char courseName[25];
} Course;
struct Student {
    char firstName[19];
    char lastName[19];
    int studentID;
    Course course;
};

int main(int argc, const char * argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    int numStudents;
    printf("Please enter the number of students you wish to enter: ");
    scanf("%d", &numStudents);

    struct Student student[numStudents];
    Course courses[numStudents];

    for(int i =0;i<numStudents;i++){
    	printf("\nPlease enter student #%d first name: ", i+1);
    	scanf("%s", student[i].firstName);
    	printf("Please enter student last name: ");
    	scanf("%s", student[i].lastName);
    	printf("Please enter student ID: ");
    	scanf("%d", &student[i].studentID);
    	while(student[i].studentID < 10000 || student[i].studentID > 99999){
    		printf("Error, ID must be 5 digits long.\nPlease enter student ID: ");
    		scanf("%d", &student[i].studentID);
    	}

    	printf("Please enter course code: ");
    	scanf("%s", courses[i].courseCode);
    	while(strlen(courses[i].courseCode) < 7 || strlen(courses[i].courseCode) > 7){
    	    printf("Error, course code must be 7 digits long.\nPlease enter course code: ");
    	    scanf("%s",  courses[i].courseCode);
    	}
    	printf("Please enter course name: ");
    	scanf("%s", courses[i].courseName);
    	student[i].course = courses[i];
    }

    for(int i=0;i<numStudents;i++){
    	printf("\nStudent name: %s %s", student[i].firstName, student[i].lastName);
    	printf("\nStudent ID: %d", student[i].studentID);
    	printf("\nCourse Code: %s", student[i].course.courseCode);
    	printf("\nCourse Name: %s", student[i].course.courseName);
    	printf("\n");
    }
}
