#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[20];
    float marks;
};

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBeginning(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insertEnd(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp;

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void printList(void) {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void) {
    struct student s1 = {101, "Aman", 88.5f};
    int *p;

    printf("Student record: Roll=%d, Name=%s, Marks=%.2f\n",
           s1.roll, s1.name, s1.marks);

    p = (int *)malloc(5 * sizeof(int));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        p[i] = i + 1;
    }

    printf("Dynamic array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    p = (int *)realloc(p, 10 * sizeof(int));
    if (p == NULL) {
        printf("Reallocation failed.\n");
        return 1;
    }

    for (int i = 5; i < 10; i++) {
        p[i] = i + 1;
    }

    printf("Resized array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p);

    insertBeginning(10);
    insertBeginning(20);
    insertEnd(30);
    printList();

    return 0;
}
