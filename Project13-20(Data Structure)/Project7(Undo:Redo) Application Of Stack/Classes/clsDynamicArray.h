#pragma once
#include <iostream>
using namespace std;
template <class T>
class clsDynamicArray
{
    protected:
        int _Size;
        T* _TempArray;

    public:
        T* OriginalArray;

        clsDynamicArray(int size = 0)
        {
            if(size<0)
                size = 0;
            this->_Size = size;
            this->OriginalArray = new T [_Size];
        }


        ~clsDynamicArray()
        {
            delete [] OriginalArray;
        }

        void SetItem(int index, T value)
        {   
            if(index >= _Size || index < 0)
                return;
            OriginalArray[index] = value;
        }

        void Print()
        {
            for(int i=0;i<_Size;i++)
                cout << OriginalArray[i] << "   ";
            cout << endl;
        }

        bool IsEmpty()
        {
            if(_Size==0)
                return true;
            else return false;
        }

        int Size()
        {
            return this->_Size;
        }

        void Resize(int NewSize)
        {
            if(NewSize == _Size)
                return;

            if(NewSize < 0)
                NewSize = 0;

            _TempArray = new T[NewSize];

            if(_Size > NewSize)
                _Size = NewSize;
            
            for(int i=0; i<_Size; i++)
                _TempArray[i] = OriginalArray[i];
            
            _Size = NewSize;
            delete []OriginalArray;
            OriginalArray = _TempArray;

        }

        T GetItem(int index)
        {
            if(index < 0 || index >= _Size)
                return T(); // Return defualt value of T
            return OriginalArray[index];
        }

        void Reverse()
        {
            _TempArray = new T[_Size];
            for(int i=0;i<_Size;i++)
                _TempArray[i] = OriginalArray[_Size-1-i];
            delete []OriginalArray;
            OriginalArray = _TempArray;
        }

        void Clear()
        {
            _TempArray = new T[0];
            delete OriginalArray;
            OriginalArray = _TempArray;
            _Size = 0;
        }

        void DeleteItemAt(int index)
        {
            if(index < 0 || index >= _Size)
                return;
            _TempArray = new T[_Size-1];
            
            int indexOfTempArray = 0;
            for(int i=0;i<_Size;i++)
            {
                if(index != i)
                {
                    _TempArray[indexOfTempArray] = OriginalArray[i];
                    indexOfTempArray++;
                }
            }
            _Size--;
            delete []OriginalArray;
            OriginalArray = _TempArray;

        }

        void DeleteFirstItem()
        {
            DeleteItemAt(0);
        }

        void DeleteLastItem()
        {
            DeleteItemAt(_Size-1);
        }

        T Find(T value)
        {
            for(int i=0;i<_Size;i++)
            {
                if(value == OriginalArray[i])
                    return i;
            }
            return -1;
        }

        void DeleteItem(T value)
        {
            int Index = Find(value);
            if(Index == -1)
                return;
            else
                DeleteItemAt(Index);

        }

        void InsertAt(int index, T value)
        {
            if ( index < 0 || index > _Size ) {
			    return;
            }

            Resize(_Size + 1);

            for ( int i = _Size; i > index; i-- ) {
                OriginalArray[i] = OriginalArray [i-1];
            }

            OriginalArray[index] = value;
        }

        void InsertAtBeginning(T value)
        {
            InsertAt(0,value);
        }

        void InsertBefore(int index, T value)
        {  
            if(index < 1)
                InsertAt(0,value);
            else
                InsertAt(index-1, value);
        }

        void InsertAfter(int index, T value)
        {
            if(index>=_Size)
                InsertAt(_Size-1,value);
            else
                InsertAt(index+1, value);
        }

        void InsertAtEnd(T value)
        {
            InsertAt(_Size, value);
        }

        


};