//
// Created by anthony on 11/5/21.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    this->head = NULL;
}

void LinkedList::addValue(int id) {
    if (this->head == NULL){
        this->head = new Node(id);
    }else{
        Node * tmp = this->head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new Node(id);
    }
}

int LinkedList::getValueAt(int i) {
    int counter = 0;
    int id_return;
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
        cout << "<" << tmp->id << ">" << endl;
        tmp = tmp->next;
    }
}



