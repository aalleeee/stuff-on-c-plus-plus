using namespace std;
#include <iostream>
#include "queue.h"

static bool q_empty(const queue &q)
{
  return (q.head == NULL);
}

void init(queue &q)
{
  q.head = NULL;
}

void deinit(queue &q)
{
  while (!q_empty(q))
    dequeue(q);
}

bool enqueue(queue &q, char c)
{
  bool res;
  node *np = new node;
  if (np == NULL)
    res = false;
  else
  {
    np->c = c;
    np->next = NULL;
    if (q_empty(q))
      q.head = np;
    else
      q.tail->next = np;

    q.tail = np;
    res = true;
  }
  return res;
}

bool dequeue(queue &q)
{
  bool res;
  if (q_empty(q))
    res = false;
  else
  {
    node *first = q.head;
    q.head = q.head->next;
    delete first;
    res = true;
  }
  return res;
}

bool first(const queue &q, char &c)
{
  bool res;
  if (q_empty(q))
    res = false;
  else
  {
    c = q.head->c;
    res = true;
  }
  return res;
}

void print(const queue &q)
{
  if (!q_empty(q))
  {
    node *first = q.head;
    while (first != NULL)
    {
      cout << first->c << "  ";
      first = first->next;
    }
    cout << endl;
  }
}
