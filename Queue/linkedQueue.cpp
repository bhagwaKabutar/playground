#include<iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LQueue{
private:
    Node* front;
    Node* rear;
public:
    LQueue(){
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int data);
    void dequeue();
};

int main(){
    LQueue q;
    
    q.dequeue();
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.enqueue(7);
    q.enqueue(8);
    q.dequeue();
    return 0;
}
void LQueue::enqueue(int data){
    if(rear==nullptr){
        Node* newNode = new Node(data);
        front=rear=newNode;
        std::cout<<"\nitem added "<<data;
    }
    else{
        Node* newNode = new Node(data);
        Node* t = front;
        while(t->next!=nullptr){
            t=t->next;
        }
        t->next = newNode;
        rear = newNode;
        std::cout<<"\nitem added "<<data;
    }
}
void LQueue::dequeue(){
    if(front==nullptr){
        std::cout<<"\nQueue Underflow";
    }
    else{
        std::cout<<"\nitem removed "<<front->data;
        front = front->next;
    }
}