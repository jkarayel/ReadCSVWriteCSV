#include <iostream>
#include "employee.h"

int main()
{
    employee CCC("read.txt", "write.txt");
    CCC.ReadFromFile();
    CCC.WriteToFile();
}
