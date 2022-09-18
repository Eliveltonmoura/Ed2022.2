#include <iostream>

using namespace std;
// Implemente a função 'troca'.
void troca(int *a, int *b)
{
   int aux = 0;
   aux = *b;
   *b = *a;
   *a = aux;

   return;
}

int main()
{
   int x, y;
   cin >> x;
   cin >> y;

   // Chame a função 'troca' para trocar os valores de x e y.
   troca(&x, &y);

   cout << x << " " << y << endl;
   return 0;
}