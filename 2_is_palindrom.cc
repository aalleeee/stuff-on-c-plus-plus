using namespace std;
#include "stack.h"
#include <iostream>

bool s_empty(const stack &s)
{
  return (s == NULL);
}

void init(stack &s)
{
  s = NULL;
}

void deinit(stack &s)
{
  while (!s_empty(s))
    pop(s);
}

bool push(stack &s, char c)
{
  bool res;
  node *np = new node;
  if (np == NULL)
    res = false;
  else
  {
    np->c = c;
    np->next = s;
    s = np;
    res = true;
  }
  return res;
}

bool pop(stack &s)
{
  bool res;
  if (s_empty(s))
    res = false;
  else
  {
    node *np = s;
    s = s->next;
    delete np;
    res = true;
  }
  return res;
}

bool top(const stack &s, char &c)
{
  bool res;
  if (s_empty(s))
    res = false;
  else
  {
    c = s->c;
    res = true;
  }
  return res;
}

void print(const stack &s)
{
  if (!s_empty(s))
  {
    node *np = s;
    while (np != NULL)
    {
      cout << np->c << "  ";
      np = np->next;
    }
    cout << endl;
  }
}
