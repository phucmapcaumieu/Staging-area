#pragma once
#include "Student.h"

class Node
{
public:
	Student data;
	Node* next;
	
public:
	Node();
	Node(const Student&, Node*&);
	~Node();

public:
	static Node* makeNode(const Student&);
};

