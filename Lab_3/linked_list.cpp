#include "linked_list.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>


LinkedList::LinkedList(){
    this->head = nullptr;
    this->size = 0;
}


LinkedList::LinkedList(int data){
    Node *node = new Node(data);
    this->head = node;
    this->head->next = nullptr;
    this->size = 1;
}


LinkedList::LinkedList(std::vector<int> vec){
    this->head = new Node(vec[0]);
    Node *current = this->head;
    this->size = vec.size();

    for (unsigned int i = 1; i < size; i++) {
        current->next = new Node(vec[i]);
        current = current->next;
    }

    current->next = nullptr;
}

LinkedList::~LinkedList(){

}

void LinkedList::push_front(int data){
    Node *new_node = new Node(data);
    new_node->next = this->head;
    this->head = new_node;

    this->size++;
}

void LinkedList::push_back(int data){
    Node *new_node = new Node(data);
    new_node->next = nullptr;

    if (this->head == nullptr) {
        this->head = new_node;
        return;
    }

    Node *current = this->head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new_node;

    this->size++;
}

void LinkedList::insert(int data, int idx){

    if (idx == 0) {
        push_front(data);
    }
    else if (idx > size) {
        push_back(data);
    }
    else {
        Node *new_node = new Node(data);
        Node *current = this->head;
        for (int i = 0; i < idx - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        this->size++;
    }
}

void LinkedList::remove(int data){
    if (head == nullptr) {
        return;
    }

    if (head->data == data) {
        Node* temp = this->head;
        this->head = head->next;
        size--;
        return;
    }

    Node* previous = this->head;
    while (previous->next != nullptr && previous->next->data != data) {
        previous = previous->next;
    }

    if (previous->next != nullptr) {
        Node* current = previous->next;
        previous->next = current->next;
        size--;
    }
}


bool LinkedList::contains(int data){
    Node* current = head;

    while (current != nullptr) {

        if (current->data == data) {
            return true;
        }
        current = current->next;

    }

    return false;
}


int LinkedList::get_size(){
    return this->size;
}

void LinkedList::choose_constructor(std::string fname, LinkedList& list, std::ifstream& infile) {
    std::string first_line;
    std::getline(infile, first_line);

    if (first_line.empty()) {
        list = LinkedList();
    }
    else {
        std::stringstream ss(first_line);
        std::vector<int> values;
        int current_value;

        while (ss >> current_value) {
            values.push_back(std::abs(current_value));
        }

        if (values.size() == 1) {
            list = LinkedList(values[0]);
            std::cout << list.to_string() << std::endl;
        }
        else {
            list = LinkedList(values);
            std::cout << list.to_string() << std::endl;
        }
    }
}

void LinkedList::get_line(std::string line, std::vector<int>& data, std::ifstream& infile, LinkedList& list){
    data.clear();

    std::stringstream ss(line);
    std::string data_value;

    while (ss >> data_value) {
        if (data_value.find('?') != std::string::npos) {
            data_value.erase(std::remove(data_value.begin(), data_value.end(), '?'), data_value.end());
            int integer_value = stoi(data_value);
            std::cout << contains(integer_value) << std::endl;
        }
        else if (data_value.find('-') != std::string::npos){
            data_value.erase(std::remove(data_value.begin(), data_value.end(), '-'), data_value.end());
            int integer_value = stoi(data_value);
            remove(integer_value);
            std::cout << list.to_string() << std::endl;
        }
        else if (line.find(' ') != std::string::npos) {
            std::stringstream ss_pair(line);
            int value, index;
            if (ss_pair >> value >> index) {
                insert(value, index);
                std::cout << list.to_string() << std::endl;
                break;
            }
        }
        else {
            int integer_value = std::stoi(data_value);
            if (integer_value % 2 == 0) {
                push_back(integer_value);
                std::cout << list.to_string() << std::endl;
            } else {
                push_front(integer_value);
                std::cout << list.to_string() << std::endl;
            }
        }
    }
}

// O(n)
std::string LinkedList::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}
