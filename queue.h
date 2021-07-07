#ifndef QUEUE_H
#define QUEUE_H

using namespace std;
#include <iostream>

struct node
{
  char c;
  node *next;
};

struct queue
{
  node *head;
  node *tail;
};

void init(queue &q);
void deinit(queue &q);
bool enqueue(queue &q, char c);
bool dequeue(queue &q);
bool first(const queue &q, char &c);
void print(const queue &q);

#endif
