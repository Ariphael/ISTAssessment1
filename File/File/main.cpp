#include <iostream>
#include <fstream>

int main() {
	std::fstream file("Car.txt",std::ios::in|std::ios::out|std::ios::app);
	if (!file) {
		std::cout << "Error: Failed to create file." << std::endl;
	}
	else {

		file.close();
	}
}