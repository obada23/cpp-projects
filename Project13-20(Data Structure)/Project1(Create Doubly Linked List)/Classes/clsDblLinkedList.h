#pragma once
#include <iostream>
#include "clsNode.h"
using namespace std;

template <class T>
class clsDblLinkedList
{
    private:
        int count;
        clsNode<T> *first;
        clsNode<T> *last;

    public:
        clsDblLinkedList()
        {
            this->count = 0;
            this->first = this->last = nullptr;
        }

        void InsertAtBeginning(T value)
        {
            clsNode<T> *new_node = new clsNode<T>(value);

            if(this->first==nullptr)
                first = last = new_node;

            else
            {
                new_node->next = first;
                first->prev = new_node;
                first = new_node;
            }
            new_node = NULL;
            delete new_node;
            this->count++;
        }
        
        void InsertAtEnd(T value)
        {
            clsNode<T> *new_node = new clsNode<T>(value);

            if(this->first == nullptr)
                this->first = this->last = new_node;
            

            else if(this->first == this->last)
            {
                last = new_node;
                first->next = last;
                last->prev = first;
            }

            else
            {
                last->next = new_node;
                new_node->prev = last;
                last = new_node;
            }
            this->count++;
            new_node = NULL;
            delete new_node;

        }

        void PrintList()
        {
            clsNode<T> *current = first;
            while(current!=nullptr)
            {
                cout << current->value << "  ";
                current = current->next;
            }
            delete current;
            cout << endl << endl;
        }

        clsNode<T>* Find(T value)
        {
            clsNode<T> *current = first;
            while(current!=NULL)
            {
                if(current->value == value)
                {
                    return current; 
                }
                current = current->next;
            }
            return NULL;
        }

        void InsertAfter(clsNode<T> *prev_node ,T value)
        {
            if(prev_node == NULL)
                return;

            clsNode<T>* new_node = new clsNode<T>(value);
            
            new_node->next = prev_node->next;
            prev_node->next = new_node;
            new_node->prev = prev_node;
            new_node->next->prev = new_node;
            if(new_node->next == nullptr)
                this->last = new_node;

            prev_node = NULL;
            delete prev_node;
            new_node = NULL;
            delete new_node;
            this->count++;


        }

        void InsertAfter(int index ,T value)
        {
            if(index < 0 || index > Size()-1)
                return;


            clsNode<T>* new_node = new clsNode<T>(value);
            clsNode<T>* current = first;

            for(int i=0;i<index;i++)
            {
                current = current->next;
            }
            new_node->next = current->next;
            new_node->prev = current;

            if(current->next!=NULL)
                current->next->prev = new_node;

            current->next = new_node;
           
            
            if(new_node->next==NULL)
                last = new_node;

            this->count++;
        

        }

        void DeleteNode(clsNode<T> *nodeToDelete)
        {
            if(nodeToDelete == NULL)
                return;
            
            if(this->count == 1)
                this->first = this->last = NULL;
            
            
            else if(nodeToDelete == first)
            {
                first = first->next;
                nodeToDelete->next = NULL;
                first->prev = NULL;
            }

            else if(nodeToDelete == last)
            {
                last = last->prev;
                last->next = NULL;
                nodeToDelete->prev = NULL;
            }
            
            else
            {
                nodeToDelete->prev->next = nodeToDelete->next;
                nodeToDelete->next->prev = nodeToDelete->prev;
            }

            delete nodeToDelete;
            this->count--;
        }

        void DeleteFirstNode()
        {
            if(first == NULL)
                return;
            
            if(first==last)
            {
                delete first;
                first = last = NULL;
            }

            else
            {
                clsNode<T> *current = first;
                first = first->next;
                current->next = NULL;
                first->prev = NULL;
                delete current;
            }

            this->count--;
        }

        void DeleteLastNode()
        {
            if(last==NULL)
                return;
            
            if(first==last)
            {
                delete first;
                first = last = NULL;
            }

            else
            {
                clsNode<T> *current = last;
                last = last->prev;
                last->next = NULL;
                current->prev = NULL;
                delete current;
            }

            this->count--;
        }

        int Size()
        {
            return this->count;
        }

        bool IsEmpty()
        {
            return this->count==0;
        }

        void Clear()
        {
            while(this->count!=0)
            {
                DeleteLastNode();
            }
        }

        void Reverse()
        {
            clsNode<T> *in = first;
            clsNode<T> *out = last;
            for(int i=0;i<Size()/2;i++)
            {
                clsNode<T> *temp = new clsNode<T>(in->value);
                in->value = out->value;
                out->value = temp->value;
                in = in->next;
                out = out->prev;
                delete temp;
            }
            
        }

        clsNode<T> *GetNode(int index)
        {
            if(index > Size()-1 || index < 0 )
                return NULL;

            clsNode<T> *current = first;
            for(int i=0;i<index;i++)
                current = current->next;
            return current;
        }

        int GetItem(int index)
        {
            if(index > Size()-1 || index < 0 );
            else
            {
                clsNode<T> *current = first;
                for(int i=0;i<index;i++)
                    current = current->next;
                return current->value;
            }
            
        }

        void UpdateItem(int index, int newValue)
        {
            if(index > Size()-1 || index < 0 )
                return;

            {
                clsNode<T> *current = first;
                for(int i=0;i<index;i++)
                    current = current->next;
                current->value = newValue;
            } 
        }
};