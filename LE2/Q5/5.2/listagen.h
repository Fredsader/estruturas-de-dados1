#ifndef LISTAGEN_H
#define LISTAGEN_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	void* dataPtr;
	struct node* link;
}NODE;

typedef struct lista{
	int count;
	NODE* pos;
	NODE* head;
	NODE* rear;
	int (*compare) (void* argu1, void* argu2);
}LIST;

LIST* createList (int (*compare)(void* argu1, void* argu2));
LIST* destroyList (LIST* pList);
int addNode (LIST* pList, void* dataInPtr);
bool removeNode (LIST* pList, void* keyPtr,void** dataOutPtr);
bool searchList (LIST* pList, void* pArgu, void** pDataOut);
bool retrieveNode (LIST* pList,void* pArgu,void** dataOutPtr);
bool traverse (LIST* pList,int fromWhere,void** dataOutPtr);
int listCount (LIST* pList);
bool emptyList (LIST* pList);
bool fullList (LIST* pList);

static bool _insert (LIST* pList, NODE* pPre, void* dataInPtr);

static void _delete (LIST* pList,NODE* pPre,NODE* pLoc, void** dataOutPtr);

static bool _search (LIST* pList,NODE** pPre,NODE** pLoc,void* pArgu);

#endif
