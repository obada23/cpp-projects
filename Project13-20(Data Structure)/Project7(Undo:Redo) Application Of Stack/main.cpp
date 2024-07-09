#include <iostream>
#include "Classes/clsMyString.h"
using namespace std;
int main()
{system("claer");

    clsMyString S1;
    cout << "\nS1 = " << S1.Value() << endl;

    S1.setValue("Obada");
    cout << "\nS1 = " << S1.Value() << "\n";

    S1.setValue("Obada2");
    cout << "\nS1 = " << S1.Value() << "\n";

    S1.setValue("Obada3");
    cout << "\nS1 = " << S1.Value() << "\n";

    cout << "\n\nUndo:";
    cout << "\n----------\n";

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value() << endl;

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value() << endl;

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value() << endl;

    cout << "\n\nRedo:";
    cout << "\n----------\n";

    S1.Redo();
    cout << "\nS1 after Redo = " << S1.Value() << endl;

    S1.Redo();
    cout << "\nS1 after Redo = " << S1.Value() << endl;

    S1.Redo();
    cout << "\nS1 after Redo = " << S1.Value() << endl;

    


cout << "\n\n\n";
    return 0;
}