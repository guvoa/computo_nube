#include <omp.h>
#include <iostream>

int main() {
    #pragma omp parallel
    {
        // Cada hilo ejecuta este bloque de código en paralelo
        int id = omp_get_thread_num();
        std::cout << "Hola desde el hilo " << id << std::endl;
    }
    return 0;
}