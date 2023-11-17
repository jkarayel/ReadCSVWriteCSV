#include <iostream>
#include "employee.h"

int main()
{
    employee CCC("read.csv", "write.csv");
    CCC.ReadFromFile();
    CCC.WriteToFile();
    CCC.CloseFiles();
}
