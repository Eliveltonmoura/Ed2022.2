#include <iostream> // std::cout, std::fixed
#include <iomanip>  // std::setprecision

typedef struct
{
    float nota[3];
    float media{};
} aluno;

// Recebe um aluno passado por referência, e preenche o campo 'media' com a
// média das 3 notas do aluno.
using namespace std;
void calcula_media(aluno *a)
{
    for (int i = 0; i < 3; i++)
    {
        a->media += (a->nota[i]) / 3;
    }
}

int main()
{
    aluno a;
    int i;
    for (i = 0; i < 3; i++)
    {
        cin >> a.nota[i];
    }

    // Chame a função 'calcula_media' passando o aluno 'a' por referência.
    calcula_media(&a);

    cout << fixed;
    cout << setprecision(1) << a.media;

    return 0;
}