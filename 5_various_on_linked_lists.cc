#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct node
{
  int val;
  node *next;
};

void insert_last(node *&list, int v);
void insert_first(node *&list, int min);
void print_list(node *list);
void sposta_max(node *&list);
void sposta_min(node *&list);
void remove_node(node *&x, int max);
void concatena_liste(node *&l1, node *l2);

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  node *list = NULL;
  node *l2 = NULL;
  for (int i = 0; i < 10; i++)
  {
    insert_last(list, rand() % 10);
    insert_last(l2, rand() % 10);
  }
  cout << "list1: ";
  print_list(list);
  cout << "list2: ";
  print_list(l2);

  cout << endl
       << "Scrivere una funzione che sposti l’elemento più grande di una lista concatenata nell'ultimo nodo della lista" << endl;
  sposta_max(list);
  print_list(list);
  cout << "Scrivere una funzione che sposti l'elemento più piccolo di una lista concatenata nel primo nodo della lista" << endl;
  sposta_min(l2);
  print_list(l2);
  cout << "Scrivere una funzione che costruisca la lista risultante dalla concatenazione di due liste x e y" << endl;
  concatena_liste(list, l2);
  print_list(list);

  return 0;
}

/* Scrivere una funzione che sposti l’elemento più grande di una
  lista concatenata nell'ultimo nodo della lista.*/
void sposta_max(node *&list)
{
  if (list != NULL)
  {
    int max = list->val;
    node *x = list;
    while (x != NULL)
    {
      if (x->val >= max)
        max = x->val;
      x = x->next;
    }
    remove_node(list, max);
    insert_last(list, max);
  }
}

/* Scrivere una funzione che sposti l'elemento più piccolo di una lista
  concatenata nel primo nodo della lista.*/
void sposta_min(node *&list)
{
  if (list != NULL)
  {
    int min = list->val;
    node *x = list;
    while (x != NULL)
    {
      if (x->val < min)
        min = x->val;
      x = x->next;
    }
    remove_node(list, min);
    insert_first(list, min);
  }
}

/* Scrivere una funzione che costruisca la lista risultante dalla
  concatenazione di due liste x e y.*/
void concatena_liste(node *&l1, node *l2)
{
  if (l1 != NULL && l2 != NULL)
  {
    while (l2 != NULL)
    {
      insert_last(l1, l2->val);
      l2 = l2->next;
    }
  }
}

//-----------------------------------
void insert_last(node *&list, int v)
{
  if (list == NULL)
  {
    list = new node;
    list->val = v;
    list->next = NULL;
  }
  else
  {
    node *x = list;
    while (x->next != NULL)
    {
      x = x->next;
    }
    node *t = new node;
    t->val = v;
    t->next = NULL;
    x->next = t;
  }
}

void remove_node(node *&list, int max)
{
  node *x = list;
  if (list->val == max)
  {
    list = list->next;
    delete x;
  }
  else
  {
    bool stop = false;
    while (x->next != NULL && !stop)
    {
      if (x->next->val == max)
      {
        node *t = x->next;
        x->next = x->next->next;
        delete t;
        stop = true;
      }
      if (x->next != NULL)
        x = x->next;
    }
  }
}
void insert_first(node *&list, int min)
{
  if (list == NULL)
  {
    list = new node;
    list->val = min;
    list->next = NULL;
  }
  else
  {
    node *t = new node;
    t->val = min;
    t->next = list;
    list = t;
  }
}
void print_list(node *list)
{
  while (list != NULL)
  {
    cout << list->val << " ";
    list = list->next;
  }
  cout << endl;
}
