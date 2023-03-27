#include "List.h"

List::List()
{
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
	this->clear();
}

List& List::operator=(const List& target)
{
	if (head != nullptr) {
		this->clear();
	}

	head = target.head;
	tail = target.tail;

	return *this;
}

void List::addTail(Node*& target)
{
	if (head == nullptr) {
		head = tail = target;
		target->next = nullptr;
	}
	else {
		tail->next = target;
		tail = target;
	}
}

void List::clear()
{
	while (head != nullptr) {
		Node* cur = head;
		head = head->next;
		delete cur;
	}

	head = nullptr;
	tail = nullptr;
}

string List::toString()
{
	stringstream builder;

	Node* cur = head;
	while (cur != nullptr) {
		builder << cur->data.toString() << endl;
		cur = cur->next;
	}

	return builder.str();
}
