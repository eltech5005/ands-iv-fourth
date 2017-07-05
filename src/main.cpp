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

    char target;                              // Обрабатываемый узел
    char sym;                                 // Временный символ
    int* nodeDistance = new int[MATRIX_SIZE]; // Массив расстояний

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
    
    /* Применение алгоритма Дейкстры и получение массива расстояний */
    cout << " Processing node " << target << ".\n" << endl;
    nodeDistance = processGraph.dejkstra(target);

    /* Вывод результата работы алгоритма */
    cout << " Shorest distances in graph from '" << target << "' to other nodes: \n" << endl << "   "; 
    /* Заголовок таблицы*/
    for (int i=0; i<MATRIX_SIZE; ++i)
        cout << setw(3) << (sym = NODE_NAME_START+i) << " ";
    /* Имя элемента */
    cout << endl << setw(3) << target << " ";
    /* Массив расстояний */
    for (int i=0; i < MATRIX_SIZE; ++i) {
        if (nodeDistance[i] != 16383)
            cout << setw(3) << nodeDistance[i] << " ";
        else
            cout << setw(3) << "inf" << " ";
    }
    cout << endl << "\n Finished.";

    std::cout << "\n Press enter to exit. "; 
    std::cin.get(); 

    return 0;

}
