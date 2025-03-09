#include "priority_queue.h"
#include <sstream>

PriorityQueue::PriorityQueue() {
    this->head = nullptr;
    this->size = 0;
}

PriorityQueue::~PriorityQueue() {

}

void PriorityQueue::enqueue(int data, int priority) {
    PriorityNode* newNode = new PriorityNode(data, priority);

    if (this->head == nullptr || this->head->priority > priority) {
        newNode->next = this->head;
        this->head = newNode;
    }
    
    else {
        PriorityNode* tmp = this->head;
        while (tmp->next != nullptr && tmp->next->priority <= priority) {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }

    this->size++;
}

void PriorityQueue::dequeue() {
    if (this->head == nullptr) {
        return;
    }

    this->head = this->head->next;
    this->size--;
}

std::pair<int, int> PriorityQueue::peek() {
    if (this->head == nullptr) {
        return std::make_pair(-1, -1);
    }
    return std::make_pair(this->head->data, this->head->priority);
}

std::string PriorityQueue::to_string() {
    std::string stringified;
    PriorityNode* tmp = this->head;

    while(tmp != nullptr){
        stringified += "(" + std::to_string(tmp->data) + "," + std::to_string(tmp->priority) + ")" + " ";
        tmp = tmp->next;
    }

    return stringified;
}