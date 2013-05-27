/**
 * Created: thread_list.h
 * PROGRAMMING ASSIGNMENT 2
 * CMPS 111 Spring 2013
 * Authors: Andrew Bao, Konstantin Litovskiy, Tyler Esser & Nick Wood
 *
 * thread_list.h: Thread List
 * A linked list containing the number of lottery tickets,
 * as well as identifying information regarding the threads
 * being kept track of.
 */
#ifndef _LIST_H_INCLUDE
#define _LIST_H_INCLUDE

/* The list nodes */
struct ThreadListNode {
    void * data;
    struct ThreadListNode * next;
    
    /* Lottery information */
    int threadID;
    int tickets;
} ThreadListNode;

/* The list proper */
struct ThreadList{
    struct ThreadListNode * front;
    struct ThreadListNode * back;
    
    /* Lottery information */
    int numTickets;
    int numNodes;
} ThreadList;
 
/* Define struct references */
typedef struct ThreadList       * TLRef;
typedef struct ThreadListNode   * TNRef;

/* Constructors */
TLRef newThreadList(void);
void insertData(TLRef L, int id, void * data, int tickets);

/* Destructors */
void freeList(TLRef *pL);
void freeNode(TNRef *pN);

/* check for list emptiness */
int isListEmpty(TLRef L);

/* get number of tickets */
int getTickets(TLRef L);

/* get list size */
int getSize(TLRef L);

/* Get data out of the list */
void* getFront(TLRef L);
void* getID(TLRef L, int id);
int   getID_tickets(TLRef L, int id);
void* getIndex(TLRef L, int index);
TNRef getIndexNode(TLRef L, int index);

void removeID(TLRef L, int id);

/**
 * I'm using this method to seperate making the list empty from 
 * freeing it.
 */
void clearList(TLRef L);

/* Look at the contents */
void printList(TLRef L);

#endif