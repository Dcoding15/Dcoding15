// Write a C program to insert, delete, display in linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

struct node *head;

void traverse()
{
	struct node * ptr = head;
	ptr = ptr->next;
	if(ptr == NULL)
	{
		printf("\nNO LINKED LIST FOUND\n");
	}
	else
	{
		printf("\nLINKED LIST: ");
		while(ptr != NULL)
		{
			printf(" %d",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

void insertAtBeginning()
{
	struct node * ptr = head;
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	int value;
	printf("\nVALUE : ");
	scanf("%d",&value);
	temp->data = value;
	temp->next = ptr->next;
	ptr->next = temp;
}

void insertAtEnding()
{
	struct node * ptr = head;
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	int value;
	printf("\nVALUE : ");
	scanf("%d",&value);
	temp->data = value;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
}

void insertIndexPosition()
{
	struct node * ptr = head;
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	int value, index, i = 1;
	printf("\nVALUE  : ");
	scanf("%d",&value);
	temp->data = value;
	printf("POSITION : ");
	scanf("%d",&index);
	while(ptr != NULL && i <= index)
	{
		if(i == index)
		{
			temp->next = ptr->next;
			ptr->next = temp;
			break;
		}
		else
		{
			i++;
			ptr = ptr->next;
		}
	}
}

void deleteAtBeginning()
{
	struct node * ptr = head;
	if(ptr->next == NULL)
	{
		printf("NO LINKED LIST HERE\n");
	}
	else
	{
		ptr->next = ptr->next->next;
	}
}

void deleteAtEnding()
{
	struct node * ptr = head;
	if(ptr->next == NULL)
	{
		printf("NO LINKED LIST HERE\n");
	}
	else
	{
		while(ptr->next->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = NULL;
	}
}

void deleteIndexPosition()
{
	struct node * ptr = head;
	int index, i = 1;
	if(ptr->next == NULL)
	{
		printf("\nNO LINKED LIST FOUND\n");
	}
	else
	{
		printf("\nPOSITION : ");
		scanf("%d",&index);
		while(ptr->next->next != NULL && i <= index)
		{
			if(i == index)
			{
				ptr->next = ptr->next->next;
				break;
			}
			else
			{
				i++;
				ptr = ptr->next;
			}
		}
	}
}

void searchElement()
{
	struct node * ptr = head;
	int element, i = 1;
	printf("\nELEMENT: ");
	scanf("%d",&element);
	ptr = ptr->next;
	if(ptr == NULL)
	{
		printf("\nNO LINKED LIST FOUND\n");
	}
	else
	{
		while(ptr != NULL)
		{
			if(ptr->data == element)
			{
				printf("\nElement found at position %d\n",i);
				break;
			}
			else
			{
				i++;
				ptr = ptr->next;
			}
		}
		if(ptr == NULL)
		{
			printf("\nElement not found at any position\n");
		}
		
	}
}

int main()
{
	head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	int x, y = 1;
	while(y)
	{
		printf("\n\t LINKED LIST INSERTING OPERATION: - \n");
		printf("\t 1. INSERT AT BEGINNING \n");
		printf("\t 2. INSERT AT ENDING \n");
		printf("\t 3. INSERT AT ANY POSITION \n");
		printf("\t 4. DELETE AT BEGINNING \n");
		printf("\t 5. DELETE AT ENDING \n");
		printf("\t 6. DELETE AT ANY POSITION \n");
		printf("\t 7. SEARCH ELEMENT \n");
		printf("\t 8. PRINT LINKED LIST \n");
		printf("\t 9. EXIT \n");
		printf("\nEnter your option: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				insertAtBeginning();
				break;
			case 2:
				insertAtEnding();
				break;
			case 3:
				insertIndexPosition();
				break;
			case 4:
				deleteAtBeginning();
				break;
			case 5:
				deleteAtEnding();
				break;
			case 6:
				deleteIndexPosition();
				break;
			case 7:
				searchElement();
				break;
			case 8:
				traverse();
				break;
			case 9:
				y--;
				printf("\n");
				break;
			default:
				printf("\nWRONG OPTION\n");
		}
	}
}
