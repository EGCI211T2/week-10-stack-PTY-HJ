
#ifndef stack_h
#define stack_h
#include "node.h"
class Stack {
	NodePtr top;
	int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
};


void Stack::push(int x){
  NodePtr new_node=new NODE(x); // create a new node
  if(new_node){
     //connect the previous top
    new_node->set_next(top);
    //change top
    top=new_node;
    //change size
    size++;
   }
   else{
    cout<<"Not enough memory"<<endl;
   }
    
}

int Stack::pop(){
        NodePtr t=top;
        int value;
        if(t!=NULL){
            value=t->get_value();
        // move top to the next one
            top=t->get_next();
        // decrease the size
            --size;
            delete t;
            return value;
        }
        //be careful of the empty stack!!!
        cout<<"Empty stack"<<endl;
         return 0;
    }

Stack::Stack(){
    //initialize stack
    top=NULL;
    size=0;
    
}
Stack::~Stack(){
    //delete all remaning stack (i.e. pop all)
    cout<<"Clear the stack"<<endl;
    int n=size;
    while(n>0){
        pop();
        n--;
    }
}

#endif
