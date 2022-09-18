#include <iostream>
#include <cstring>

using namespace std;

typedef struct
{

    string nome, disciplina;
    int matricula;
    double nota;

} registro_aluno;

registro_aluno ler_aluno()
{
    registro_aluno a;

    getline(cin, a.nome);
    cin >> a.matricula;
    getline(cin, a.disciplina);
    cin >> a.nota;

    return a;
}

void passou_reprovou(registro_aluno a)
{

    a.nome[sizeof(a.nome) - 1] = '\0'; // remove o '\n'
    a.disciplina[sizeof(a.disciplina) - 1] = '\0';

    if (a.nota >= 7)
        cout << a.nome << a.disciplina;
    else
        cout << a.nome << a.disciplina;
}

int main()
{

    registro_aluno dados = ler_aluno(); // crio a variavel dados pra receber a função
    passou_reprovou(dados);             // passo a variavel dados para a função passou_reprovou
}
