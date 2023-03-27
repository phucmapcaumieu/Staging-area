#include "Node.h"

Node::Node()
{
	Student* emptyStudent = new Student();
	data = *emptyStudent;
	next = nullptr;
}

Node::Node(const Student& target, Node*& next)
{
	data = target;
	this->next = next;
}

Node::~Node()
{
	next = nullptr;
}

Node* Node::makeNode(const Student& target)
{
	Node* result = new Node();
	result->data = target;
	result->next = nullptr;
	
	return result;
}
