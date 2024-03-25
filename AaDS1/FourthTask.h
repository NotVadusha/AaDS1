#include<iostream>
#include "NodeUtils.h"

using namespace std;

static  void fourthTask() {
	Node<int>* head = NULL;
	Node<int>* currentNode;
	Node<int>* end = NULL;

	int counter = 0;
	cout << "Enter number before count of even number will be 5:" << endl;
	for (int i = 1; i <= 10; i++)
	{
		if (counter == 5) break;

		Node<int>* currentNode = new struct Node<int>;
		currentNode->next = NULL;
		cin >> currentNode->data;

		if (currentNode->data % 2 == 0)
			counter++;

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

	int maxValue = NULL;
	while (currentNode != NULL)
	{
		if (currentNode->data > maxValue) maxValue = currentNode->data;
		currentNode = currentNode->next;
	}

	currentNode = head;
	while (currentNode != NULL)
	{
		if (currentNode->data == maxValue) currentNode = deleteNode(head, end, currentNode);
		else currentNode = currentNode->next;
	}
	currentNode = head;

	displayList<int>(head);
	wipeMemory(head);
}