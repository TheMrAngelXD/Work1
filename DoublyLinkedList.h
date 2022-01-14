#pragma once
#include <iostream>
using namespace std;
/*!
	\brief Класс звена списка.

	В данном классе реализована структура элемента списка.
	В нем присутствуют приватные поля:
	1. int data - значение элемента списка
	2. Element *next - указатель типа Element на следующий элемент списка
	3. Element *previous - указатель типа Element на предыдущий элемент списка.
*/
class Element
{
	int data;
	Element* next;
	Element* previous;
	friend class List;
public:
	Element(int data, Element* next, Element* previous)
	{
		this->next = next;
		this->previous = previous;
		this->data = data;
	}
};
/*!
	\brief Класс реализации списка.

	В данном классе описана реализация двусвязного списка.
	В нем присутствуют приватные поля:
	1. Element *head, *tail - указатели типа Element на первый элемент списка,
	на последний элемент списка.
	2. size_t count - значение типа size_t количества элементов списка.
	Методы, взаимодействующие с двусвязным списком.
*/
class List
{
	Element* head;
	Element* tail;
	size_t count;
	/*!
	 \brief Приватный метод получения элементов списка.

	 Приватный метод получения элементов списка двусвязного списка.
	 Его предназначение - дальнейшее использование в переопределении
	 оператора сдвига <<.
	*/
	friend ostream& operator << (ostream& out, const List& list);

public:
	/*!
	 \brief Конструктор по умолчанию.

	 В данном конструкторе присваиваются указателям
	 head (начало списка) и tail (конец списка) nullptr (нулевые значения).
	*/
	List():head(nullptr), tail(nullptr) , count(0) {};
	
	/*!
	 \brief Деструктор.

	 В деструкторе присваиваются указателям элементам списка нулевые значения
	 и освобождается память.
	*/
	~List();

	/*!
	 \brief Метод вывода количества элементов списка.
	 \return count - Переменная типа size_t количества элементов списка

	 Метод класса вывода количества элеметов двусвязного списка.
	*/
	const size_t getCount() 
	{
		return count;
	};
	/*!
	 \brief Метод класса добавления элемента в список.
	 \param[in] const int data - значение,
	 которое будет хранить добавленный элемент списке.
	*/
	void addElement(const int data);
	/*!
	 \brief Метод класса изменения значения элемента списка.
	 \param[in] const size_t numberElement - номер элемента,который будет изменяться.
	 \param[in] const int setData - значение элемента,который будет изменяться.

	 Метод класса изменения значения элемента циклического односвязного списка.
	*/
	void changeElement(const size_t numberElement, const int setData);
	/*!
	 \brief Метод класса удаления элемента списка.
	 \param[in] const size_t numberElement - номер элемента, подверженному удалению,
	 введеный с клавиатуры.
	*/
	void deleteElement(const size_t numberElement);
	
};

	