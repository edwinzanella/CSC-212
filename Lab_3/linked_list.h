#pragma once
#include "node.h"
#include <vector>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class LinkedList{
    private:
        Node* head;
        unsigned int size;

    public:
        LinkedList(); // this->head = nullptr;
        LinkedList(int data);
        LinkedList(std::vector<int> vec);
        ~LinkedList();

        void push_front(int data);
        void push_back(int data);
        void insert(int data, int idx); // For any `idx` > `size`, append the value
        void remove(int data);
        bool contains(int data);
        int get_size();
        void choose_constructor(std::string fname, LinkedList& list, std::ifstream& infile);
        void get_line(std::string fname, std::vector<int>& data, std::ifstream& infile, LinkedList& list);
        std::string to_string();
};