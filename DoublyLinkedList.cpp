#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

void List::addElementHead(int data)
{
	const auto element = new Element(data, this->head, nullptr);
	if (this->head != nullptr)
	{
		element->next = this->head;
		this->head->previous = element;
		this->head = element;
	}
	else
	{
		this->head = element;
		this->tail = element;
	}
	this->count++;
}


void List::addElementTail(int data)
{
	const auto element = new Element(data, nullptr, this->tail);
	if (this->head != nullptr)
	{
		this->tail->next = element;
		element->previous = this->tail;
		this->tail = element;
	}
	else
	{
		this->head = element;
		this->tail = element;
	}
	this->count++;
}

void List::addElement(int data, int pos)
{
	if (pos < 0)
	{
		throw std::out_of_range("Позиция должна быть положительным числом");
	}
	else if (pos == 0)
	{
		addElementHead(data);
	}
	else if ((unsigned int)pos > this->count)
	{
		addElementTail(data);
	}
	else
	{
		const auto element = new Element(data, nullptr, this->tail);
		auto insertBefore = this->head;
		int i = 0;
		while (i != pos)
		{
			insertBefore = insertBefore->next;
			i++;
		}
		element->next = insertBefore;
		element->previous = insertBefore->previous;
		insertBefore->previous->next = element;
		element->next->previous = element;
	}
}

void List::changeElement(int numberElement, int setData)
{
	if (numberElement < 0) throw std::out_of_range("Позиция должна быть положительным числом");
	if (numberElement > this->count) throw std::out_of_range("Позиция не должна быть больше размера");
	else
	{
		int i = 0;
		auto itemToChange = this->head;
		while (i < numberElement)
		{
			itemToChange = itemToChange->next;
			i++;
		}
		itemToChange->data = setData;
	}
}

void List::deleteElement(int numberElement)
{
	if (numberElement < 0) throw std::out_of_range("Позиция должна быть положительным числом");
	if (numberElement > this->count) throw std::out_of_range("Нельзя удалить несуществующий элемент");
	else
	{
		int i = 0;
		auto itemToDelete = this->head;
		while (i < numberElement)
		{
			itemToDelete = itemToDelete->next;
			i++;
		}
		if (numberElement == 0)
		{
			itemToDelete->next->previous = nullptr;
			this->head = itemToDelete->next;
			delete itemToDelete;
		}
		else {
			itemToDelete->next->previous = itemToDelete->previous;
			itemToDelete->previous->next = itemToDelete->next;
			delete itemToDelete;
		}
		this->count--;
	}
}

const size_t List::getCount()
{
	return this->count;
}

std::string List::getElements()
{
	std::string elements = "";
	auto temp = this->head;
	while (temp != nullptr)
	{
		elements += std::to_string(temp->data);
		temp = temp->next;
		if (temp != nullptr)
		{
			elements += ", ";
		}
	}
	return elements;
}

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
Element::~Element()
{
	this->next = nullptr;
	this->previous = nullptr;
};
