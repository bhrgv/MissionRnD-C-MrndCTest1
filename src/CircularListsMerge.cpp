/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int getLength(struct node* head)
{
	int count = 0;
	if (head == NULL)
		return 0;
	struct node* first = head;
	do
	{
		count++;
		head = head->next;
	} while (head != first);
	return count;
}
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	int len1 = getLength(*head1);
	int len2 = getLength(*head2);
	if (*head1 == NULL && *head2 == NULL)
		return -1;
	else if (*head1 == NULL)
	{
		return len2;
	}
	else if (*head2 == NULL)
	{
		return getLength(*head1);
	}
	struct node* list1 = *head1;
	struct node* list2 = *head2;
	struct node head;
	head.next = NULL;
	struct node* curr = &head;
	int count1 = 0, count2 = 0;
	while(1)
	{
		if (count1 == len1 || count2 == len2)
			break;
		if (list1->data > list2->data)
		{
			curr->next = list2;
			count2++;
			list2 = list2->next;
		}
		else
		{
			curr->next = list1;
			count1++;
			list1 = list1->next;
		}
		curr = curr->next;
	}
	while (count1 != len1)
	{
		curr->next = list1;
		count1++;
		list1 = list1->next;
		curr = curr->next;
	}
	while (count2 != len2)
	{
		curr->next = list2;
		count2++;
		list2 = list2->next;
		curr = curr->next;
	}
	curr->next = head.next;
	return getLength(head.next);
}