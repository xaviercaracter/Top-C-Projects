/**
 * Author: Xavier Caracter
 * Date: Sun 24 Oct 2021 10:44:09 PM MDT
 * Description: The driver class for my Playlist object
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "PlaylistNode.h"



void NewLineTrim(char *line);
void BufferPurge(void);

void PrintMenu(char playListTitle[])
{
    char menuOption;
    char uniqueID[50];
    char songName[50];
    char artistName[50];
    int songLength = 0;
    int rc;
    int rc1;
    int rc2;
    int rc3;
    int rc4;
    bool foundNode = false;
    int currentPos = 0;
    int newPos = 0;
    int listSpot = 1;
    PlaylistNode *headNode = NULL;
    PlaylistNode *tailNode = NULL;
    PlaylistNode *currentNode = NULL;
    PlaylistNode *previousNode = NULL;
    PlaylistNode *oldBeforeNode = NULL;
    PlaylistNode *targetNode = NULL;
    PlaylistNode *oldAfterNode = NULL;
    PlaylistNode *newBeforeNode = NULL;
    PlaylistNode *newAfterNode = NULL;
    PlaylistNode *newTargetNode = NULL;

    do
    {
        printf("MENU\n");
        printf("a - Add song\n");
        printf("r - Remove song\n");
        printf("c - Change position of song\n");
        printf("s - Output songs by specific artist\n");
        printf("t - Output total time of playlist (in seconds)\n");
        printf("o - Output full playlist\n");
        printf("q - Quit\n");

        printf("\nChoose an option: ");
        scanf(" %c", &menuOption);
        switch (menuOption)
        {

        case 'a':
            BufferPurge();
            printf("ADD SONG\n");
            printf("Enter song's unique ID:\n");
            fgets(uniqueID, 50, stdin);
            NewLineTrim(uniqueID);

            printf("Enter song's name:\n");
            fgets(songName, 50, stdin);
            NewLineTrim(songName);

            printf("Enter Artist's name:\n");
            fgets(artistName, 50, stdin);
            NewLineTrim(artistName);

            printf("Enter song's length (in seconds):\n");
            scanf("%d", &songLength);
            BufferPurge();

            printf("You entered: %s, %s, %s, %d\n", uniqueID, songName, artistName, songLength);

            currentNode = CreatePlaylistNode(uniqueID, songName, artistName, songLength);
            if (currentNode == NULL)
            {
                printf("Error: Unable to create PLaylitNode\n");
                exit(1);
            }

            if (headNode == NULL)
            {
                headNode = currentNode;
                tailNode = currentNode;
            }
            else
            {
                rc = InsertPlaylistNodeAfter(tailNode, currentNode);

                if (rc < 0)
                {
                    printf("Error: unable to insert PLaylitNode...\n");
                    PrintPlaylistNode(currentNode);
                    exit(1);
                }
                tailNode = currentNode;
                break;
            case 'r':
                BufferPurge();
                printf("\nREMOVE SONG\n");
                printf("Enter song's unique ID:\n");
                fgets(uniqueID, 50, stdin);
                NewLineTrim(uniqueID);
                currentNode = headNode;
                previousNode = NULL;
                if (strcmp(currentNode->uniqueID, uniqueID) == 0 && (currentNode = headNode))
                {
                    foundNode = true;
                    headNode = GetNextPlaylistNode(currentNode);
                    headNode->nextNodePtr = GetNextPlaylistNode(currentNode)->nextNodePtr;
                    printf("%s removed\n", currentNode->songName);
                    free(currentNode);
                }
                else
                {
                    previousNode = currentNode;
                    currentNode = GetNextPlaylistNode(currentNode);
                    while ((foundNode == false) && currentNode != NULL)
                    {
                        if (strcmp(currentNode->uniqueID, uniqueID) == 0)
                        {
                            foundNode = true;
                            previousNode->nextNodePtr = currentNode->nextNodePtr;
                            printf("%s removed\n", currentNode->songName);
                            free(currentNode);
                        }
                        else
                        {
                            previousNode = currentNode;
                            currentNode = GetNextPlaylistNode(currentNode);
                        }
                    }
                }

                foundNode = false;
                break;
            case 'c':
                printf("\nCHANGE POSITION OF SONG\n");
                printf("Enter song's current poition:\n");
                scanf("%d", &currentPos);
                BufferPurge();
                printf("Enter new position for song:\n");
                scanf("%d", &newPos);
                BufferPurge();

                previousNode = headNode;
                currentNode = headNode;

                
                while (currentNode != NULL)
                {

                    if (listSpot == currentPos)
                    {
                        oldBeforeNode = previousNode;
                        targetNode = currentNode;
                        oldAfterNode = GetNextPlaylistNode(currentNode);
                    }

                    if((currentPos > newPos) && (listSpot == newPos-1)){
                        newBeforeNode = currentNode;
                        newAfterNode = GetNextPlaylistNode(currentNode);
                    }

                    if((currentPos < newPos) && (listSpot == newPos)){
                        newBeforeNode = previousNode;
                        if(currentNode != NULL){
                            newTargetNode = currentNode;
                            newAfterNode = GetNextPlaylistNode(currentNode);
                        }
                    }

                    previousNode = currentNode;
                    currentNode = GetNextPlaylistNode(currentNode);
                    listSpot++;
                }
                rc1 = SetNextPlaylistNode(targetNode, newAfterNode);
                rc2 = SetNextPlaylistNode(newBeforeNode, targetNode);
                rc3 = SetNextPlaylistNode(oldBeforeNode, newTargetNode);
                rc4 = SetNextPlaylistNode(newTargetNode, oldAfterNode);
                if(rc1 < 0 || rc2 < 0 || rc3 < 0 || rc4 < 0){
                    printf("Error: unable to set PlaylistNode");
                    exit(1);
                }
                
                printf("\"%s\" moved to position %d\n", targetNode->songName, newPos);
                break;
            case 's':
                BufferPurge();
                printf("\nOUTPUT SONGS BY SPECIFIC ARTIST\n");
                printf("Enter artist's name:\n");
                fgets(artistName, 50, stdin);
                NewLineTrim(artistName);
                printf("\n");
                int count = 1;
                currentNode = headNode;
                while (currentNode != NULL)
                {
                    if (strcmp(artistName, currentNode->artistName) == 0)
                    {
                        printf("%d.\n", count);
                        PrintPlaylistNode(currentNode);
                        printf("\n");
                    }
                    currentNode = GetNextPlaylistNode(currentNode);
                    count++;
                }
                break;

            case 't':
                printf("\nOUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n");
                int sum = 0;
                currentNode = headNode;
                while (currentNode != NULL)
                {
                    sum += currentNode->songLength;
                    currentNode = GetNextPlaylistNode(currentNode);
                }
                printf("Total time: %d seconds\n\n", sum);
                break;

            case 'o':
                printf("\n%s - OUTPUT FULL PLAYLIST\n", playListTitle);
                if (headNode->nextNodePtr == NULL)
                {
                    printf("Error: Playlist is empty");
                    break;
                }
                else
                {
                    currentNode = headNode;
                    int count = 1;
                    while (currentNode != NULL)
                    {
                        printf("%d.\n", count);
                        PrintPlaylistNode(currentNode);
                        currentNode = GetNextPlaylistNode(currentNode);
                        printf("\n");
                        count++;
                    }
                }

                break;
            case 'q':
                /* Quits the program and says goodbye */
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nError: Unknown option selected\n");
                break;
            }
        }
    } while (menuOption != 'q');
}

int main(void)
{
    char playListTitle[50] = "";

    printf("Enter playlist's title:\n");
    scanf("%50[^\n]", playListTitle);
    BufferPurge();

    PrintMenu(playListTitle);
    return 0;
}

void BufferPurge(void)
{
    char c = getchar();
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void NewLineTrim(char *line)
{
    size_t lineLength;

    if (line == NULL)
    {
        return;
    }
    lineLength = strlen(line);
    if (line[lineLength - 1] == '\n')
    {
        line[lineLength - 1] = '\0';
    }
}