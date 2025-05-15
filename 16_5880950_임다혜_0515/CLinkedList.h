#pragma once

typedef int elementType; // 노드에 저장할 데이터는 정수

typedef struct ListNode {
    elementType data;
    struct ListNode* link;
} listNode;

typedef struct {
    int follow; // 사용하지 않아도 무방함 (기능 요구 없음)
    listNode* Node_h;
    listNode* Node_tail;
} linkedList_h;

extern void insertFirstNode(linkedList_h* L, elementType item);
extern void insertLastNode(linkedList_h* L, elementType item);
extern void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item);
extern void printHeadTail(linkedList_h* L);
