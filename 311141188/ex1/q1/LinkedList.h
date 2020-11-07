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

int is_list_empty(struct LinkedList linkedList);
struct Node * create_node(struct polygon* polygonOfNewNode);
void add_data_to_linked_list(struct LinkedList * linkedList, struct polygon* polygonToAdd);
struct LinkedList create_empty_linked_list();
struct polygon * copy_polygon(struct polygon polygonOfNewNode);
void free_list(struct LinkedList * linkedList);
