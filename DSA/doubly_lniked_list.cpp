#include <stdio.h>
#include <stdlib.h>


struct Node 
{
	int data;
	struct Node* next;
	struct Node* prev;
};

void deleteNode(struct Node** head_ref, struct Node* del)
{
	if (*head_ref == NULL || del == NULL)
		return;
	if (*head_ref == del)
		*head_ref = del->next;

	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;

	free(del);
	return;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}

void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node* head = NULL;

	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);

	printf("\n Original Linked list ");
	printList(head);
	deleteNode(&head, head); 
	deleteNode(&head, head->next); 
	deleteNode(&head, head->next);
	printf("\n Modified Linked list ");
	printList(head);
	getchar();
}
