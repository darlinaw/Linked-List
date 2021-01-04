#include <iostream>
#include <string>
#include <cctype>
#include "List.h"


using std::string;


List::~List(){ //destructor                                                                                                        
  LinkNode *temp = head;
  while(head){
    temp = head;
    head = head->next;
    delete temp; temp = 0;
  }

}




string List::toUpper(string s){ //uppercases input string                                                                          
  for(int i = 0; i < s.length(); i++){
    s[i] = toupper(s[i]);
  }
  return s;
}



void List::insert(string s){ //insert function                                                                                     
  s = toUpper(s);
  if(s.length() > 0){
    for(int i = s.length() - 1; i >= 0; i--){
      insertFront(s.substr(i, 1));
      size++;
    }
  }
}



void List::insertFront(string s){ //inserts single node from front, containing string of length 1                                  
  if(s.length() != 1) return;
  LinkNode *temp = new LinkNode();
  temp->data = s;
  if(isEmpty()){
    head = tail = temp;
    return;
  }
  temp->next = head;
  head->prev = temp;
  head = temp;

}




void List::insertBack(string s){ //same as insertFront, but from back instead                                                      
  if(s.length() != 1) return;
  LinkNode *temp = new LinkNode();
  temp->data = s;
  if(isEmpty()){
    head = tail = temp;
    return;
  }

  temp->prev = tail;
  tail->next = temp;
  tail = temp;

}




string List::toString(){ //converts list to a string                                                                               
  string toString = "";
  LinkNode *temp = head;
  toString = "(" + std::to_string(size) + ")";
  while(temp){
    toString += temp->data;
    temp = temp->next;

  }

  return toString;
}




void List::print(){ //prints list in correct format                                                                                
  std::cout << toString();

}




void List::findAndDelete(string find){ //find and delete function                                                                  

  LinkNode *before = head;
  LinkNode *temp = head->next;


  while(temp != 0){

    if(head->data == find){ //if in first node                                                                                     
      head = temp;
      head->prev = 0;
      delete before; before = temp;
      size--;
    }


    else if(temp->next == 0 && temp->data == find){ //if in last node                                                              
      tail = before;
      before->next = 0;
      delete temp; temp = 0;
      size--;
      return;
    }


 else if(temp->data == find){ //if find in middle node                                                                          
      //std::cout << "in middle" << std::endl;                                                                                     

      before->next = temp->next;
      temp->next->prev = temp->prev;
      delete temp; temp = before;
      //this->print();                                                                                                             
      //std::cout << std::endl;                                                                                                    
      size--;
    }

    //updates pointers                                                                                                             
    before = temp;
    temp = temp->next;

  }

  if(tail == head && head->data == find && head != 0){ //if only one element                                                       
    head = 0;
    delete tail; tail =0;
    size = 0;
    return;
  }
  
  
  
  //return if not found                                                                                                            
  if(!temp) return;


}





void List::splice(string find, string replace){ //splice function                                                                  
  find = toUpper(find);
  replace = toUpper(replace);

  if(isEmpty()) return; //return is list is empty                                                                                  
  if(find.length() != 1) return; //return is find string is not one character                                                      

  if(replace.length() == 0){
    findAndDelete(find); //case where replace is empty                                                                             
    return;
  }


  //case if there is only one node in list                                                                                         
  if(head == tail && head->data == find){
    tail == 0;
    delete head; head = 0;
    size--;
    for(int i = 0; i < replace.length(); i++){
      insertBack(replace.substr(i, 1));
      size++;
    }
    return;
  }


 LinkNode *before = head;
  LinkNode *temp = head->next;

  //case if find is in first node                                                                                                  
  if(head->data == find){
    head = temp;
    head->prev = 0;
    delete before; before = temp;
    size--;
    for(int i = replace.length() - 1; i >= 0; i--){
      insertFront(replace.substr(i, 1));
      size++;
    }
  }

  //traverse through list, stop at last node                                                                                       
  while(temp != 0 && temp->next != 0){

    //if find in middle                                                                                                            
    if(temp->data == find){
      temp->data = replace.substr(0, 1);
      for(int i = 1; i < replace.length(); i++){
        LinkNode *insert = new LinkNode();
        insert->data = replace.substr(i, 1);
        insert->next = temp->next;
        insert->prev = temp;
        temp->next = insert;
        temp->next->prev = insert;
        before = temp;
        temp = insert;
        size++;
      }
    }




    before = temp;
    temp = temp->next;

 }

  //return if not found                                                                                                            
  if(!temp) return;

  //case if find is in last node                                                                                                   
  if(temp->next == 0 && temp->data == find){
    tail = before;
    before->next = 0;
    delete temp; temp = 0;
    size--;
    for(int i = 0; i < replace.length(); i++){
      //std::cout << "i: " << i << " replace[i] " << replace[i] << std::endl;                                                      
      insertBack(replace.substr(i, 1));
      size++;
 }
    return;
  }


}
