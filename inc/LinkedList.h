#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

//TODO: Create your Node Struct and Queue class here
struct Node {
    string data;
    Node* next;

    Node(string value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;
    int count;
public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const string& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        count--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    string peek() const {
        if (isEmpty()) {
            return "";
        }
        return head->data;
    }

    int size() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void print() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;

    }
};

#endif