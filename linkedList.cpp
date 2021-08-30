//
// Created by Mahta Shafiee Sabet on 2021-06-21.
//

#include "linkedList.h"
#include "iostream"

linkedList::linkedList() {
    head = nullptr;
}

void linkedList::push_back(node* newElement) {
    path* newNode = new path();
    newNode->start = newElement;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if(head == nullptr) {
        head = newNode;
    } else {
        path* temp = head;

        this->head = newNode;
        newNode->next = temp;
        temp->prev = head;
        newNode->prev = nullptr;
//        while(temp->next != NULL)
//            temp = temp->next;
//        temp->next = newNode;
//        newNode->prev = temp;
    }
}

path *linkedList::back() {
    return head;
}

void linkedList::erase(path* p) {
    if(p == head){
        if(head->next == nullptr){
            p->~path();
            head = nullptr;
            return;
        }
        head = head->next;
        head->prev = nullptr;

        p->~path();
        return;
    }
    else if(p->prev != nullptr){
        p->prev->next = p->next;
        if(p->next != nullptr ){
            p->next->prev = p->prev;
        }
//        p->~path();
        return;
    }
    if(p->prev == nullptr && p != head){
        cout << "Error: this is not in the list!";
    }
}
