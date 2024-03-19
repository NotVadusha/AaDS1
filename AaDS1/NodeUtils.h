#pragma once

#include <iostream>

#ifdef _WINDLL
#define DLL_PORT __declspec(dllexport)
#else
#define DLL_PORT __declspec(dllimport)
#endif

using namespace std;

template<class T>
struct Node
{
	T data;
	Node* next;
};

struct DLL_PORT ListStatitics
{
	int count;
	double positive;
	double negative;
	double zeros;
};

template<class T>
static void displayList(Node<T>* head)
{
	Node<T>* currentNode = head;
	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
	cout << endl;
	currentNode = head;
}

template<class T>
void wipeMemory(Node<T>* head)
{
	Node<T>* currentNode = head;
	while (currentNode != NULL)
	{
		head = head->next;
		delete currentNode;
		currentNode = head;
	}
}

template<class T>
Node<T>* deleteNode(Node<T>*& head, Node<T>*& end, Node<T>	* ptr)
{
	if (ptr == NULL) return NULL;
	Node<T>* currentNode = head;

	if (ptr == head)
	{
		head = head->next;
		delete currentNode; return head;
	}

	currentNode = head;
	while (currentNode->next != ptr && currentNode != NULL)
		currentNode = currentNode->next;

	if (currentNode == NULL) return NULL;
	currentNode->next = ptr->next;
	if (ptr == end) end = currentNode;
	delete ptr;

	Node<T>* result = currentNode;
	currentNode = head;

	return result;
}
