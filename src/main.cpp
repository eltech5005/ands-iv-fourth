/* -----
 * Вариант: 5
 * Задание: Подсчёт расстояний от произвольной вершины до всех остальных вершин в ориентированном ненагруженном графе
 ----- */

#define MATRIX_SIZE 5

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <src/graph.h>

using namespace std;

int main (int argc, char **argv) {

    srand(time(NULL));

    /* Генерация случайного графа */
    graph processGraph;
    processGraph.generate();
    
    /* Вывод матрицы смежности графа на экран */
    cout << "\n Generated adjacency matrix:";
    processGraph.show();
    
    std::cout << "\n Press enter to continue... "; 
    std::cin.get(); 

    return 0;

}
