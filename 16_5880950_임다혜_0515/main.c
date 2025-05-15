#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

int main() {
    linkedList_h list = { 0, NULL, NULL };
    int menu, value, target;
    listNode* current;

    do {
        printf("\n===== Linked_List Menu =====\n");
        printf("1) insertFirst (����Ʈ�� ���� �տ� ����)\n");
        printf("2) insertLast (����Ʈ�� ���� �ڿ� ����)\n");
        printf("3) insertMiddle (Ư�� �� �ڿ� ����)\n");
        printf("4) print Head/Tail\n");
        printf("0) Program Stop\n");
        printf("Select menu : ");
        scanf_s("%d", &menu);

        switch (menu) {
        case 1:
            printf("\n������ �� : ");
            scanf_s("%d", &value);
            insertFirstNode(&list, value);
            printHeadTail(&list);
            break;

        case 2:
            printf("\n������ �� : ");
            scanf_s("%d", &value);
            insertLastNode(&list, value);
            printHeadTail(&list);
            break;

        case 3:
            if (list.Node_h == NULL) {
                printf("\n����Ʈ�� ����ֽ��ϴ�.\n");
                break;
            }
            printf("\n� �� �ڿ�? ");
            scanf_s("%d", &target);
            printf("������ �� : ");
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
            printf("\n���α׷��� �����մϴ�.\n");
            break;

        default:
            printf("\n�߸��� �޴��Դϴ�. �ٽ� �����ϼ���.\n");
        }

    } while (menu != 0);

    return 0;
}
