#pragma once
#include <iostream>
#include "clsNode.h"
using namespace std;

class clsStack
{
    private:
        int counter;
        clsNode *top;
        clsNode *bottom;
    
    public:
        clsStack()
        {
            this->counter = 0;
            this->top = nullptr;
            this->bottom = nullptr;
        }

        void push(int value)
        {
            clsNode *new_node = new clsNode(value);
            if(top==NULL)
                top = bottom = new_node;
            
            else
            {
                new_node->next = top;
                top->prev = new_node;
                top = new_node;
            }

            this->counter++;

        }

        void Print()
        {
            clsNode *current = top;
            while(current!=NULL)
            {
                cout << current->value << "   ";
                current = current->next;
            }
        }

        int Size()
        {
            return this->counter;
        }

        int Top()
        {
            return this->top->value;
        }

        int Bottom()
        {
            return this->bottom->value;
        }

        void pop()
        {
            if(top==NULL)
                return;
            
            if(top == bottom)
            {
                delete top;
                top = bottom = nullptr;
            }

            else
            {
                clsNode *current = top;
                top = top->next;
                top->prev = nullptr;
                delete current;
            }

            this->counter--;
        }

        int GetItem(int index)
        {
            if(index<0 || index>=this->counter)
                return -999;
            
            else
            {
                clsNode *current = top;
                for(int i=0;i<index;i++)
                    current = current->next;
                return current->value;
            }
        }

        void Reverse()
        {
            clsNode *t = top;
            clsNode *b = bottom;
            clsNode *temp = new clsNode();
            for(int i=0;i<this->counter/2;i++)
            {
                temp->value = t->value;
                t->value = b->value;
                b->value = temp->value;
                t = t->next;
                b = b->prev;
            }
            delete temp;
        }

        void UpdateItem(int index, int value)
        {
            if(index<0 || index>=this->counter)
                return;
            
            else
            {
                clsNode *current = top;
                for(int i=0;i<index;i++)
                    current = current->next;
                current->value = value;
            }
        }

        void InsertAfter(int index, int value)
        {
            if(index<0 || index>=this->counter)
                return;
            
            else
            {
                clsNode *current = top;
                for(int i=0;i<index;i++)
                    current = current->next;
                clsNode *new_node = new clsNode(value);
                new_node->prev = current;
                new_node->next = current->next;
                if(current->next != nullptr)
                    current->next->prev = new_node;
                current->next = new_node;
                if(new_node->next == nullptr)
                    bottom = new_node;
                this->counter++;
            }
        }

        void InsertAtTop(int value)
        {
            if(top==NULL)
                return;
            
            clsNode *new_node = new clsNode(value);
            new_node->next = top;
            top->prev = new_node;
            top = new_node;

            this->counter++;
        }

        void InsertAtBottom(int value)
        {
            if(bottom==NULL)
                return;
            
            clsNode *new_node = new clsNode(value);
            bottom->next = new_node;
            new_node->prev = bottom;
            bottom = new_node;
            this->counter++;
        }

        void Clear()
        {
            while(top!=NULL)
                pop();
        }
};