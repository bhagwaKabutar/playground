
#include <iostream>

class Node{
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
public:
    Node* head;
    int len = 0;
    LinkedList() {
        head = nullptr;
    }

    void pushHead(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            len++;
            return;
        }
        newNode->next = head;
        head = newNode;
        len++;
    }

    void pushTail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            len++;
            return;
        }
        Node* tracer = head;
        while (tracer->next != nullptr) {
            tracer = tracer->next;
        }
        tracer->next = newNode;
    }

    void pushAt(int data,int pos) {
        if (head == nullptr) {
            std::cout << "Add items in the list first [ addItem(data) ]\n";
        }
        if (pos < len) {


            Node* newNode = new Node(data);
            if (pos == 0) {
                newNode->next = head;
                head = newNode;
                len++;
                return;
            }
            Node* tracer = head;

            for (int i = 0; i < pos - 1; i++) {
                tracer = tracer->next;
            }
            newNode->next = tracer->next;
            tracer->next = newNode;
            len++;
        }
        else {
            std::cout << "Enter the valid position.";
        }
    }

    void deleteNode(int pos) {
        Node* tracer = head;
        Node* pre_tracer = nullptr;
        for (int i = 0; i < pos; i++) {
            pre_tracer = tracer;
            tracer = tracer->next;
        }
        pre_tracer->next = tracer->next;
        delete tracer;
        tracer = nullptr;

    }
    void modifyNode(int data, int pos) {
        Node* tracer = head;
        for (int i = 0;i < pos; i++) {
            tracer = tracer->next;
        }
        tracer->data = data;
    }

    void printList() {
        Node* tracer = head;
        while (tracer != nullptr) {
            std::cout << tracer->data << "->";
            tracer = tracer->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList li;
    li.pushHead(1);
    li.pushHead(2);
    li.pushHead(3);
    li.pushHead(4);
    li.pushHead(5);
    li.printList();
    li.pushTail(0);
    li.printList();
    li.pushAt(99, 3);
    li.printList();
    li.modifyNode(56, 3);
    li.printList();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
