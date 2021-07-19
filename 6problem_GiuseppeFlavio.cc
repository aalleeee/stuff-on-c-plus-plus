#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
  int val;
  node *next;
};

void print_list(node *list);

void problemGiuseppeFlavio(int n, int m);

int main(int argc, char const *argv[])
{
  problemGiuseppeFlavio(atoi(argv[1]), atoi(argv[2]));
  return 0;
}

void problemGiuseppeFlavio(int n, int m)
{
  //A circular list of only one node is built for person 1
  node *list = new node;
  list->val = 1;
  list->next = list;

  //The other N-1 nodes are inserted one at a time for the other people
  node *x = list;
  int i = 2;
  while (i <= n)
  {
    node *t = new node;
    t->val = i;
    t->next = list;
    x->next = t;
    x = x->next;
    i++;
  }

  //The result is a circle with nodes from 1 to N
  print_list(list);

  node *first = list;

  if (m == 1 || m == 0)
  {
    for (int i = 1; i < n; i++)
      first = first->next;
  }
  else
  {
    //loop to repeat the approach until only one node is left
    for (int i = 0; i < n - 1; i++)
    {
      //take the first node of the circle and skip M-1 nodes
      for (int i = 1; i < m - 1; i++)
        first = first->next;

      //remove node M by updating the links to maintain the circular structure
      if (first->next != NULL)
      {
        node *del = first->next;
        cout << "*** Removing " << del->val << " ..." << endl;
        first->next = first->next->next;
        delete del;
        first = first->next;
      }
    }
  }

  //the ultimate content will give the result
  cout << "---------------" << endl;
  cout << "Result is " << first->val << endl;
  cout << "---------------" << endl;
}

void print_list(node *list)
{
  cout << list->val << "  ";
  for (node *x = list->next; x != list; x = x->next)
    cout << x->val << "  ";
  cout << endl;
}
