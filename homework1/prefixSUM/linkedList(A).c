#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    long long countA;
    long long countB;
    long long totalPares;
} LinkedList;

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->countA = 0;
    list->countB = 0;
    list->totalPares = 0;
    return list;
}

void insertHead(LinkedList* list, char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = list->head;
    newNode->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode;
    }
    list->head = newNode;

    if (val == 'A') {
        list->countA++;
        list->totalPares += list->countB;
    } else if (val == 'B') {
        list->countB++;
    }
}

void insertTail(LinkedList* list, char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    list->tail = newNode;

    // Update counts
    if (val == 'A') {
        list->countA++;
    } else if (val == 'B') {
        list->countB++;
        list->totalPares += list->countA;
    }
}

void popHead(LinkedList* list) {
    if (list->head == NULL) return;

    Node* temp = list->head;
    char val = temp->data;

    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }

    if (val == 'A') {
        list->countA--;
        list->totalPares -= list->countB;
    } else if (val == 'B') {
        list->countB--;
    }

    free(temp);
}

void popTail(LinkedList* list) {
    if (list->tail == NULL) return;

    Node* temp = list->tail;
    char val = temp->data;

    list->tail = list->tail->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    if (val == 'A') {
        list->countA--;
    } else if (val == 'B') {
        list->countB--;
        list->totalPares -= list->countA;
    }

    free(temp);
}

void freeList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    LinkedList* list = createList();
    int op;
    char val;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &op) != 1 || op == 0) break;

        if (op == 2) {
            scanf(" %c", &val);
            insertHead(list, val);
        } else if (op == 1) {
            scanf(" %c", &val);
            insertTail(list, val);
        } else if (op == 3) {
            popTail(list);
        } else if (op == 4) {
            popHead(list);
        }

        printf("%lld\n", list->totalPares);
    }

    freeList(list);
    return 0;
}
