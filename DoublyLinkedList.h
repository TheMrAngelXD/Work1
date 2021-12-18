#pragma once
#include <iostream>
using namespace std;
/**
	Задает элемент списка,
	указатели на начальный и конечный элементы
 */
struct Elem
{
	int data;
	Elem* head, * tail;
};
/**
   Создание класса Список,
   указатели на начало и конец списка
   Счетчик на количество элементов в списке
*/
class List
{
	Elem* head, * tail;
	size_t count;

public:
	/**
	Конструктор по умолчанию
 */
	List();
	/**
	Конструктор копирования
 */
	List(const List&);
	/**
	Деструктор
 */
	~List();

	/**
	Получает количество элементов в списке
 */
	size_t getCount();
	/**
	Получает элемент из списка по заданному индексу
 */
	Elem* getElement(const size_t index);

	/**
	Удаление всего списка
 */
	void delAll();
	/**
	Удаление элемента,если нет параметра,
	то происходит запрос
 */
	void del(int pos = 0);
	/**
	Вставка элемента,если нет параметра,
	то происходит запрос
 */
	void insert(int pos = 0);

	/**
	Добавление элемента в конец списка
 */
	void addTail();

	/**
	Добавление элемента в начало списка
 */
	void addHead();

	/**
	Вывод списка в консоль
 */
	friend std::ostream& operator << (std::ostream& out, const List& list);
};

std::ostream& operator << (std::ostream& out, const List& list)
{
	out<< list;
	return out;
}
	