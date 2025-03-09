#include "priority_node.h"

// Default constructor
PriorityNode::PriorityNode(){
    this->data = 0;
    this->priority = 0;
    this->next = nullptr;
}

PriorityNode::PriorityNode(int data, int priority){
    this->data = data;
    this->priority = priority;
    this->next = nullptr;
}

PriorityNode::PriorityNode(int data, PriorityNode* next, int priority){
    this->data = data;
    this->priority = priority;
    this->next = next;
}

PriorityNode::~PriorityNode(){

}
