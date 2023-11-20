#include<iostream>

class Person{
public:
    std::string name,sex;
    int age;
    Person* next;

    Person(std::string name, std::string sex, int age){
        this->name = name;
        this->sex = sex;
        this->age = age;
        this->next = nullptr;
    }
};


class Queue{
public:
    Person* front = nullptr;

    void enqueue(std::string n, std::string s, int a){
        Person* newPerson = new Person(n,s,a);
        if(front==nullptr){
            front = newPerson;
            return;
        }
        Person* tracer = front;
        while (tracer->next!=nullptr){
            tracer= tracer->next;
        }
        tracer->next = newPerson;
    }
    void dequeue(){
        if(front==nullptr){
            std::cout<<"\nQueue is empty";
        }
        Person* tracer = front;
        front = tracer->next;
        std::cout<<"\n"<<tracer->name<<" is remvoed from the queue.";
        delete tracer;
    }
};


int main(){
    Queue q;
    q.enqueue("Test","male",12);
    q.enqueue("Test 2","female",14);
    q.enqueue("Test 3","female",18);
    q.dequeue();
    q.dequeue();
    return 0;
}