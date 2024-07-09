#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;
template <class T>
class clsQueue
{
    protected:
        clsDynamicArray<T> _MyList;
    
    public:
        void push(T value)
        {
            _MyList.InsertAtEnd(value);
        }

        void Print()
        {
            _MyList.Print();
        }

        int Size()
        {
            return _MyList.Size();
        }

        T Front()
        {
            return _MyList.GetItem(0);
        }

        T Back()
        {
            return _MyList.GetItem(Size()-1);
        }

        void pop()
        {
            _MyList.DeleteFirstItem();
        }

        T GetItem(int index)
        {
            return _MyList.GetItem(index);
        }

        void Reverse()
        {
            _MyList.Reverse();
        }

        void UpdateItem(int index, T value)
        {
            _MyList.SetItem(index, value);
        }

        void InsertAfter(int index, T value)
        {
            _MyList.InsertAfter(index, value);
        }

        void InsertAtFront(T value)
        {
            _MyList.InsertAtBeginning(value);
        }

        void InsertAtBack(T value)
        {
            _MyList.InsertAtEnd(value);
        }

        void Clear()
        {
            _MyList.Clear();
        }
};