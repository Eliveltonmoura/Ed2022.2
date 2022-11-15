#ifndef NODE__H
#define NODE__H

template <typename T>
struct Node
{

  T volue;
  Node *next;

  Node(const T &val, Node *nxt)
  {
    value = val;
    nex = nxt;
  }
  ~Node {
    delete next;
  }
};

#endif
