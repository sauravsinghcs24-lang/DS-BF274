#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
};

struct Node *head = NULL;


void createList(int n) {
struct Node *newNode, *temp;
int data, i;

for (i = 1; i <= n; i++) {
newNode = (struct Node*)malloc(sizeof(struct Node));
printf("Enter data for node %d: ", i);
scanf("%d", &data);

newNode->data = data;
newNode->next = NULL;

if (head == NULL) {
head = newNode;
temp = head;
} else {
temp->next = newNode;
temp = newNode;
}
}
}

void insertAtBeginning(int data) {
struct Node *newNode;
newNode = (struct Node*)malloc(sizeof(struct Node));

newNode->data = data;
newNode->next = head;
head = newNode;
}

void insertAtEnd(int data) {
struct Node *newNode, *temp;
newNode = (struct Node*)malloc(sizeof(struct Node));

newNode->data = data;
newNode->next = NULL;

if (head == NULL) {
head = newNode;
} else {
temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
}
}


void insertAtPosition(int data, int position) {
int i;
struct Node *newNode, *temp;
newNode = (struct Node*)malloc(sizeof(struct Node));

newNode->data = data;
temp = head;

if (position == 1) {
newNode->next = head;
head = newNode;
return;
}

for (i = 1; i < position - 1 && temp != NULL; i++) {
temp = temp->next;
}

if (temp != NULL) {
newNode->next = temp->next;
temp->next = newNode;
} else {
printf("Position not found!\n");
}
}

void displayList() {
struct Node *temp;
temp = head;

if (head == NULL) {
printf("List is empty.\n");
return;
}

printf("Linked List: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

int main() {
int n, choice, data, pos;

printf("Enter number of nodes: ");
scanf("%d", &n);
createList(n);

printf("\nLinked List created successfully!\n");
displayList();

while (1) {
printf("\n1. Insert at Beginning\n");
printf("2. Insert at End\n");
printf("3. Insert at Any Position\n");
printf("4. Display List\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter data to insert at beginning: ");
scanf("%d", &data);
insertAtBeginning(data);
displayList();
break;

case 2:
printf("Enter data to insert at end: ");
scanf("%d", &data);
insertAtEnd(data);
displayList();
break;

case 3:
printf("Enter data and position: ");
scanf("%d%d", &data, &pos);
insertAtPosition(data, pos);
displayList();
break;

case 4:
displayList();
break;

case 5:
exit(0);
break;

default:
printf("Invalid choice!\n");
}
}

return 0;
}