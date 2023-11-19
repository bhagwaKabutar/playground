#include<iostream>

class Queue{
private:
    int* arr = new int[6];
    int rear,front;
public:
    Queue(){
        rear=front=-1;
    }
    void enqueue(int data);
    int dequeue();
};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    std::cout<<q.dequeue();
    std::cout<<q.dequeue();
    q.enqueue(9);
    std::cout<<q.dequeue();
    q.enqueue(10);
    std::cout<<q.dequeue();
    q.enqueue(11);
    q.enqueue(12);
    std::cout<<q.dequeue();
    std::cout<<q.dequeue();
    std::cout<<q.dequeue();
    std::cout<<q.dequeue();
    std::cout<<q.dequeue();
    return 0;
}
void Queue::enqueue(int data){
    if(rear==5){
        std::cout<<"\nQueue Overflow!";
    }
    else if(rear==-1 and front==-1){
        rear=front=0;
        arr[rear]=data;
        std::cout<<"\nitem inserted "<<data;
    }else{
        arr[++rear]=data;
        std::cout<<"\nitem inserted "<<data;
    }
}
int Queue::dequeue(){
    if(front==-1){
        std::cout<<"Queue underflow";
        return -1;
    }
    else if(front>rear){
        std::cout<<"\nQueue is empty";
        return -1;
    }
    else{
        std::cout<<"\nitem is poped ";
        //front++;
        return arr[front++];
    }
}