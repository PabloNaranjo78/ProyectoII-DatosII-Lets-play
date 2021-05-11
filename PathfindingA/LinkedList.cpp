//
// Created by anthony on 11/5/21.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    this->head = NULL;
}

void LinkedList::addValue(int val, int id) {
    if (this->head == NULL){
        this->head = new Node(id, val);
    }else{
        Node * tmp = this->head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new Node(id, val);
    }
}

int LinkedList::getValueAtTop() {
    int check = this->head->value;
    int id_return = this->head->id;
    Node * tmp = this->head;
    while (tmp != NULL){
        if (tmp->value < check){
            check = tmp->value;
            id_return = tmp->id;
        }
        tmp = tmp->next;
    }
    this->deleteNode(id_return);
    return id_return;

}

void LinkedList::deleteNode(int id) {
    Node * tmp = this->head;
    while (tmp != NULL){
        if (tmp->next->id == id){
            tmp->next = tmp->next->next;
            break;
        }
        tmp = tmp->next;
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
    return check;
}

void LinkedList::printList() {
    Node * tmp = this->head;
    while (tmp != NULL){
        cout << "<" << tmp->value << ">" << endl;
        tmp = tmp->next;
    }
}



