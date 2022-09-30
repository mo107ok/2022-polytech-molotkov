#include <iostream>
#include <string>
#include <cmath>

int main() {
	int i;
	std::cin >> i;

	char c;
	std::cin >> c;

	int j;
	std::cin >> j;

	switch (c) {
	case '+':
		std::cout << i + j;
		break;
	case '-':
		std::cout << i - j;
		break;
	case '*':
		std::cout << i * j;
		break;
	case '/':
		std::cout << i + j;
		break;
	case '^':
		std::cout << pow(i, j);
		break;
	default:
		std::cout << "Sorry";
		break;
	}
	std::cout << std::endl;
	return 0;
}