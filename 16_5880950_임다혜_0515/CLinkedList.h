#pragma once

typedef int elementType; // ��忡 ������ �����ʹ� ����

typedef struct ListNode {
    elementType data;
    struct ListNode* link;
} listNode;

typedef struct {
    int follow; // ������� �ʾƵ� ������ (��� �䱸 ����)
    listNode* Node_h;
    listNode* Node_tail;
} linkedList_h;

extern void insertFirstNode(linkedList_h* L, elementType item);
extern void insertLastNode(linkedList_h* L, elementType item);
extern void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item);
extern void printHeadTail(linkedList_h* L);
