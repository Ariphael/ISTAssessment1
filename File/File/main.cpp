#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::fstream file("Database.txt",std::ios::in|std::ios::out|std::ios::app);
	if (!file) {
		std::cout << "Error: Failed to create file." << std::endl;
	}
	else {
		bool choice;
		std::string name;
		std::string make;
		std::string model;
		std::string colour;
		std::cout << "Welcome to the offline car depository program!" << std::endl;
		std::cout << "1 to search for information about a person's car properties." << std::endl;
		std::cout << "0 to register information about a person's car properties." << std::endl;
		std::cin >> choice;
		if (!choice) {
			std::cout << "Name: ";
			file << "Name: \n";
			std::getline(std::cin, make);
			file << make;

			std::cout << "Make: ";
			file << "Make: \n";
			std::getline(std::cin, make);
			file << make;

			std::cout << "Model: ";
			file << "Model: \n";
			std::getline(std::cin, model);
			file << model;

			std::cout << "Colour: ";
			file << "Colour: \n";
			std::getline(std::cin, colour);
			file << colour;
		}
		else {

		}
		file.close();
	}
}