#include <iostream>
#include <iomanip>
int main()
{
bool flag;
std::cout << "unesi " << true << " - " << false << std::endl;
std::cin >> flag;
std::cout << std::boolalpha << flag << std::endl;
int a = 255;
std::cout << "hex " << std::hex << a << std::endl;
std::cout << "dec " << std::dec << a << std::ends;
std::cout << "oct " << std::oct << a << std::flush;
double pi = 3.141592;
std::cout << "pi = " << std::scientific << std::uppercase;
std::cout << std::setprecision(3) << std::setw(0) << std::setfill('0'
);
std::cout << pi << std::endl;
}