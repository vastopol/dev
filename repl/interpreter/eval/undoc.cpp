#include "undoc.h"

void unsafe()
{
    std::string danger_com = "DANGER";
    std::cout << '>'; std::cin >> danger_com; std::cout << '\n';
    system(danger_com.c_str());
}
//-------------------------------------------------------------------------------------------

