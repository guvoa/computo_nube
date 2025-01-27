#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float *d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int pedazos = chunk;

    // Inicialización de los arreglos a y b
    for (int i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }

    // Aquí no necesitamos declarar i como 'private(i)' porque ya está declarada en el for
    #pragma omp parallel for shared(a, b, c, pedazos) schedule(static, pedazos)
    for (int i = 0; i < N; i++) // La variable i ya está declarada aquí
    {
        c[i] = a[i] + b[i];
    }

    // Imprimir los resultados
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: ";
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: ";
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: ";
    imprimeArreglo(c);

    return 0;
}

void imprimeArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++)
    {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}