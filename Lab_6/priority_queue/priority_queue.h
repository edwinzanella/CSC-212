#pragma once

#include "priority_node.h"
#include <string>
#include <vector>

class PriorityQueue {
    private:
        PriorityNode* head;
        int size;

    public:
        PriorityQueue();
        ~PriorityQueue();

        void enqueue(int data, int priority);
        void dequeue();
        std::pair<int, int> peek();
        std::string to_string();
};