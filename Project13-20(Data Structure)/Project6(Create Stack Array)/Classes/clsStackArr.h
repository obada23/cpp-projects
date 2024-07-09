#pragma once
#include <iostream>
#include "clsQueue.h"
using namespace std;
template <class T>
class clsStackArr : public clsQueue <T>
{
    
    public:
        void push(T value)
        {
            clsQueue<T>::_MyList.InsertAtEnd(value);
        }

        T Top()
        {
            return clsQueue<T>::_MyList.GetItem(clsQueue<T>::Size()-1);
        }

        T Bottom()
        {
            return clsQueue<T>::_MyList.GetItem(0);
        }

        void pop()
        {
            clsQueue<T>::_MyList.DeleteLastItem();
        }

        void InsertAtTop(T value)
        {
            clsQueue<T>::_MyList.InsertAtEnd(value);
        }

        void InsertAtBottom(T value)
        {
            clsQueue<T>::_MyList.InsertAtBeginning(value);
        }

};