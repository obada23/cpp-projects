#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsNode
{
    public:
        T value;
        clsNode *next;
        clsNode *prev;

        clsNode(T value)
        {
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }

        clsNode()
        {
            this->value = 0;
            this->next = nullptr;
            this->prev = nullptr;
        }
};