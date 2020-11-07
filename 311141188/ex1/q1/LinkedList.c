#include "LinkedList.h"
#include "ex1_q1.h"

int isListEmpty(struct LinkedList linkedList)
{
    return linkedList.head == NULL;
}


struct Node * createNode(struct polygon polygonOfNewNode)
{
    struct polygon * newPolygon = copyPolygon(polygonOfNewNode);
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->poly=newPolygon;
    newNode->next=NULL;
    return newNode;
}

void addDataToLinkedList(struct LinkedList * linkedList, struct polygon polygonToAdd)
{
    struct Node * newNode = createNode(polygonToAdd);
    if(linkedList->head == NULL && linkedList->tail == NULL)
    {
        linkedList->head = newNode;
        linkedList->tail = newNode;
    }
    else
    {
        linkedList->tail->next = newNode;
        linkedList->tail = newNode;
    }
    struct polygon * p1 = newNode->poly;
    /*for(int i=0; i<8;i++)
    {
        struct point * vertics = p1->vertices;
        struct point point1 = vertics[i];
    }*/
}

struct LinkedList createEmptyLinkedList()
{
    struct LinkedList linkedList;
    linkedList.head=NULL;
    linkedList.tail=NULL;
    //printf("A\n");
    return linkedList;
}