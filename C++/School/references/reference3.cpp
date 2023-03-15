#include <assert.h>
#include <iostream>

using namespace std;

struct node {
  int data;
  struct node *nextnode;
};

int main() {
  struct node *headnode = new node;

  int COUNT = 3;

  assert(headnode != NULL);

  headnode->data = 1;
  headnode->nextnode = NULL;

  node *tempnode = headnode;

  for (int i = 2; i <= COUNT; i++) {
    node *newnode = new node;

    assert(newnode != NULL);

    newnode->data = i;
    newnode->nextnode = headnode;

    tempnode->nextnode = newnode;
    tempnode = newnode;
  }

  tempnode = headnode;

  for (int i = 1; i <= COUNT * COUNT + 1; i++) {
    cout << tempnode->data << " ";
    tempnode = tempnode->nextnode;
  }

  cout << endl;

  tempnode = headnode;

  for (int i = 1; i <= COUNT; i++) {
    node *tempnode2 = tempnode->nextnode;
    delete tempnode;
    tempnode = tempnode2;
  }

  cout << "DONE!" << endl;

  return 0;
}