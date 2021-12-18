#include <iostream>
#include "DoublyLL.h"

using namespace std;

List::List()
{
	head = tail = NULL;
	count = 0;
}
List::~List()
{
	delAll();
}