#include <iostream>
using namespace std;

struct node {

  int data;

  node *next;
};

int main(void) {

  int i = 0;

  int len = 21;

  node *head = new node;

  node *body = new node;

  node *tail = new node;

  head->data = 1;

  head->next = body;

  body->data = 2;

  body->next = tail;

  tail->data = 3;

  tail->next = head;

  while (i < len) {

    cout << head->data;

    head = head->next;

    if (i != len - 1) {

      cout << "->";
    }

    i++;
  }

  delete head;

  delete body;

  delete tail;

  return 0;
}