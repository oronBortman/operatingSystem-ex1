#pragma once

#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "ex1_q1.h"

struct Node {
    struct polygon* poly;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

int isListEmpty(struct LinkedList linkedList);
struct Node * createNode(struct polygon polygonOfNewNode);
void addDataToLinkedList(struct LinkedList * linkedList, struct polygon polygonToAdd);
struct LinkedList createEmptyLinkedList();
struct polygon * copyPolygon(struct polygon polygonOfNewNode);