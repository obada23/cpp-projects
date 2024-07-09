#include <iostream>
#include "clsLoginScreen.h"
using namespace std;

int main()
{
    while(true)
    {
        if(!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }


cout << "\n\n\n";
    return 0;
}