#include <iostream>

const int MAX_SIZE = 100;

class Queue {
private:
  int arr[MAX_SIZE];
  int front;
  int rear;

public:
  Queue();
  void enqueue(int x);
  int dequeue();
  int peek();
  int size();
  bool isEmpty();
  bool isFull();
};

Queue::Queue() {
  front = -1;
  rear = -1;
}

void Queue::enqueue(int x) {
  if (isFull()) {
    std::cout << "Error: queue is full" << std::endl;
    return;
  }
  if (isEmpty()) {
    front = rear = 0;
  } else {
    rear = (rear + 1) % MAX_SIZE;
  }
  arr[rear] = x;
}

int Queue::dequeue() {
  if (isEmpty()) {
    std::cout << "Error: queue is empty" << std::endl;
    return -1;
  }
  int x = arr[front];
  if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    front = (front + 1) % MAX_SIZE;
  }
  return x;
}

int Queue::peek() {
  if (isEmpty()) {
    std::cout << "Error: queue is empty" << std::endl;
    return -1;
  }
  return arr[front];
}

int Queue::size() {
  if (isEmpty()) {
    return 0;
  }
  if (rear >= front) {
    return rear - front + 1;
  }
  return MAX_SIZE - (front - rear - 1);
}

bool Queue::isEmpty() { return front == -1; }

bool Queue::isFull() { return ((rear + 1) % MAX_SIZE) == front; }

int main() {
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;
  return 0;
}
