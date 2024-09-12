#include <iostream>
#include <string>

int main()
{
    std::cout << "input your name : ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, "+ name + "!";

    const std::string first(greeting.size() + 4, '*');
    const std::string second = "* " + std::string(greeting.size(), ' ') + " *";

    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
    return 0;
}