#ifndef LIST_H
#define LIST_H
#include <string>
#include "LinkNode.h"


using std::string;

class List {

 public:
  List() { size = 0; head = 0; tail = 0; }
  //work on destructor                                                                                                             
  ~List();
  int getSize() { return size; }
  std::string toString();
  void insert(std::string s);
  void splice(std::string find, std::string replace);
  bool isEmpty() { return head == 0; }
  void print();
 private:
  LinkNode *head, *tail;
  int size;
  void findAndDelete(std::string find);
  void insertFront(std::string s);
  void insertBack(std::string s);
  std::string toUpper(std::string s);
};

#endif
