#include <iostream> //Allows us to print and request input.
#include <fstream> //Allows us to use text files.
#include <string> //Allows us to use std::string variables.
#include <stdio.h> //Allows us to delete and rename files.

int main() {
	std::fstream file("Database.txt", std::ios::in | std::ios::out | std::ios::app);
	if (!file) { //Error Checking
		std::cout << "Error: Failed to create file." << std::endl;
	}
	else {
		int choice;
		std::string name, company, model, color, line;
		std::cout << "1 - Append new records\n2 - Edit records\n3 - Remove records\n4 - Display records\n";
		std::cin >> choice;
		/*
		Case 1 - Append
		Case 2 - Edit
		Case 3 - Remove
		Case 4 - Display
		*/
		switch (choice) {
		case 1:
			std::cin.ignore(); //Skips characters in the input stream to avoid bugs.
			std::cout << "Name: ";
			std::getline(std::cin, name);
			std::cout << "Company: ";
			std::getline(std::cin, company);
			std::cout << "Model: ";
			std::getline(std::cin, model);
			std::cout << "Colour: ";
			std::getline(std::cin, color);
			file <<  name << " " << company << " " << model << " " << color << "\n";
			break;
		case 2:
			std::cin.ignore();
			std::cout << "Enter name: ";
			std::getline(std::cin, name);
			while (!file.eof()) {
				file >> line;
				if (line == name) {
					std::string oName, oCompany, oModel, oColor;
					oName = line;
					file >> oCompany;
					file >> oModel;
					file >> oColor;
				record:
					std::cout << "Record found.\n";
					std::cout << "New Name: ";
					std::getline(std::cin, name);
					std::cout << "New Company: ";
					std::getline(std::cin, company);
					std::cout << "New Model: ";
					std::getline(std::cin, model);
					std::cout << "New Colour: ";
					std::getline(std::cin, color);
					if (name.size() == 0 || company.size() == 0 || model.size() == 0 || color.size() == 0) {
						std::cout << "Error: One or more new field is empty. Please try again." << std::endl;
						goto record;
					}
					std::fstream EditedFile("nDatabase.txt", std::ios::in | std::ios::out | std::ios::app);
					/*
					In c++, the only way to modify a line is to completely rewrite the text file, which involves creating a new text file,
					entering everything in only modifying the line that needs to be modified, remove the original file, and rename the new file to
					the old file's name.
					*/
					if (!EditedFile) {
						std::cout << "Failed to create new database.txt" << std::endl;
						break;
					}
					else {
						file.seekg(0, std::ios::beg);
						while (!file.eof()) {
							std::getline(file, line);
							if (line == oName + " " + oCompany + " " + oModel + " " + oColor) {
								line = name + " " + company + " " + model + " " + color;
							}
							EditedFile << line << "\n";
						}
						file.close();
						EditedFile.close();
						remove("Database.txt");
						rename("nDatabase.txt", "Database.txt");
					}

					goto skipA;
				}
			}
			std::cout << "Unable to edit record; name not found.\n";
		skipA:
			break;
		case 3:
		{
			std::cin.ignore();
			std::cout << "Enter Name: ";
			std::getline(std::cin, name);
			std::fstream EditFile("nDatabase.txt", std::ios::in | std::ios::out | std::ios::app);
			//Same thing as case 2, except this is removing a line.
			if (!EditFile) {
				std::cout << "Unable to created new database.txt" << std::endl;
			}
			else {
				while (!file.eof()) {
					std::getline(file, line);
					if (line.find(name) != std::string::npos) {
						line = "";
					}
					if (line.size() > 0) {
						EditFile << line << "\n";
					}
					else {
						EditFile << line;
					}
				}
				file.close();
				EditFile.close();
				remove("Database.txt");
				rename("nDatabase.txt", "Database.txt");
				break;
			}

			std::cout << "Unable to delete record; name not found.\n";
		}
		break;

		case 4:
			std::cout << "(name, company, model, colour)" << std::endl;
			while (!file.eof()) {
				std::getline(file, line);
				std::cout << line << std::endl;
			}
			break;
		default:
			std::cout << choice << " is not a valid command." << std::endl;
		}
	}
	system("pause");
	return 0;
}