#include <iostream>
#include "Classes/clsStackArr.h"
using namespace std;

int main()
{system("clear");

    
    clsStackArr <int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    cout << "Stack:\n";
    myStack.Print();

    cout << "\nStack Size: " << myStack.Size();
    cout << "\nStack Top:  " <<  myStack.Top();
    cout << "\nStack Bottom: " << myStack.Bottom();

    cout << "\n\nStack after pop() :\n";
    myStack.pop();
    myStack.Print();

    cout << "\n\nItem(2) : " << myStack.GetItem(2);

    myStack.Reverse();
    cout << "\n\nStack after reverse() : \n";
    myStack.Print();

    myStack.UpdateItem(2,600);
    cout << "\n\nStack after updating Item(2) to 600 : \n";
    myStack.Print();

    myStack.InsertAfter(2,800);
    cout << "\n\nStack after Inserting 800 after Item(2) : \n";
    myStack.Print();

    myStack.InsertAtTop(1000);
    cout << "\n\nStack after Inserting 1000 at Top: \n";
    myStack.Print();

    myStack.InsertAtBottom(2000);
    cout << "\n\nStack after Inserting 2000 at Bottom: \n";
    myStack.Print();

    myStack.Clear();
    cout << "\n\nStack after Clear(): \n";
    myStack.Print();




cout << "\n\n\n";
    return 0;
}