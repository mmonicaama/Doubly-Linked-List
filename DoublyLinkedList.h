#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void push_front(int);
	void push_back(int);
	void insert(int, int);
	void remove(int);
	int get(int) const;
	void printList() const;
	void printReverse() const;
	int getSize() const;

private:
	struct Node
	{
	public:
		Node();
		Node(int);

	public:
		int data;
		Node* prev;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
};

#endif // DOUBLYLINKEDLIST_H