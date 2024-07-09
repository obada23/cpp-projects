#include <iostream>
#include "clsDynamicArray.h"
using namespace std;
int main()
{system("clear");

    clsDynamicArray<int> MyDynamicArray(5);
    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs Empty?   " << MyDynamicArray.IsEmpty();
    cout << "\nArray Size:  " << MyDynamicArray.Size();
    cout << "\n\nArray Items:\n";
    MyDynamicArray.Print();

   /*  MyDynamicArray.Resize(2);
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    cout << "\nArray Items after resize to 2 : \n";
    MyDynamicArray.Print();

    MyDynamicArray.Resize(10);
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    cout << "\nArray Items after resize to 2 : \n";
    MyDynamicArray.Print(); */

    cout << "\nItem(2): " << MyDynamicArray.GetItem(2) << endl;

    MyDynamicArray.Reverse();
    cout << "\nArray Items after reverse:\n";
    MyDynamicArray.Print();

    /* MyDynamicArray.Clear();
    MyDynamicArray.Print(); */

   /*  MyDynamicArray.DeleteItemAt(2);
    cout << "\nArray Items after deleting item(2): \n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();

    MyDynamicArray.DeleteFirstItem();
    cout << "\nArray Items after deleting first item: \n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();

    MyDynamicArray.DeleteLastItem();
    cout << "\nArray Items after deleting last item: \n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print(); */

    int Index = MyDynamicArray.Find(30);
    if(Index == -1)
        cout << "\nItem was not found :-(\n";
    else
        cout << "\n30 is found at index : " << Index;
    
    MyDynamicArray.DeleteItem(30);
    cout << "\n\nArray Items after deleting 30: ";
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();

    MyDynamicArray.InsertAt(0, 500);
    cout << "\n\nArray after insert 500 at index 2: ";
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();

    MyDynamicArray.InsertAtBeginning(400);
    cout << "\n\nArray after insert 400 at beginning: ";
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();

    MyDynamicArray.InsertBefore(2, 100);
    cout << "\n\nArray after insert 100 before index 2: ";
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();

    MyDynamicArray.InsertAfter(2, 200);
    cout << "\n\nArray after insert 200 after index 2: ";
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();

    MyDynamicArray.InsertAtEnd(800);
    cout << "\n\nArray after insert 800 at end: ";
    cout << "\nArray Size: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();


    

    



cout << "\n\n\n";
    return 0;
}