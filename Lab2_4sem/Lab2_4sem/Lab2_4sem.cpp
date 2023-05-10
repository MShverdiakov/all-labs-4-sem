#include "Header.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    
    Set set;
    try { set = load_data(); }
    catch (const char* msg) { cout << msg; return 2; }
    cout << set;
}