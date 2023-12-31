// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
}

void list_free(list_t *l) {
  struct Node* current = l->head;
    while (current != NULL) {
        struct Node* next = current->next;
        freeNode(current); 
        current = next;
    }
    l->head = NULL;
}

void list_print(list_t *l) {
  struct Node* current = l->head;
      if (current == NULL) {
          printf("The list is empty.\n");
          return;
      }

      printf("Linked List Elements: ");

      while (current != NULL) {
          printf("%d ", current->data);
          current = current->next;
      }
      
      printf("\n");
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) { return -1; }

void list_add_to_back(list_t *l, elem value) {
  struct Node* newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }

    if (l->head == NULL) {
        l->head = newNode;
    } else {
        struct Node* current = l->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void list_add_to_front(list_t *l, elem value) {
     node_t* cur_node = (node_t *) malloc(sizeof(node_t));
     cur_node->value = value;
     cur_node->next = NULL;

     /* Insert to front */

     node_t* head = l->head;  // get head of list

     cur_node->next = head;
     head = cur_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
  list_t *newNode = (list_t*)malloc(sizeof(list_t));
    newNode->data = value;

    if (index == 0 || l == NULL) {
        newNode->next = l;
        l = newNode;
        return;
    }

    list_t *current = l;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }

    if (current == NULL) {
        free(newNode); 
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

elem list_remove_from_back(list_t *l) {
  if (*l == NULL) {
        return -1;
    }

    int removedValue;
    list_t *current = *l;
    list_t *previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    removedValue = current->data;

    if (previous == NULL) {
        *l = NULL;
    } else {
        previous->next = NULL;
    }

    free(current);

    return removedValue;
}

elem list_remove_from_front(list_t *l) {
  if (*l == NULL) {
        return -1;
    }

    int removedValue;
    list_t *temp = *l;

    removedValue = temp->data;

    *l = temp->next;

    free(temp);

    return removedValue;
}

elem list_remove_at_index(list_t *l, int index) {
  if (*l == NULL || index < 0) {
        return -1;
    }

    int removedValue;
    list_t *current = *l;
    list_t *previous = NULL;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    if (current == NULL) {
        return -1;
    }

    removedValue = current->data;

    if (previous != NULL) {
        previous->next = current->next;
    } else {
        *l = current->next;
    }

    free(current);

    return removedValue;
} 

bool list_is_in(list_t *l, elem value) {
  list_t *current = l;

    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }

    return false;
}

elem list_get_elem_at(list_t *l, int index) {
  list_t *current = l;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (current == NULL) {
        return -1;
    }

    return current->data;
}

int list_get_index_of(list_t *l, elem value) {
  list_t *current = l;
    int currentIndex = 0;

    while (current != NULL) {
        if (current->data == value) {
            return currentIndex;
        }
        current = current->next;
        currentIndex++;
    }

    return -1;
}

