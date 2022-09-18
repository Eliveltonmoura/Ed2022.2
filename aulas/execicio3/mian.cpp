#include <iostream>

using namespace std;
struct ponto
{
    float x;
    float y;
};

void troca(ponto *p1, ponto *p2)
{

    ponto aux = *p1;
    *p1 = *p2;
    *p2 = aux;

       // float aux = p1 > x;
    // p1->p2->x;
    // p2->x = aux;

    // aux = p1 > y;
    // p1->p2->x;
    // p2->x = aux;
}

int main()
{
    ponto p{9, 8}, q{6, 5};
    troca(&p, &q);

    cout << "P =(" << p.x << "," << p.y << ")" << endl;
    cout << "Q =(" << q.x << "," << q.y << ")" << endl;
}