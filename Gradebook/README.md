The following is the README given by the instructor presenting this project.
# Gradebook
## Problem Description
Gradebook is an adaptation of a CS121 project used to demonstrate processing CSV files as well as working with ArrayLists and is revisited when we discuss Arrays.  This version of the Gradebook application allows the user to specify a CSV file containing student grade data command-line.  The application will open the CSV, load the grades from the CSV file into a dynamically allocated array. The array will initially be allocated to hold a max of 8 student grades, but will grow as needed by doubling its size each time. Once the grade data has been loaded from the CSV file, the grades array will be sorted based upon score, then displayed in the console. 
<br />
1. Carefully study the provided Student header file (Student.h) and function definitions (Student.c)
<br /><br />
The Student struct as well as function declarations for the related functions described below have been provided in Student.h. Please do not modify the provided Student.h or Student.c files. Details regarding each function as well as expected return values are included in the comments associated with each function declaration in Student.h. The following is a summary of this content:

- Data members
  - char lastname[40];
  - char firstname[40];
  - int id;
  - int score;
- Related functions
  - Student * CreateStudent(const char lastname[], const char firstname[], int id, int score)  
  - int CompareStudents(const void * Student1PtrPtr, const void * Student2PtrPtr) 
  - void PrintStudent(Student * thisSG)
  - void DestroyStudent(Student * thisSG)


<br />
2. Process the command-line arguments passed into main(), validate the correct number of values are passed in, dynamically create a gradebook array to hold 8 Student pointers and finally, open the specified file.  Handle any errors that occur by displaying a helpful error message and then exit with a non-zero exit status. 
<br /><br />

Ex: Incorrect number of command-line arguments
```
./myprog 
Usage: ./myprog <gradebook.csv>
```

Ex: Missing CSV data file
```
./myprog grades.txt
fopen: No such file or directory
```

<br />
3. Iterate through each line in the specified input CSV file, extracting song fields from each line as shown in the CSVParser example, adding each Student to the gradebook. If the gradebook fills up before reaching the of the CSV file, grow the gradebook by doubling its size as shown in the SampleDataProcessing example. When the end of the CSV file is reached display a message specifying the number of Students that were successfully loaded.
<br /><br />

Ex: Run gradebook application on XL CSV dataset
```
./myprog gradebook-xl.csv 
Growing Array: 8 -> 16
Growing Array: 16 -> 32
Growing Array: 32 -> 64
Growing Array: 64 -> 128
Growing Array: 128 -> 256
Growing Array: 256 -> 512
Growing Array: 512 -> 1024
Successfully loaded 1000 Students!
```
<br />
4. Use qsort() and the CompareStudents() function to sort the gradebook array.  

For more details on how qsort() works, please review the [Week 9 Deeper Look](https://www.youtube.com/playlist?list=PLvnIObHoMl8dxXVqbIki-altY22BE2vTU) discussion of function pointers. The PointersAndFunctions example from [cs253-week9-examples](https://github.com/lhindman/cs253-week9-examples) may also be helpful.
<br /><br />


<br />
5. Iterate through the sorted gradebook and display each Student in the console using the PrintStudent() function. Verify that the Students are displayed in ascending order
<br /><br />

Ex: Show sorted gradebook using small CSV dataset
```
./myprog gradebook.csv
Successfully loaded 7 Students!
Stella Zinman (6326) has a F (21)
Barney Stinson (1) has a D- (63)
Gary Blauman (7123) has a C (76)
Lily Aldrin (1413) has a B- (82)
Marshall Eriksen (1423) has a B+ (87)
Robin Scherbatsky (3002) has a A- (91)
Ted Mosby (6003) has a A+ (103)
```

<br />
6. Release allocated memory. Iterate through the gradebook, freeing each Student by calling the DestroyStudent() function. Then free the gradebook.  Also make certain to close any files that were opened.
<br /><br />


Ex:
```
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./myprog  gradebook-xl.csv > /dev/null
==90009== Memcheck, a memory error detector
==90009== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==90009== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==90009== Command: ./myprog gradebook-xl.csv
==90009== 

<<<<<<<< PROGRAM OUTPUT REMOVED >>>>>>>>

==90009== 
==90009== HEAP SUMMARY:
==90009==     in use at exit: 0 bytes in 0 blocks
==90009==   total heap usage: 1,012 allocs, 1,012 frees, 120,984 bytes allocated
==90009== 
==90009== All heap blocks were freed -- no leaks are possible
==90009== 
==90009== For lists of detected and suppressed errors, rerun with: -s
==90009== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

