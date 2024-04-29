#include <iostream>
#include "parser.h"
#include "fileManager.h"
#include "clientManager.h"
#include "employeeManager.h"
#include "adminManager.h"
#include "fileHelper.h"
#include "screens.h"

using namespace std;
int main()
{
  Screens screen;
  screen.runApp();
  return 0;
}
