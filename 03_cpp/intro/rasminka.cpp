
#include <iostream> 
#include <string> 

int main()
{
	std::cout << "������� ��� ";
	std::string name;

	std::getline(std::cin, name);

	std::cout << "������������," << name << '!';

	std::cin.get();
	return 0;
}
