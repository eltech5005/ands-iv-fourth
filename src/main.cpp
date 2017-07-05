/* -----
 * Вариант: 5
 * Задание: Подсчёт расстояний от произвольной вершины до всех остальных вершин в ориентированном ненагруженном графе
 ----- */

/* Количество узлов */
#define MATRIX_SIZE 5

/* Начало именования узлов */
#define NODE_NAME_START 'a'

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <src/graph.h>

using namespace std;

int main (int argc, char **argv) {

    srand(time(NULL));

    char target;

    /* Генерация случайного графа */
    graph processGraph;
    processGraph.generate();
    
    /* Вывод матрицы смежности графа на экран */
    cout << "\n Generated adjacency matrix:";
    processGraph.show();
    
    /* Ввод имени узла для расчёта */
    cout << "\n Input node name to dejkstra: ";
    cin >> target;
    
    /* Проверка имени узла*/
    if ((target-NODE_NAME_START >= MATRIX_SIZE) || (target - NODE_NAME_START < 0)) {
        cout << " Given node does not exist. Will now exit. \n";
        return 1;
    }
    cout << " Processing node " << target << ".\n" << endl;
    
    processGraph.dejkstra(target);
    
    std::cout << "\n Press enter to continue... "; 
    std::cin.get(); 

    return 0;

}
