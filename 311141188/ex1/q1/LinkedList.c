#include "LinkedList.h"
#include "ex1_q1.h"

int is_list_empty(struct LinkedList linkedList)
{
    return linkedList.head == NULL;
}

struct Node * create_node(struct polygon polygonOfNewNode)
{
    struct polygon * newPolygon = copy_polygon(polygonOfNewNode);
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->poly=newPolygon;
    newNode->next=NULL;
    return newNode;
}

void add_data_to_linked_list(struct LinkedList * linkedList, struct polygon polygonToAdd)
{
    struct Node * newNode = create_node(polygonToAdd);
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
}

struct LinkedList create_empty_linked_list()
{
    struct LinkedList linkedList;
    linkedList.head=NULL;
    linkedList.tail=NULL;
    return linkedList;
}

void free_list(struct LinkedList * linkedList)
{
    struct Node * currNode = linkedList->head;
    struct Node * nodeToDelete = currNode;
    while(currNode != NULL)
    {
        free_polygon_pointer(currNode->poly);
        nodeToDelete=currNode;
        currNode = currNode->next;
        free(nodeToDelete);
    }
}