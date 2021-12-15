#include <iostream>
#include "DoublyLL.h"

using namespace std;

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	DelAll();
}