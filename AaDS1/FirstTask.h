#include<iostream>
#include "NodeUtils.h"

using namespace std;

static ListStatitics calculatePercentage(Node<int>* head)
{
	int countPositive = 0;
	int countNegative = 0;
	int countZeros = 0;
	int count = 0;

	Node<int>* currentNode = head;
	while (currentNode != NULL)
	{
		count++;
		if (currentNode->data > 0)
		{
			countPositive++;
		}
		else if (currentNode->data < 0)
		{
			countNegative++;
		}
		else
		{
			countZeros++;
		}
		currentNode = currentNode->next;
	}

	ListStatitics result = {
		count,
		(double)countPositive / count * 100,
		(double)countNegative / count * 100,
		(double)countZeros / count * 100
	};

	return result;
}

static void firstTask() {
	Node<int>* head = NULL;
	Node<int>* currentNode;
	Node<int>* end = NULL;

	cout << "Enter 10 numbers:" << endl;
	for (int i = 1; i <= 10; i++)
	{
		Node<int>* currentNode = new struct Node<int>;
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
	
	displayList(head);

	currentNode = head;

	ListStatitics result = calculatePercentage(head);
	cout << "Count = " << result.count << endl;
	cout << "Percentage of positive elements = " << result.positive << endl;
	cout << "Percentage of negative elements = " << result.negative << endl;
	cout << "Percentage of zeros = " << result.zeros << endl;
	wipeMemory(head);
}