#ifndef LINKNODE_H
#define LINKNODE_H

#include <string>


class LinkNode {
  friend class List;
 public:
  LinkNode() { prev = 0; next = 0; }

 private:
  LinkNode *prev, *next;
  std::string data;


};


#endif
