#include <iostream>
#include "stack.h"
using namespace std;

// NOTE : ASSUMING CORRECT STRING: no check about it
int main(int argc, char const *argv[])
{
  stack s;
  char exp[100];

  init(s);
  cout << "Expression:: ";
  cin >> exp;
  deinit(s);

  for (int i = 0; exp[i] != '\0'; i++)
    push(s, exp[i]);

  print(s);

  bool stop = false;
  char n1, n2, n3, op, op2;
  // NOTE : ASSUMING CORRECT STRING: no check about it
  while (!stop)
  {
    top(s, n1);
    pop(s);
    if (top(s, op))
    {
      pop(s);
      top(s, n2);
      pop(s);

      if (op == '*') // ... n2 * n1
      {
        int n = (n1 - '0') * (n2 - '0');
        push(s, (n + '0'));
      }
      else if (op == '+') // ... n2 + n1
      {
        if (top(s, op2))
        {
          if (op2 == '*') // ... * n2 + n1 -> need to do * before +
          {
            pop(s);
            top(s, n3);
            pop(s);
            int n = (n2 - '0') * (n3 - '0');
            push(s, (n + '0'));
            push(s, op);
            push(s, n1);
          }
          else if (op2 == '+') // ... + n2 + n1 -> just add
          {
            int n = (n1 - '0') + (n2 - '0');
            push(s, (n + '0'));
          }
        }
        else
        {
          int n = (n1 - '0') + (n2 - '0'); // nothing before n2 + n1 -> just add
          push(s, (n + '0'));
        }
      }
    }
    else
    {
      push(s, n1);
      stop = true;
    }
  }
  print(s);
  // NOTE : ASSUMING CORRECT STRING: no check about it

  return 0;
}
