/* 
 * Author: Xavier Caracter
 * Date: Sun 24 Oct 2021 01:38:27 PM MDT
 * Description: Lab Warmup ContactNode.c file containing 
 * ContactNode object and interactive functions.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "PlaylistNode.h"

PlaylistNode* CreatePlaylistNode(char id[], char songName[], char artistName[], int songLength){
    PlaylistNode * nodeForPlaylist = (PlaylistNode *) malloc(sizeof(PlaylistNode));

   if(nodeForPlaylist == NULL){
      return NULL;
   }

   /* Validate Parameters*/
   if(id == NULL || songName == NULL || artistName == NULL || songLength < 0){
      return NULL;
   }

   strncpy(nodeForPlaylist->uniqueID, id, 50);
   strncpy(nodeForPlaylist->songName, songName, 50);
   strncpy(nodeForPlaylist->artistName, artistName, 50);
   nodeForPlaylist->songLength = songLength;
   nodeForPlaylist->nextNodePtr = NULL;

   return nodeForPlaylist;
}

int InsertPlaylistNodeAfter(PlaylistNode* nodeInList, PlaylistNode* newNode){
    PlaylistNode* tempNxt = NULL;

   if (nodeInList == NULL || newNode == NULL){
      return -1;
   }

   tempNxt = nodeInList->nextNodePtr;
   nodeInList->nextNodePtr = newNode;
   newNode->nextNodePtr = tempNxt;

   return 0;
}

int SetNextPlaylistNode(PlaylistNode* nodeInList, PlaylistNode* newNode){
    if (nodeInList == NULL || newNode == NULL){
      return -1;
    }

    nodeInList->nextNodePtr = newNode;
    
    return 0;
}

PlaylistNode* GetNextPlaylistNode(PlaylistNode* nodeInList){
    if(nodeInList == NULL){
      return NULL;
   }

   return nodeInList->nextNodePtr;

}

void PrintPlaylistNode(PlaylistNode* thisNode){
    if(thisNode==NULL){
      return;
   }

   printf("Unique ID: %s\n", thisNode->uniqueID);
   printf("Song Name: %s\n", thisNode->songName);
   printf("Artist Name: %s\n", thisNode->artistName);
   printf("Song Length: %d\n", thisNode->songLength);

   return;
}

void DestroyPlaylistNode(PlaylistNode* thisNode){
    if(thisNode == NULL){
      return;
   }

   free(thisNode);

}