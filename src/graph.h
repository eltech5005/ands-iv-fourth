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

    int matrix[MATRIX_SIZE][MATRIX_SIZE];

    public:
        graph () { 
            for (int i = 0; i < MATRIX_SIZE; ++i)
                for (int j = 0; j < MATRIX_SIZE; ++j)
                    matrix[i][j] = 0;
        };
        ~graph () {};
        void generate ();
        void show ();
        int* dejkstra (char nodeName);

};

/* Функция генерации случайного графа */
void graph :: generate () {

    for (int i=0; i<MATRIX_SIZE; ++i)
        for (int j=0; j<MATRIX_SIZE; ++j) {
            if ((i != j) && (rand() % 2))
                matrix[i][j] = abs(rand() % 100);
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
int* graph :: dejkstra (char nodeName) {

    int minindex, min;

    /* Матрица расстояний */
    int* nodeDistance = new int[MATRIX_SIZE];
    for (int i=0; i < MATRIX_SIZE; ++i)
        nodeDistance[i] = 16383;

    /* Массив флагов найденности расстояний до вершин */
    int used[MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; ++i)
        used[i] = 1;

    nodeName=nodeName-NODE_NAME_START; // Приводим имя узла к числу
    nodeDistance[nodeName] = 0;        // Кратчайшее расстояние до самого себя = 0

    do {
        minindex = 10000; // Наименьший номер элемента
        min = 10000;      // Наименьший вес

        for (int i = 0; i < MATRIX_SIZE; ++i) { 
            /* Если вершина ещё не пройдена и вес меньше найденного минимального */
            if ( (used[i] == 1) && (nodeDistance[i] < min) ) {
                min = nodeDistance[i]; // Минимальный вес - найденный
                minindex = i;          // Номер элемента для построения маршрута
            }
        }
        
        /* Добавляем найденный минимальный вес к текущему весу вершины
         * и сравниваем с текущим минимальным весом вершины */
        if (minindex != 10000) {

            for (int i = 0; i<MATRIX_SIZE; ++i) {
                /* Если ребро существует */
                if (matrix[minindex][i] > 0) {

                    int temp = min + matrix[minindex][i];
                    if (temp < nodeDistance[i])
                        nodeDistance[i] = temp;
                }
            }
            used[minindex] = 0;
        }

    } while (minindex < 10000);

    return nodeDistance;

}