#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
	const Vector lista_modelo;
	cout << lista_modelo.capacity() << endl;

	Vector lista_qualquer;
	cout << lista_qualquer.capacity() << endl;
}