#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "Hamster.h"
#include "Snake.h"
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char*argv[]){

    // Extract # of animals we're expecting to read from the CLA
	int animal_count = atoi(argv[1]);

    // Extract the name of the file we'll be reading from the CLA
	std::string fname = argv[2];

	// Create a collection (data structure) of the appropriate size to hold the # of animals we are creating

	Animal *animals[animal_count];

	std::ifstream infile;
	infile.open(fname);

	// Loop through the number of animals we have.
	for (int i = 0; i < animal_count; i++) {
		// Read the current line from the file		
		std::string type;
		std::string hunger_string;
		std::string thirst_string;

		// Tokenize the line into type, hunger, thirst
		std::getline(infile, type, ' ');
		std::getline(infile, hunger_string, ' ');
		std::getline(infile, thirst_string, '\n');
		float hunger = std::stof(hunger_string);
		float thirst = std::stof(thirst_string);

		// Based on the type, create the appropriate animal and add it to your collection of animals
        if (type == "Cat") {
            animals[i] = new Cat(hunger, thirst);
        }
        if (type == "Dog") {
            animals[i] = new Dog(hunger, thirst);
        }
        if (type == "Bird") {
            animals[i] = new Bird(hunger, thirst);
        }
        if (type == "Hamster") {
            animals[i] = new Hamster(hunger, thirst);
        }
        if (type == "Snake") {
            animals[i] = new Snake(hunger, thirst);
        }

	}
	infile.close();


		
	// Loop through your collection of animals 
	for (int i = 0; i < animal_count; i++) {
		// Speak
		animals[i]->Speak();
		// Output hunger
		std::cout << animals[i]->GetHunger() << std::endl;
		// Output thirst
		std::cout << animals[i]->GetThirst() << std::endl;
	}

	return 0;
}
