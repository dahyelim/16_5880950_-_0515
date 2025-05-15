#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

int main() {
    linkedList_h list = { 0, NULL, NULL };
    int menu, value, target;
    listNode* current;

    do {
        printf("\n===== Linked_List Menu =====\n");
        printf("1) insertFirst (리스트의 제일 앞에 삽입)\n");
        printf("2) insertLast (리스트의 제일 뒤에 삽입)\n");
        printf("3) insertMiddle (특정 값 뒤에 삽입)\n");
        printf("4) print Head/Tail\n");
        printf("0) Program Stop\n");
        printf("Select menu : ");
        scanf_s("%d", &menu);

        switch (menu) {
        case 1:
            printf("\n삽입할 값 : ");
            scanf_s("%d", &value);
            insertFirstNode(&list, value);
            printHeadTail(&list);
            break;

        case 2:
            printf("\n삽입할 값 : ");
            scanf_s("%d", &value);
            insertLastNode(&list, value);
            printHeadTail(&list);
            break;

        case 3:
            if (list.Node_h == NULL) {
                printf("\n리스트가 비어있습니다.\n");
                break;
            }
            printf("\n어떤 값 뒤에? ");
            scanf_s("%d", &target);
            printf("삽입할 값 : ");
            scanf_s("%d", &value);
            current = list.Node_h;
            do {
                if (current->data == target) {
                    insertMiddleNode(&list, current, value);
                    break;
                }
                current = current->link;
            } while (current != list.Node_h);
            printHeadTail(&list);
            break;

        case 4:
            printHeadTail(&list);
            break;

        case 0:
            printf("\n프로그램을 종료합니다.\n");
            break;

        default:
            printf("\n잘못된 메뉴입니다. 다시 선택하세요.\n");
        }

    } while (menu != 0);

    return 0;
}
