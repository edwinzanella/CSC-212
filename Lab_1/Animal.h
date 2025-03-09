#ifndef LAB_01_CODE_ANIMAL_H
#define LAB_01_CODE_ANIMAL_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Animal{
private:
    float hunger;
    float thirst;

public:
    Animal(float initial_hunger, float initial_thirst);
    void Eat(float sustenance);
    float GetHunger();
    float GetThirst();
    void Drink(float quench);
    virtual void Speak() = 0;
};

#endif //LAB_01_CODE_ANIMAL_H
