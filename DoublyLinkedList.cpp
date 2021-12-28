#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

List::~List()
{
	while (this->getCount() != 0)
	{
		Element* temp = head->next;
		if (head != nullptr)
		{
			delete head;
			head = nullptr;
		}
		head = temp;
		count--;
	}
}