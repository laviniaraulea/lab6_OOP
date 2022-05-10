#include "Lab10.h"
#include <QtWidgets/QApplication>
#include "service.h"
#include "Gui.h"
#include "test.h"

void run_GUI(int argc, char* argv[])
{
    QApplication a(argc, argv);
    repo* r = new repo;
    service s{ r };

    pharmacyGUI gui{ s };
    gui.show();
    a.exec();
}
int main(int argc, char *argv[])
{
    test_all();
    run_GUI(argc, argv);
  
}
