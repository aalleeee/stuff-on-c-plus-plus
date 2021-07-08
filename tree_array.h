#ifndef TREE_ARRAY_H
#define TREE_ARRAY_H

struct tree
{
  int pos;
  int *arr;
};

void init(tree &t);
void deinit(tree &t);
bool insert(tree &t, int v);
tree cerca(const tree &t, int v);
void print_linear(const tree &t);
void print_indent(const tree &t);

#endif
