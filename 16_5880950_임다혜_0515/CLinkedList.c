#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void insertFirstNode(linkedList_h* L, elementType item) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;

    if (L->Node_h == NULL) {
        newNode->link = newNode;
        L->Node_h = newNode;
        L->Node_tail = newNode;
    }
    else {
        newNode->link = L->Node_h;
        L->Node_tail->link = newNode;
        L->Node_h = newNode;
    }
}

void insertLastNode(linkedList_h* L, elementType item) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;

    if (L->Node_h == NULL) {
        newNode->link = newNode;
        L->Node_h = newNode;
        L->Node_tail = newNode;
    }
    else {
        newNode->link = L->Node_h;
        L->Node_tail->link = newNode;
        L->Node_tail = newNode;
    }
}

void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item) {
    if (pre == NULL) return;

    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    newNode->link = pre->link;
    pre->link = newNode;

    if (pre == L->Node_tail) {
        L->Node_tail = newNode;
    }
}

void printHeadTail(linkedList_h* L) {
    if (L->Node_h == NULL) {
        printf("\n리스트가 비어있습니다.\n");
        return;
    }

    listNode* current = L->Node_h;
    printf("\nLinked List() : [");
    do {
        printf("%d", current->data);
        current = current->link;
        if (current != L->Node_h) printf(", ");
    } while (current != L->Node_h);
    printf("]\n");

    printf("Head : %d, Tail : %d\n", L->Node_h->data, L->Node_tail->data);
}
