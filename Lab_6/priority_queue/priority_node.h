#pragma once

class PriorityNode{
    private:
        int data;
        int priority;
        PriorityNode* next;

        friend class PriorityQueue;
    public:
        PriorityNode();
        // Overloading
        PriorityNode(int data, int priority);
        PriorityNode(int data, PriorityNode* next, int priority);
        ~PriorityNode();
};