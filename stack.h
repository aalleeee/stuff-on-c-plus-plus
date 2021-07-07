#ifndef STRUCT_STACK_H
#define STRUCT_STACK_H

using namespace std;
#include <iostream>

struct node
{
  char c;
  node *next;
};

typedef node * stack;

void init(stack &s);
void deinit(stack &s);
bool push(stack &s, char c);
bool pop(stack &s);
bool top(const stack &s, char &c);
void print(const stack &s);

#endif
