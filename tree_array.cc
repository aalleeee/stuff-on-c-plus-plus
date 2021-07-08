using namespace std;
#include <iostream>
#include "tree_array.h"

const int MAX_DIM = 100;

static tree left(const tree &t)
{
  tree res;
  res.pos = 2 * t.pos + 1;
  res.arr = t.arr;
  return res;
}

static tree right(const tree &t)
{
  tree res;
  res.pos = 2 * t.pos + 2;
  res.arr = t.arr;
  return res;
}

static bool empty_t(const tree &t)
{
  return (t.arr[t.pos] == -1);
}

void init(tree &t)
{
  t.pos = 0;
  t.arr = new int[MAX_DIM];
  for (int i = 0; i < MAX_DIM; i++)
    t.arr[i] = -1;
}

void deinit(tree &t)
{
  delete[] t.arr;
}

bool insert(tree &t, int v)
{
  bool res;
  tree tmp;
  if (t.pos >= MAX_DIM)
    res = false;
  else if (empty_t(t))
  {
    t.arr[t.pos] = v;
    res = true;
  }
  else if (v <= t.arr[t.pos])
  {
    tmp = left(t);
    res = insert(tmp, v);
  }
  else if (v > t.arr[t.pos])
  {
    tmp = right(t);
    res = insert(tmp, v);
  }

  return res;
}

tree cerca(const tree &t, int v)
{
  tree res;
  if (empty_t(t))
    res.pos = -1; //tofix
  else if (v == t.arr[t.pos])
    res = t;
  else if (v < t.arr[t.pos])
    res = cerca(left(t), v);
  else if (v > t.arr[t.pos])
    res = cerca(right(t), v);
  return res;
}

void print_linear(const tree &t)
{
  if (!empty_t(t))
  {
    print_linear(left(t));
    cout << t.arr[t.pos] << " ";
    print_linear(right(t));
  }
}

void print_indent(const tree &t)
{
  static int space = 0;
  space++;
  if (!empty_t(t))
  {
    print_indent(right(t));
    for (int i = 0; i < space; i++)
      cout << "  ";
    cout << t.arr[t.pos] << endl;
    print_indent(left(t));
  }
  space--;
}
