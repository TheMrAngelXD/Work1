#include <iostream>
#include "../DoublyLinkedList.h"

using namespace std;

int main()
{
    List ll;
    ll.addElementTail(1);
    ll.addElementTail(2);
    ll.addElementTail(3);
    ll.deleteElement(0);
    //ll.addElement(77, -3);
    //ll.addElement(33, 3);
    //ll.changeElement(3, 89);
    //ll.changeElement(0, 89);
    //ll.deleteElement(2);
    cout << ll.getElements();
}
