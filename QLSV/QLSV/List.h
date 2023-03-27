#pragma once
#include "Node.h"

class List
{
public:
	Node* head;
	Node* tail;

public:
	List();
	~List();

public:
	List& operator=(const List&);

public:
	void addTail(Node*&);
	void clear();

	string toString();
};

