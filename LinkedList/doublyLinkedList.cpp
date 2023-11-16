#include<iostream>

class DLLNode{
    public:
    int data;
    DLLNode* prev;
    DLLNode* next;
    
    DLLNode(int data){
        this->data = data;
        prev = nullptr;
        next=nullptr;
    }
};
class DLinkedList{
    public:
    DLLNode* head;
    DLinkedList(){
        this->head = nullptr;
    }

    void push(int data);
    void pushHead(int data);
    void pushAt(int data, int pos);
    void delNode(int pos);
    void change(int data, int pos);
    void printList();
};
DLLNode* revList(DLLNode* head);

int main(){
    DLinkedList dll = DLinkedList();

    dll.push(1);
    dll.push(2);
    dll.push(3);
    dll.push(4);
    dll.printList();
    DLLNode* rev_head = revList(dll.head);
    while(rev_head!=nullptr){
        std::cout<<rev_head->data<<"->";
        rev_head = rev_head->next;
    }
    return 0;
}


DLLNode* revList(DLLNode* head){
    if(head==nullptr){return head;}
    do{
        DLLNode* t_nxt = head->next;
        head->next = head->prev;
        head->prev = t_nxt;
        if(t_nxt!=nullptr){head = t_nxt;}
    }while(head->prev != nullptr);
    return head;
}

void DLinkedList::push(int data){
    DLLNode* newNode = new DLLNode(data);
    if(head==nullptr){
        head = newNode;
        return;
    }
    DLLNode* tracer = head;
    while(tracer->next!=nullptr){
        tracer = tracer->next;
    }
    tracer->next = newNode;
    newNode->prev = tracer;
    tracer = nullptr;
}

void DLinkedList::pushHead(int data){
    DLLNode* newNode = new DLLNode(data);
    if(head==nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DLinkedList::pushAt(int data,int pos){
    DLLNode* newNode = new DLLNode(data);
    if(head==nullptr){
        head = newNode;
        return;
    }
    if(pos==0){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    DLLNode* tracer = head;
    for(int i =0; i<pos-1; i++){
        tracer=tracer->next;
    }
    newNode->next = tracer->next;
    newNode->prev = tracer;
    tracer->next->prev = newNode;
    tracer->next = newNode;
}

void DLinkedList::delNode(int pos){
    if(head==nullptr){std::cout<<"Nothing to delete!"; return;}
    if(pos ==0){
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        return;
    }
    DLLNode* tracer = head;
    for(int i = 0; i<pos; i++){
        tracer = tracer->next;
    }
    tracer->prev->next =tracer->next;
    tracer->next->prev = tracer->prev;
    delete tracer;
}

void DLinkedList::change(int data, int pos){
    DLLNode* tracer = head;
    for(int i = 0; i<pos; i++){
        tracer = tracer->next;
    }
    tracer->data = data;
}

void DLinkedList::printList(){
    DLLNode* tracer = head;
    while(tracer!=nullptr){
        std::cout<<tracer->data<<"->";
        tracer = tracer->next;
    }
    std::cout<<"\n";
}