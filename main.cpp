#include "FileCustom.h"

int main()
{

    FileCustom* f = new FileCustom();

    char from[] = "E:/cpp_project/NextLev/test1.txt";
    char to[] = "E:/cpp_project/NextLev/test2.txt";

    f->Copy(*from, *to);
}
