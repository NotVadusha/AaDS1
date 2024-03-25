#include<iostream>
#include "NodeUtils.h"

using namespace std;

static void thirdTask() {
	Node<int>* head = NULL;
	Node<int>* currentNode;
	Node<int>* end = NULL;

	int count = 0;
	cout << "Enter numbers before their sum will be dividable by their count:" << endl;
	for (int i = 1; i <= 10; i++)
	{
		Node<int>* currentNode = new struct Node<int>;
		currentNode->next = NULL;
		cin >> currentNode->data;
		count += currentNode->data;
		if (i != 1) if (count % 2 == 0) {
			break;
		}

		if (head == NULL)
		{
			head = currentNode;
			end = currentNode;
		}
		else
		{
			end->next = currentNode;
			end = currentNode;
		}
	}
	currentNode = head;

	displayList<int>(head);
	currentNode = head;

	Node<int>* maxNode = new struct Node<int>;
	while (currentNode != NULL)
	{
		if (currentNode->data > maxNode->data) maxNode = currentNode;
		else currentNode = currentNode->next;
	}

	Node<int>* newElement = new struct Node<int>;
	newElement->data = 33;

	currentNode = head;
	while (currentNode != NULL)
	{
		if (currentNode == maxNode) {
			newElement->next = currentNode->next;
			currentNode->next = newElement;
		}
		currentNode = currentNode->next;
	}
	currentNode = head;

	displayList<int>(head);

	wipeMemory(head);
}