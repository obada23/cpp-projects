#include <iostream>
#include "Classes/clsQueue.h"
#include "Classes/clsNode.h"
using namespace std;

int main()
{system("clear");

    
    clsQueue <int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);

    cout << "Queue:\n";
    myQueue.PrintQueue();

    cout << "\n\nQueue Size: " << myQueue.Size();
    cout << "\nQueue Front:  " <<  myQueue.Front();
    cout << "\nQueue Back: " << myQueue.Back();

    cout << "\nQueue after pop() :\n";
    myQueue.pop();
    myQueue.PrintQueue();

    cout << "\n\nItem(2) : " << myQueue.GetItem(2);

    myQueue.Reverse();
    cout << "\n\nQueue after reverse() : \n";
    myQueue.PrintQueue();

    myQueue.UpdateItem(2,600);
    cout << "\n\nQueue after updating Item(2) to 600 : \n";
    myQueue.PrintQueue();

    myQueue.InsertAfter(2,800);
    cout << "\n\nQueue after Inserting 800 after Item(2) : \n";
    myQueue.PrintQueue();

    myQueue.InsertAtFront(1000);
    cout << "\n\nQueue after Inserting 1000 at front: \n";
    myQueue.PrintQueue();

    myQueue.InsertAtBack(2000);
    cout << "\n\nQueue after Inserting 2000 at back: \n";
    myQueue.PrintQueue();

    myQueue.Clear();
    cout << "\n\nQueue after Clear(): \n";
    myQueue.PrintQueue();







cout << "\n\n\n";
    return 0;
}