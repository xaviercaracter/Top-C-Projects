The following is the README given to me by the instructor.
# Playlist
## Problem Description

*You will be building a linked list. Make sure to keep track of both the head and tail nodes.*

<br />
1. Implement the functions declared in the PlaylistNode.h in PlaylistNode.c 

- PlaylistNode.h - Struct definition and related function declarations
- PlaylistNode.c - Related function definitions
- main.c - main() function

The PlaylistNode struct as well as function declarations for the related functions described below have been provided in PlaylistNode.h.  Please do not modify the provided PlaylistNode.h file. Details regarding each function as well as expected return values are included in the comments associated with each function declaration in PlaylistNode.h.  The following is a summary of this content:  

Note: Some functions can initially be function stubs (empty functions), to be completed in later steps. 

- Private data members
   - char uniqueID[50] 
   - char songName[50] 
   - char artistName[50] 
   - int songLength 
   - PlaylistNode* nextNodePtr 
- Related functions
   - CreatePlaylistNode() 
   - InsertPlaylistNodeAfter() 
   - SetNextPlaylistNode() 
   - GetNextPlaylistNode()
   - PrintPlaylistNode()
   - DestroyPlaylistNode()

Ex. of PrintPlaylistNode output:
```
Unique ID: S123
Song Name: Peg
Artist Name: Steely Dan
Song Length (in seconds): 237
```

<br />
2. In main(), prompt the user for the title of the playlist. 
<br /><br />
Ex:

```
Enter playlist's title:
JAMZ 
```
<br />
3. Implement the PrintMenu() function. PrintMenu() takes the playlist title as a parameter and outputs a menu of options to manipulate the playlist. Each option is represented by a single character. Build and output the menu within the function.

If an invalid character is entered, continue to prompt for a valid choice. Hint: Implement Quit before implementing other options. Call PrintMenu() in the main() function. Continue to execute the menu until the user enters q to Quit. 
<br /><br />
Ex:
```
JAMZ PLAYLIST MENU
a - Add song
r - Remove song
c - Change position of song
s - Output songs by specific artist
t - Output total time of playlist (in seconds)
o - Output full playlist
q - Quit

Choose an option:
```
<br />
4. Implement "Output full playlist" menu option. If the list is empty, output: `Playlist is empty` 
<br /><br />
Ex:

```
JAMZ - OUTPUT FULL PLAYLIST
1.
Unique ID: SD123
Song Name: Peg
Artist Name: Steely Dan
Song Length (in seconds): 237

2.
Unique ID: JJ234
Song Name: All For You
Artist Name: Janet Jackson
Song Length (in seconds): 391

3.
Unique ID: J345
Song Name: Canned Heat
Artist Name: Jamiroquai
Song Length (in seconds): 330

4.
Unique ID: JJ456
Song Name: Black Eagle
Artist Name: Janet Jackson
Song Length (in seconds): 197

5. 
Unique ID: SD567
Song Name: I Got The News
Artist Name: Steely Dan
Song Length (in seconds): 306
```
<br />
5. Implement the "Add song" menu item. New additions are added to the end of the list. 
<br /><br />
Ex:

```
ADD SONG
Enter song's unique ID:
SD123
Enter song's name:
Peg
Enter artist's name:
Steely Dan
Enter song's length (in seconds):
237
```
<br />
6. Implement the "Remove song" function. Prompt the user for the unique ID of the song to be removed.
<br /><br />
Ex:

```
REMOVE SONG
Enter song's unique ID:
JJ234
"All For You" removed
```
<br />
7. Implement the "Change position of song"  menu option. Prompt the user for the current position of the song and the desired new position. Valid new positions are 1 - *n* (the number of nodes). If the user enters a new position that is less than 1, move the node to the position 1 (the head). If the user enters a new position greater than *n*, move the node to position *n* (the tail). 6 cases will be tested:

- Moving the head node 
- Moving the tail node 
- Moving a node to the head 
- Moving a node to the tail 
- Moving a node up the list 
- Moving a node down the list 
<br />

Ex:
```
CHANGE POSITION OF SONG
Enter song's current position:
3
Enter new position for song:
2
"Canned Heat" moved to position 2
```
<br />
8. Implement the "Output songs by specific artist" menu option. Prompt the user for the artist's name, and output the node's information, starting with the node's current position. 
<br /><br />

Ex:
```
OUTPUT SONGS BY SPECIFIC ARTIST
Enter artist's name:
Janet Jackson

2.
Unique ID: JJ234
Song Name: All For You
Artist Name: Janet Jackson
Song Length (in seconds): 391

4.
Unique ID: JJ456
Song Name: Black Eagle
Artist Name: Janet Jackson
Song Length (in seconds): 197
```
<br />
9. Implement the "Output total time of playlist" menu option. Output the sum of the time of the playlist's songs (in seconds). 
<br /><br />

Ex:
```
OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)
Total time: 1461 seconds
```

<br />
10. Run valgrind to check for memory leaks or errors
<br /><br />

```
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./myprog
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./mytests -t <test_num>
```


### Error Handling
The following describes the expected behavior when functions return errors unless the error is an expected behavior and part of the core application logic.  For example, GetNextPlaylistNode() returns NULL when it reaches the end of the list.
- if a call to CreatePlaylistNode() returns NULL, display the following message, display the menu and prompt for a selection
```
Error: Unable to create PlaylistNode
```
- if a call to InsertPlaylistNOdeAfter() returns -1, display the following message, display the menu and prompt for a selection
```
Error: Unable to insert PlaylistNode
```
- if a call to SetNextPlaylistNode() returns -1, display the following message, display the menu and prompt for a selection
```
Error: Unable to set next PlaylistNode
```
