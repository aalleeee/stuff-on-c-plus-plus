using namespace std;
#include <iostream>
#include "tree.h"

static bool empty_t(const tree &t)
{
  return (t == NULL);
}

void init(tree &t)
{
  t = NULL;
}

void deinit(tree &t)
{
  if (!empty_t(t))
  {
    deinit(t->left);
    deinit(t->right);
    delete t;
  }
}

bool insert(tree &t, int v)
{
  bool res;
  if (empty_t(t))
  {
    t = new node;
    if (t == NULL)
      res = false;
    else
    {
      t->val = v;
      t->left = NULL;
      t->right = NULL;
      res = true;
    }
  }
  else if (v <= t->val)
    res = insert(t->left, v);
  else if (v > t->val)
    res = insert(t->right, v);

  return res;
}

tree search(const tree &t, int v)
{
  tree res;
  if (empty_t(t))
    res = NULL;
  else if (v == t->val)
    res = t;
  else if (v < t->val)
    res = search(t->left, v);
  else if (v > t->val)
    res = search(t->right, v);
  return res;
}

void print_linear(const tree &t)
{
  if (!empty_t(t))
  {
    print_linear(t->left);
    cout << t->val << " ";
    print_linear(t->right);
  }
}

void print_indent(const tree &t)
{
  static int space = 0;
  space++;
  if (!empty_t(t))
  {
    print_indent(t->right);
    for (int i = 0; i < space; i++)
      cout << "  ";
    cout << t->val << endl;
    print_indent(t->left);
  }
  space--;
}
