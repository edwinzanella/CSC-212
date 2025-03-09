#pragma once
#include "node.h"
#include <vector>
#include <string>

class Queue{
    private:
        Node* head;
        unsigned int size;

    public:
        Queue(); // this->head = nullptr;
        Queue(int data);
        Queue(std::vector<int> vec);

        void enqueue(int data); // push_back
        void dequeue();
        int peek();
        std::string to_string();
};