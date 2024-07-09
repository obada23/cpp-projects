#pragma once
#include <iostream>
#include "clsStackArr.h"
using namespace std;
class clsMyString
{
    protected:
        clsStackArr<string> _History;
        clsStackArr<string> _UnDoHistory;

    public:
        clsMyString()
        {
            _History.push("");
        }

        void setValue(string value)
        {
            _History.push(value);
        }

        string Value()
        {
            return _History.Top();
        }

        void Undo()
        {
            if ( _History.Size() == 0 ) { return; }
            _UnDoHistory.push(_History.Top());
            _History.pop();
        }

        void Redo()
        {
            if ( _UnDoHistory.Size() == 0 ) { return; }
            _History.push(_UnDoHistory.Top());
            _UnDoHistory.pop();
        }
};

