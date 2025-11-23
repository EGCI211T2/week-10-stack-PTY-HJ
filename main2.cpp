#include<iostream>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    Stack s;
    int i,j;
   
    cout<<"Checking the parenthesis in argv argunments"<<endl;

    for(i=1;i<argc;i++){
    int correct=1;

      for(j=0;j<strlen(argv[i]);j++){

        if(argv[i][j]=='['||argv[i][j]=='{'){
          s.push(argv[i][j]);
        }

        else{
          if(argv[i][j]==']'||argv[i][j]=='}'){
            //if the stack is empty, it means there is a closing with no opening
            if(s.isEmpty()){
              correct=0;
              break;
            }

            char x=s.pop();

            //check whether the type matches or not for the closing and opening
            if ((argv[i][j] == ']' && x != '[') || (argv[i][j] == '}' && x != '{')) {
            correct = 0;
            break;
          }
        }
      }
    }
    if(!s.isEmpty()){
      correct=0;
      cout<<"Too many opening brackets left"<<endl;
    }

    if (correct == 1)
        cout << "argv " << i << " correct" << endl;
    else
        cout << "argv " << i << " incorrect" << endl;

  }
   return 0;
}
