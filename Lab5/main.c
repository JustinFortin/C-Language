/*
============================================================================
Name : main.c
Author : <<< Justin-Thomas Warkus-Fortin (wark0025)>>>
Version : Lab 5
Description : File I/O in C, Ansi-style
Status :
 Builds clean; no warning(s) : << true >>
 Requirement #1 - FileRead.txt in src/ : << complete >>
 Requirement #2 - Open FileRead.txt read (only) : << complete >>
 Requirement #3 - Open FileOut.txt write (only) : << complete >>
 Requirement #4 - Check file open for success : << complete  >>
 Requirement #5 - Process FileRead.txt word-by-word: << complete >>
 Requirement #6 - Display total words and chars : << complete  >>
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FILE *readFile, *writeFile;
	int wordCount = 0;
	int charCount = 0;

	readFile = fopen("FileRead.txt", "r");
	writeFile = fopen("FileOut.txt", "w");

	if (readFile == NULL || writeFile == NULL)
	{
		printf("The file could not be read");
		return -1;
	}
	else
	{
		char fileWords[30];
		while (fscanf(readFile, "%s", fileWords) == 1)
		{
			printf("The word I read from FileRead.txt -> %s\n", fileWords);
			fprintf(writeFile, "The word I read from FileRead.txt -> %s\n", fileWords);
			int i;
			for (i = 0; fileWords[i] != '\0'; i++)
			{
				charCount++;
			}
			wordCount++;
		}
	}
	fclose(readFile);
	fclose(writeFile);

	printf("\nTotal number of words in file: %d", wordCount);
	printf("\nTotal number of characters in file (sans white-space): %d", charCount);

	return 0;
}
