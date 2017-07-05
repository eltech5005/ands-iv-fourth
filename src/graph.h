/* -----
 * Пользовательская библиотека, содержащая описание класса "граф" для решения задачи №4.
 ----- */

#pragma once

/* Количество узлов */
#ifndef MATRIX_SIZE
    #define MATRIX_SIZE 5
#endif

/* Начало именования узлов */
#ifndef NODE_NAME_START
    #define NODE_NAME_START 'A'
#endif

#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

/* Описание класса "граф" */
class graph {

    unsigned int matrix[MATRIX_SIZE][MATRIX_SIZE];
    
    public:
        graph () { 
            for (int i = 0; i < MATRIX_SIZE; ++i)
                for (int j = 0; j < MATRIX_SIZE; ++j)
                    matrix[i][j] = 0;
        };
        ~graph () {};
        void generate ();
        void dejkstra (char nodeName);
        void show ();

};

/* Функция генерации случайного графа */
void graph :: generate () {

    for (int i=0; i<MATRIX_SIZE; ++i)
        for (int j=0; j<MATRIX_SIZE; ++j) {
            if ((i != j) && (rand() % 2))
                matrix[i][j] = rand() % 100;
        }

}

/* Функция вывода матрицы смежности графа */
void graph :: show () {

    char sym;

    std::cout << endl << "   ";

    /* Выводим заголовок матрицы смежности */
    for (int i=0; i<MATRIX_SIZE; ++i)
        std::cout << setw(2) << (sym = NODE_NAME_START+i) << " ";
    std::cout << endl;

    /* Выводим матрицу смежности*/
    for (int i=0; i<MATRIX_SIZE; ++i) {
        // Левый столбец букв
        std::cout << setw(2) << (sym = NODE_NAME_START+i) << " ";

        for (int j=0; j<MATRIX_SIZE; j++)
            std::cout << setw(2) << matrix[i][j] << " ";

        std::cout << endl;

    }

}

/* Функция применения алгоритма Дейкстры к графу */
void graph :: dejkstra (char nodeName) {

    int nodeDistance[MATRIX_SIZE];
    
    nodeName=nodeName-NODE_NAME_START; // Приводим имя узла к числу
    nodeDistance[nodeName] = 0;        // Кратчайшее расстояние до самого себя = 0

    /* Массив флагов найденности расстояний до вершин */
    bool used[MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; ++i)
        used[i] = false;

    /* Для каждой вершины орграфа */
    for (int iteration = 0; iteration < MATRIX_SIZE; ++iteration) {

        int node = -1;              // Номер обрабатываемой вершины
        int nodeDistanceV = 16383;  // Расстояние по умолчанию

        /* Выбираем вершину, кратчайшее расстояние до которой еще не найдено */
        for (int i = 0; i < MATRIX_SIZE; ++i) {

            if (used[i])
                continue;

            if (nodeDistanceV < nodeDistance[i])
                continue;

            node = i;
            nodeDistanceV = nodeDistance[i];
        }

        /* Для всех ребёр */
        for (int i = 0; i < matrix[node][MATRIX_SIZE]; ++i) {

            if (matrix[node][i] != 0) {

                int nodeTwo = i;
                int nodeTwoWeight = matrix[node][i];

                if (nodeDistance[node] + nodeTwoWeight < nodeDistance[nodeTwo]) {
                    nodeDistance[nodeTwo] = nodeDistance[node] + nodeTwoWeight;
                }
                
            }
        }

        // Помечаем вершину v просмотренной, до нее найдено кратчайшее расстояние
        used[node] = true;

    }
    
    cout <<"Result: \n\n";
    for (int i=0;i<MATRIX_SIZE;++i)
        cout << nodeDistance[i] << " ";
    
}

//void GR :: Make(int G[ MaxV ][ MaxV ]) { //матрица → списки смежности
//    int ls = 0, f;
//    n = m = 0;
//    for (int i=0; i<MaxV; i++) {
//        LIST[ i ] = 0;
//        G[ i ][ i ] = 0;
//        f = 0;
//        cout << '\n' << Ch(i) << ": ";
//        for (int j = 0; j < MaxV; j++)
//            if(G[ i ][ j ]) { 
//                f++;
//                Node *v = new Node;
//                v->d = j; v->next = LIST[ i ]; LIST[ i ] = v;
//                cout << Ch( j );
//            } else 
//                cout << "-";
//        if( f )
//            n++;
//        m += f;
//        if (!(( ++ls ) % 10));
//    }
//    cout << '\n' << "| V |=" << n << " | E |=" << m/2;
//}