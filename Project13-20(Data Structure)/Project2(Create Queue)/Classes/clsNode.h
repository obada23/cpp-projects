#pragma once
#include <iostream>
using namespace std;

class clsNode
{
    public:
        int value;
        clsNode *next;
        clsNode *prev;

        clsNode(int value)
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