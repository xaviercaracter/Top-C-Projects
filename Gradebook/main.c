/**
 * Author: Xavier Caracter
 * Date: Sun 07 Nov 2021 10:14:24 PM MST
 * Description: The driver class for my gradebook application
 * */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "Student.h"

/**
 * growArray:  Doubles the size of the student array passed into it
 *             and returns the newly created array
 * array - Pointer to array of student objects that will have it size doubled
 * currentSize - the student array's current size
 * newSize - the new doubled size of the array
 * returns a new array of students with double the previous capacity
 */
Student **growArray(Student **array, int currentSize, int newSize)
{
   if (array == NULL)
   {
      return NULL;
   }

   if (newSize <= currentSize)
   {
      return NULL;
   }

   Student **newArray = (Student **)malloc(sizeof(Student) * newSize);
   if (newArray == NULL)
   {
      return NULL;
   }

   for (int i = 0; i < currentSize; i++)
   {
      newArray[i] = array[i];
   }

   free(array);

   fprintf(stdout, "Growing Array: %d -> %d\n", currentSize, newSize);

   return newArray;
}

int main(int argc, char *argv[])
{

   /* Arguments checking */
   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <gradebook.csv>\n", argv[0]);
      exit(1);
   }

   char *userFilename = argv[1];

   /* Open and validate file */
   errno = 0;
   FILE *dataFile = fopen(userFilename, "r");
   if (dataFile == NULL)
   {
      perror("fopen");
      exit(1);
   }

   const size_t STARTING_ARRAY_SIZE = 8;
   int startigArrayCapacity = STARTING_ARRAY_SIZE;
   Student **studentList = (Student **)malloc(sizeof(Student *) * STARTING_ARRAY_SIZE);
   if (studentList == NULL)
   {
      fprintf(stderr, "Error: Unable to allocate memory for song list\n");
      exit(1);
   }

   /* Temporary variables for holding CSV fields */
   const int MAX_FILED_SIZE = 256;
   char lastname[MAX_FILED_SIZE];
   char firstname[MAX_FILED_SIZE];
   int studentID;
   int score;

   int studentCount = 0;
   int numRead = 0;
   while (!feof(dataFile))
   {
      numRead = fscanf(dataFile, "%255[^,], %255[^,], %d, %d\n", lastname, firstname, &studentID, &score);
      if (numRead == 4)
      {
         if (studentCount >= startigArrayCapacity)
         {
            studentList = growArray(studentList, startigArrayCapacity, startigArrayCapacity * 2);
            if (studentList == NULL)
            {
               fprintf(stderr, "Error: An error occured while growing the array");
               exit(1);
            }
            startigArrayCapacity *= 2;
         }
         studentList[studentCount++] = CreateStudent(lastname, firstname, studentID, score);
      }
      else
      {
         fprintf(stderr, "Error: read %d of 4 when processing CSV!\n", numRead);
      }
   }
   /* Clean up */
   fclose(dataFile);
   fprintf(stdout, "Successfully loaded %d students!\n", studentCount);

   qsort(studentList, studentCount, sizeof(Student *), CompareStudents);

   /* Display student list */
   for (int i = 0; i < studentCount; i++)
   {
      PrintStudent(studentList[i]);
   }

   /*  Clean Up student list */
   for (int i = 0; i < studentCount; i++)
   {
      DestroyStudent(studentList[i]);
   }
   free(studentList);

   return 0;
}