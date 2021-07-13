#include <iostream>
#include <ctime>
using namespace std;

/*
Scrivere un programma che, data una lista concatenata di interi, inverta la lista.
*/

struct node
{
  int val;
  node *next;
};

void insert_last(node *&x, int v)
{
  if (x == NULL)
  {
    x = new node;
    x->val = v;
    x->next = NULL;
  }
  else
  {
    node *s = x;
    while (s->next != NULL)
    {
      s = s->next;
    }
    node *t = new node;
    t->val = v;
    t->next = NULL;
    s->next = t;
  }
}

void insert_first(node *&x, int v)
{
  if (x == NULL)
  {
    x = new node;
    x->val = v;
    x->next = NULL;
  }
  else
  {
    node * t = new node;
    t->val = v;
    t->next = x;
    x = t;
  }
}

void print_list(node *x)
{
  while (x != NULL)
  {
    cout << x->val << "  ";
    x = x->next;
  }
  cout << endl;
}

void reverse_list(node *&x)
{
  node *s = x;
  x = NULL;
  while (s != NULL)
  {
    insert_first(x, s->val);
    s = s->next;
  }
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  node *list = NULL;
  for (int i = 0; i < 11; i++)
    insert_last(list, rand() % 10);
  cout << "................................" << endl;
  print_list(list);
  cout << "................................" << endl;
  reverse_list(list);
  cout << "................................" << endl;
  print_list(list);
  cout << "................................" << endl;
  return 0;
}
