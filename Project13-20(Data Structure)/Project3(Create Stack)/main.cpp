#include <iostream>
#include "Classes/clsStack.h"
using namespace std;
int main()
{system("clear");

    clsStack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    cout << "Stack: \n";
    myStack.Print();

    cout << "\n\nStack Size: " << myStack.Size();
    cout << "\nStack Top: " << myStack.Top();
    cout << "\nStack Bottom: " << myStack.Bottom();

    cout << "\n\nStack after pop() :\n";
    myStack.pop();
    myStack.Print();

    cout << "\n\nItem(2) : " << myStack.GetItem(2);

    cout << "\n\nStack after reverse() :\n";
    myStack.Reverse();
    myStack.Print();

    cout << "\n\nStack after updating Item(2) to 600 : \n";
    myStack.UpdateItem(2, 600);
    myStack.Print();

    cout << "\n\nStack after Inserting 800 after Item(2) :\n";
    myStack.InsertAfter(2, 800);
    myStack.Print();

    cout << "\n\nStack after Inserting 1000 at top : \n";
    myStack.InsertAtTop(1000);
    myStack.Print();

    cout << "\n\nStack after Inserting 2000 at bottom : \n";
    myStack.InsertAtBottom(2000);
    myStack.Print();

    cout << "\n\nStack after Clear() : \n";
    myStack.Clear();
    myStack.Print();

    





cout << "\n\n\n";
    return 0;
}