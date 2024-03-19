#include<iostream>
#include "NodeUtils.h"

using namespace std;

static  void secondTask() {
	Node<double>* head = NULL;
	Node<double>* currentNode;
	Node<double>* end = NULL;

	cout << "Enter 10 numbers:" << endl;
	for (int i = 1; i <= 10; i++)
	{
		Node<double>* currentNode = new struct Node<double>;
		currentNode->next = NULL;
		cin >> currentNode->data;
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
	cout << "The list" << endl;
	currentNode = head;
	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
	cout << endl;
	currentNode = head;



	while (currentNode != NULL)
	{
		if (currentNode->data < 0) currentNode->data = 0;
		if (currentNode->data > 0) currentNode->data = 1;
		currentNode = currentNode->next;
	}
	currentNode = head;

	cout << "The list" << endl;
	currentNode = head;
	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
	cout << endl;
	currentNode = head;
}