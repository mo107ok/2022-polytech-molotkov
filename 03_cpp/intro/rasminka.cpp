
#include <iostream> 
#include <string> 

int main()
{
	std::cout << "Введите имя";
	std::string name;

	std::getline(std::cin, name);

	std::cout << "Здравствуйте," << name << '!';

	std::cin.get();
	return 0;
}
