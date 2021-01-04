#include <iostream>

#include "List.h"



int main(){
  using std::cout;
  using std::endl;

  List myList;
  cout << myList.toString() << endl; // (0)                                                                                        
  myList.insert("");
  cout << myList.toString() << endl; // (0)                                                                                        
  myList.insert("a");
  cout << myList.toString() << endl; // (1)A                                                                                       
  myList.insert("BCdB");
  cout << myList.toString() << endl; // (5)BCDBA                                                                                   
  myList.splice("", "");
  cout << myList.toString() << endl; // (5)BCDBA                                                                                   
  myList.splice("B", "C");
  cout << myList.toString() << endl; // (5)CCDCA                                                                                   


  return 0;
}

