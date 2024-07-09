#pragma once
#include <iostream>
#include "clsNode.h"
using namespace std;

template <class T>
class clsQueue
{
    private:
        int counter;
        clsNode *front;
        clsNode *back;
    
    public:
        clsQueue()
        {
            this->counter = 0;
            this->front = this->back = NULL;
        }

        void push(T value)
        {
            clsNode* new_node = new clsNode(value);
            if(front==NULL)
                front = back = new_node;
            
            new_node->next = back;
            back->prev = new_node;
            back = new_node;
            
            this->counter++;
        }

        void PrintQueue()
        {
            clsNode* current = front;
            while(current!=NULL)
            {
                cout << current->value << "   ";
                current = current->prev;
            }
        }

        int Size()
        {
            return this->counter;
        }

        int Front()
        {
            return this->front->value;
        }

        int Back()
        {
            return this->back->value;
        }

        void pop()
        {
            if(front==NULL)
                return;
            
            if(back == front)
            {
                delete back;
                back = front = nullptr;
            }
            
            else
            {
                clsNode* current = front;
                front = front->prev;
                front->next = nullptr;
                delete current;
            }
            this->counter--;
                
        }

        T GetItem(int index)
        {
            if(index>counter-1 || index<0)
                return -999;

            else
            {
                clsNode *current = front;
                for(int i=0; i<index; i++)
                    current = current->prev;
                return current->value;
                
            }
        }

        void Reverse()
        {
            clsNode *f = front;
            clsNode *b = back;
            clsNode *temp = new clsNode();
            for(int i=0;i<Size()/2;i++)
            {
                temp->value = f->value;
                f->value = b->value;
                b->value = temp->value;
                f = f->prev;
                b = b->next;
            }
            delete temp;
        }

        void UpdateItem(int index, T value)
        {
            if(index>counter-1 || index<0)
                return;

            else
            {
                clsNode *current = front;
                for(int i=0; i<index; i++)
                    current = current->prev;
                current->value = value;
                
            }

        }

        void InsertAfter(int index, T value)
        {
            if(index>counter-1 || index<0)
                return;
            
            clsNode *current = front;
            for(int i=0;i<index;i++)
                current = current->prev;
            
            clsNode *new_node = new clsNode(value);
            new_node->next = current;
            new_node->prev = current->prev;
            if(current->prev!=nullptr)
                current->prev->next = new_node;
            current->prev = new_node;
            if(new_node->prev == nullptr)
                back = new_node;
            this->counter++;
            
        }

        void InsertAtFront(T value)
        {
            clsNode *new_node = new clsNode(value);
            if(front==NULL)
                front = back = new_node;
            
            else
            {
                new_node->prev = front;
                front->next = new_node;
                front = new_node;
            }

            this->counter++;
        }

        void InsertAtBack(T value)
        {
            clsNode *new_node = new clsNode(value);
            if(front==NULL)
                front = back = new_node;
            
            else
            {
                new_node->next = back;
                back->prev = new_node;
                back = new_node;
            }

            this->counter++;
        }

        void Clear()
        {
            while(this->front!=NULL)
            {
                pop();
            }
        }

        
};