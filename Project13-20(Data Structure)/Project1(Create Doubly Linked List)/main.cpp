#include <iostream>
#include "Classes/clsDblLinkedList.h"
#include "Classes/clsNode.h"
using namespace std;
int main()
{system("clear");

    clsDblLinkedList<int> MydblLinkedList;

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    clsNode<int>* N1 = MydblLinkedList.Find(2);
    if(N1 != NULL)
        cout << "\nNode with value 2 is Found :-)\n";
    else
        cout << "\nNode Is not Found :-(\n";

    MydblLinkedList.InsertAfter(N1, 500);
    cout << "\nAfter Inserting 500 after 2:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAtEnd(700);
    cout << "\nAfter Inserting 700 at end:\n";
    MydblLinkedList.PrintList();

    clsNode<int>* N2 = MydblLinkedList.Find(4);
    MydblLinkedList.DeleteNode(N2);
    cout << "\nAfter Deleting 4:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.DeleteFirstNode();
    cout << "\nAfter Deleting First Node:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.DeleteLastNode();
    cout << "\nAfter Deleting Last Node:\n";
    MydblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MydblLinkedList.Size();

    if(MydblLinkedList.IsEmpty())
        cout << "\n\nYes List is Empty.\n";
    else
        cout << "\n\nNo List is not Empty.\n";

    MydblLinkedList.Clear();
    cout << "\nNumber of items in the linked list = " << MydblLinkedList.Size() << endl;

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.Reverse();

    cout << "\nLinked List Contenet After Reverse:\n";
    MydblLinkedList.PrintList();

    clsNode<int> *N = MydblLinkedList.GetNode(2);
    cout << "\nNode Value Is: " << N->value << endl;

    cout << "\nItem 2 Value is: " << MydblLinkedList.GetItem(2);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.UpdateItem(2, 500);
    cout << "\nAfter Updating Item (2): \n";
    MydblLinkedList.PrintList();

    MydblLinkedList.UpdateItem(2, 3);
    cout << "\nAfter Updating Item (2): \n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAfter(4, 500);
    cout << "\nAfter Insert:\n";
    MydblLinkedList.PrintList();
 



    

    





    
    


cout << "\n\n\n";
    return 0;
}