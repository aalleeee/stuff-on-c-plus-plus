#ifndef TREE_H
#define TREE_H

using namespace std;
#include <iostream>

struct node;

typedef node *tree;

struct node
{
  int val;
  tree left;
  tree right;
};

void init(tree &t);
void deinit(tree &t);
bool insert(tree &t, int v);
tree search(const tree &t, int v);
void print_linear(const tree &t);
void print_indent(const tree &t);

#endif
