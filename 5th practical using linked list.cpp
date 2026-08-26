#include <iostream>
#include <string>
using namespace std;

// Node of the linked list
class Node {
public:
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = nullptr;
    }
};

// Stack using Singly Linked List
class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(string page) {
        Node* newNode = new Node(page);

        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            return "Stack Underflow";
        }

        Node* temp = top;
        string page = top->page;

        top = top->next;
        delete temp;

        return page;
    }

    string peek() {
        if (isEmpty()) {
            return "";
        }

        return top->page;
    }

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    LinkedListStack backStack;

    string currentPage = "Home";

    // Visit pages
    cout << "Visiting: " << currentPage << endl;

    backStack.push(currentPage);
    currentPage = "Google";
    cout << "Visiting: " << currentPage << endl;

    backStack.push(currentPage);
    currentPage = "YouTube";
    cout << "Visiting: " << currentPage << endl;

    backStack.push(currentPage);
    currentPage = "Wikipedia";
    cout << "Visiting: " << currentPage << endl;

    // Back button
    cout << "\nBack button pressed.\n";

    backStack.pop();

    currentPage = backStack.peek();

    if (!currentPage.empty()) {
        cout << "Current page: " << currentPage << endl;
    }

    cout << "\nBack button pressed.\n";

    backStack.pop();

    currentPage = backStack.peek();

    if (!currentPage.empty()) {
        cout << "Current page: " << currentPage << endl;
    }

    return 0;
}