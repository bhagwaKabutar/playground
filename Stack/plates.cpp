#include <iostream>
#include <string>
class Stack{
private:
    int top;
    std::string arr[10];
public:

    Stack(){
        top = -1;
    }

    void push(std::string data);
    std::string peek();
    void pop();
};

int main(){
    
    Stack plates;
    plates.push("Red");
    plates.push("Green");
    plates.push("Yellow");
    std::cout<<plates.peek()<<"\n";
    plates.pop();
    plates.pop();
    plates.push("Black");
    std::cout<<plates.peek()<<"\n";

    return 0;
}

void Stack::push(std::string data){
    if(top>10){
        std::cout<<"Stack Overflow!\n";
    }
    else{
        arr[++top] = data;
    }
}

std::string Stack::peek(){
    if(top<0){
        std::string s = "Stack Empty\n";
        return s;
    }
    else{
        return arr[top];
    }
}
void Stack::pop(){
    if(top<0){
        std::cout<<"Stack Underflow\n";
    }
    else{
        std::cout<<"Poped: "<<arr[top]<<" from stack.\n";
        top--;
    }
}