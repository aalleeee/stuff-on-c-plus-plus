using namespace std;
#include <iostream>

// ! text on foot ! (IT)

//convert
long long int convert(char *source, int dim);
//convert

int get_power(int n, int b,int exp);
int convert_wrapped(char *arr, int i, int exp);
int get_len(char *arr, int i);

bool check_base(const char n, const int base)
{
  switch (base)
  {
  case 2:
    return ((n == '0') || (n == '1'));
  case 4:
    return ((n >= '0') && (n <= '3'));
  case 8:
    return ((n >= '0') && (n <= '8'));
  case 16:
    return (((n >= '0') && (n <= '9')) ||
            ((n >= 'A') && (n <= 'D')) ||
            ((n >= 'a') && (n <= 'd')));
  default:
    return false;
  }
}

bool controlla(char *num, const int maxdim, const unsigned int base = 4)
{
  for (int i = 0; ((i < maxdim) && (num[i] != '\0')); i++)
  {
    if (num[i] >= 'A' && num[i] <= 'Z')
    {
      num[i] = 'a' + (num[i] - 'A');
    }
    if (!check_base(num[i], base))
      return false;
  }
  return true;
}

int main(int argc, char const *argv[])
{
  const unsigned int maxdim = 100;
  char number[maxdim];

  cout << "Inserire numero: ";
  cin >> number;
  if (!controlla(number, maxdim))
  {
    cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
    exit(1);
  }

  long long int decimal = convert(number, maxdim);

  cout << "The converted number is: " << decimal << endl;
  return 0;
}

// Inserire qui sotto la definizione della funzione convert
long long int convert(char *source, int dim)
{
  int d = get_len(source, 0);
  long long int n = convert_wrapped(source, d - 1, 0);
  return n;
}

//convert
int convert_wrapped(char *arr, int i, int exp)
{
  if (i >= 0)
  {
    if (arr[i] == '\0')  // redaundant ?
      return 0;
    else
    {
      int n;
      if (arr[i] == '0')
        n = 0;
      else if (arr[i] == '1')
        n = 1;
      else
      {
        cout << "Digit error" << endl;
        exit(1);
      }
      return n * get_power(n, 2, exp) + convert_wrapped(arr, i - 1, exp + 1);
    }
  }
  else
    return 0;
}
//convert

int get_power(int n, int b, int exp)
{
  if (exp == 0)
    return 1;
  else
    return b * get_power(n, b,exp - 1);
}

int get_len(char *arr, int i)
{
  if (arr[i] == '\0')
    return 0;
  else
    return 1 + get_len(arr, i + 1);
}



/* TEXT (IT) 
La conversione di un numero in base B in decimale è la trasformazione di un numero in base
B (sistema in base B, e.g. 2) in un numero in base 10 (sistema decimale). Essendo due sistemi
numerici posizionali per convertire un numero in base B in un numero decimale è sufficiente
moltiplicare ogni cifra di del numero dndn−1...d1d0 in base B per la potenza B corrispondente
alla sua posizione (n), ovvero il numero decimale corrispondente è: dn ∗Bn +dn−1 ∗Bn−1 +...+
d1 ∗ B1 + d
0 ∗ B0
.
Scrivere nel file esercizio2.cc la dichiarazione e la definizione della funzione ricorsiva
converti che prende come argomento un array di char source, la dimensione massima dell’array
source di tipo int, e assumendo B = 2 e che gli elementi dell’array siano i soli caratteri
’0’,’1’ o ’\0’ per indicare la fine dell’array, ritorni il numero intero (di tipo long long int) che
rappresenta la conversione in decimale del numero in base B rappresentato nell’array di caratteri
source sfruttando il metodo sopra descritto.
Il programma per essere eseguito legge da standard input una sequenza di caratteri terminata
da newline e produce in output il numero decimale convertito dalla base specificata.

*/
