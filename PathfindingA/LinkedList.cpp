//
// Created by anthony on 11/5/21.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    this->head = NULL;
}

void LinkedList::addValue(int id) {
    this->length++;
    if (this->head == NULL){
        this->head = new Node(id);
    }else{
        Node * tmp = this->head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new Node(id);
    }
    cout << "Node added" << endl;
}

int LinkedList::getValueAt(int i) {
    int counter = 0;
    int id_return = 0;
    Node * tmp = this->head;
    while (tmp != NULL){
        if (i == counter){
            id_return = tmp->id;
            break;
        }
        tmp = tmp->next;
        counter++;
    }
    return id_return;

}

void LinkedList::deleteNode(int id) {
    Node * tmp = this->head;
    if (this->head->id == id){
        cout << "Found" << endl;
        this->head = this->head->next;
        this->length--;
    }
    else{
        while (tmp != NULL) {
            if (tmp->next->id == id) {
                cout << "Found" << endl;
                tmp->next = tmp->next->next;
                this->length--;
                break;
            }
            tmp = tmp->next;
        }
    }
}

bool LinkedList::isIn(int id) {
    Node * tmp = this->head;
    bool check = false;
    while (tmp != NULL){
        if (tmp->id == id){
            check = true;
            break;
        }
        tmp = tmp->next;
    }
    cout << "all right" << endl;
    return check;
}

void LinkedList::printList() {
    Node * tmp = this->head;
    while (tmp != NULL){
        cout << "<" << tmp->id << ">" << endl;
        tmp = tmp->next;
    }
}

string LinkedList::getListString() {
    string result;
    Node * tmp = this->head;
    while (tmp != NULL){
        cout << "<" << tmp->id << ">" << endl;
        result+= "$"+ to_string(tmp->id);
        tmp = tmp->next;
    }
    return result;
}

void LinkedList::setParent(int parent, int id) {
    Node * tmp = this->head;
    while (tmp != NULL){
        if (id == tmp->id){
            tmp->parent = parent;
        }
        tmp = tmp->next;
    }
}

int LinkedList::getParent(int id) {
    Node * tmp = this->head;
    int parent = 0;
    while (tmp != NULL){
        if (id == tmp->id){
            parent = tmp->parent;
            break;
        }
        tmp = tmp->next;
    }
    return parent;
}



