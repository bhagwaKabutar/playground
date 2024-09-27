#include<iostream>
#include<string>
//This is the comment added.
class Node{
public:
    std::string data;
    Node* next;

    Node(std::string data){
        this->data = data;
        this->next = nullptr;
    }
};

class Stack{
private:
    Node* top;
public:
    void push(std::string data);
    void pop();
    void peak();
};

int main(){
    Stack stk;
    stk.push("red");
    stk.push("green");
    stk.push("blue");
    stk.push("black0");
    stk.peak();
    stk.pop();
    stk.pop();
    stk.peak();
    return 0;
}
void Stack::push(std::string data){
    Node* newNode = new Node(data);
    if(top==nullptr){top = newNode;}
    else{
        newNode->next = top;
        top = newNode;
    }
}
void Stack::pop(){
    if(top==nullptr){
        std::cout<< "Stack underflow\n";
    }
    Node* t = top;
    top = t->next;
    std::cout<<t->data<<" is popped!\n";
    delete t;
}
void Stack::peak(){
    std::cout<<top->data<<"\n";
}
