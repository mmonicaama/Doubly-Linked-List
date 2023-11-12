#include "DoublyLinkedList.h"

#include <stdexcept>
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
	: head(nullptr)
	, tail(nullptr)
	, size(0)
{
}

DoublyLinkedList::~DoublyLinkedList()
{
	Node* tmp;
	while (head != nullptr) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
	
}

DoublyLinkedList::Node::Node()
	: data(0)
	, prev(nullptr)
	, next(nullptr)
{
}

DoublyLinkedList::Node::Node(int d)
	: data(d)
	, prev(nullptr)
	, next(nullptr)
{
}

void DoublyLinkedList::push_front(int value)
{
	Node* newNode = new Node(value);
	++size;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

void DoublyLinkedList::push_back(int value)
{
	Node* newNode = new Node(value);
	++size;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
}

void DoublyLinkedList::insert(int index, int value)
{
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index is out of bounds of the list");
	}
	Node* newNode = new Node(value);
	Node* tmp;
	if (index < size / 2) {
		tmp = head;
		while (index != 0) {
			tmp = tmp->next;
			--index;
		}
	}
	else {
		tmp = tail;
		while (index != 0) {
			tmp = tmp->prev;
			--index;
		}
	}
	newNode->prev = tmp->prev;
	newNode->next = tmp;
	tmp->prev->next = newNode;
	tmp->prev = newNode;
	++size;
}

void DoublyLinkedList::remove(int index)
{
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index is out of bounds of the list");
	}
	Node* tmp;
	if (index < size / 2) {
		tmp = head;
		while (index != 0) {
			tmp = tmp->next;
			--index;
		}
	}
	else {
		tmp = tail;
		while (index != 0) {
			tmp = tmp->prev;
			--index;
		}
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	delete tmp;
	--size;
}

int DoublyLinkedList::get(int index) const
{
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index is of bounds of the list");
	}
	Node* tmp;
	if (index < size / 2) {
		tmp = head;
		while (index != 0) {
			tmp = tmp->next;
			--index;
		}
	}
	else {
		tmp = tail;
		while (index != 0) {
			tmp = tmp->prev;
			--index;
		}
	}
	return tmp->data;
}

void DoublyLinkedList::printList() const
{
	if (head == nullptr) {
		std::cout << "List is empty.\n";
		return;
	}
	std::cout << "List:\n";
	Node* tmp = head;
	while (tmp != nullptr) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << "\n";
}

void DoublyLinkedList::printReverse() const
{
	if (head == nullptr) {
		std::cout << "List is empty.\n";
		return;
	}
	std::cout << "List:\n";
	Node* tmp = tail;
	while (tmp != nullptr) {
		std::cout << tmp->data << " ";
		tmp = tmp->prev;
	}
	std::cout << "\n";
}

int DoublyLinkedList::getSize() const
{
	return size;
}