#include "queue.h"

// constructors the same as linked list
Queue::Queue() {
    this->head = nullptr;
    this->size = 0;
}

Queue::Queue(int data) {
    this->head = new Node(data);
    this->size = 1;
}

Queue::Queue(std::vector<int> vec){
    if(vec.size() == 0){
        this->head = nullptr;
        this->size = 0;
    }

    else {
        this->head = new Node(vec[0]);
        Node* temp = this->head;

        for(int i = 1; i < vec.size(); i++){
            temp->next = new Node(vec[i]);
            temp = temp->next;
        }
    }
    this->size = vec.size();
}

// same code as push_back
void Queue::enqueue(int data){
    if(this->head == nullptr){
        this->head = new Node(data);
    }
    
    else {
        Node* tmp = this->head;

        while(tmp->next != nullptr){
            tmp = tmp->next;
        }

        tmp->next = new Node(data);
    }

    this->size++;
}

void Queue::dequeue() {
    if (this->head == nullptr) {
        return;
    }

    this->head = this->head->next;
}

int Queue::peek() {
    int peek = this->head->data;
    return peek;
}

std::string Queue::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}