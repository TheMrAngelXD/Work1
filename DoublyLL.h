#pragma once
#include <iostream>
using namespace std;
/**
	Задает элемент списка
 */
struct Elem
{

};
/**
   Создание класса Список
*/
class List
{
	Elem* Head, * Tail;
	int Count;

public:
	/**
	Конструктор
 */
	List();
	/**
	Конструктор с параметрами
 */
	List(const List&);
	/**
	Деструктор
 */
	~List();

	/**
	Получает количество элементов в списке
 */
	int GetCount();
	/**
	Получает элемент из списка
 */
	Elem* GetElem(int);

	/**
	Удаление всего списка
 */
	int DelAll();
	/**
	Удаление элемента,если нет параметра,
	то происходит запрос
 */
	int Del(int pos = 0);
	/**
	Вставка элемента,если нет параметра,
	то происходит запрос
 */
	void Insert(int pos = 0);

	/**
	Добавление элемента в конец списка
 */
	void AddTail(int n);

	/**
	Добавление элемента в начало списка
 */
	void AddHead(int n);

	/**
	Вывод списка в консоль
 */
	void Print();
	/**
	Вывод элемента списка в консоль
 */
	void Print(int pos);
	
};