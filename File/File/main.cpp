#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::fstream file("Database.txt",std::ios::in|std::ios::out|std::ios::app);
	if (!file) {
		std::cout << "Error: Failed to create file." << std::endl;
	}
	else {
		int choice;
		std::string name, company, model, color;
		std::cout << "1 - Append new records\n2 - Edit records\n3 - Remove records\n";
		std::cin >> choice;
		/*
		1 - Append
		2 - Edit
		3 - Remove
		*/
		switch (choice) {
		case 1:
			std::cin.ignore();
			std::cout << "Name: ";
			std::getline(std::cin, name);
			std::cout << "Company: ";
			std::getline(std::cin, company);
			std::cout << "Model: ";
			std::getline(std::cin, model);
			std::cout << "Colour: ";
			std::getline(std::cin, color);
			file << "Name: " << name << std::endl;
			file << "Company: " << company << std::endl;
			file << "Model: " << model << std::endl;
			file << "Colour: " << color << std::endl;
			break;
		case 2:

			break;
		case 3:

			break;
		default:
			std::cout << choice << " is not a valid command." << std::endl;
		}
	}
	system("pause");
	return 0;
}