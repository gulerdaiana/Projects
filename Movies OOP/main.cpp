/*#include "filme.h"
#include "FilmeRepo.h"
#include "Console.h"
#include "teste.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
using namespace std;
int main() {
   testAll();
   system("cls");
    {FilmeRepo repo;
   FilmeServ serv{repo};
   UI ui{serv};
   ui.startUI();}
    return 0;
}*/
#include "Console.h"
#include "teste.h"
int main(int argc, char* argv[]) {
    testAll();
    QApplication a(argc, argv);
    FilmeRepo rep;
    FilmeServ serv{ rep };
    GUI gui{ serv };
    gui.show();
    return a.exec();
}
