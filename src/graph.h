/* -----
 * Пользовательская библиотека, содержащая описание класса "граф" для решения задачи №4.
 ----- */

#pragma once

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
                for (int j = 0; j < MATRIX_SIZE; j++)
                    matrix[i][j] = 0;
        };
        ~graph () {};
        void generate ();
        void show ();

};

/* Функция генерации случайного графа */
void graph :: generate () {

    for (int i=0; i<MATRIX_SIZE; ++i)
        for (int j=0; j<MATRIX_SIZE; j++) {
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
        std::cout << setw(2) << (sym = 'A'+i) << " ";
    std::cout << endl;

    /* Выводим матрицу смежности*/
    for (int i=0; i<MATRIX_SIZE; ++i) {
        // Левый столбец букв
        std::cout << setw(2) << (sym = 'A'+i) << " ";

        for (int j=0; j<MATRIX_SIZE; j++)
            std::cout << setw(2) << matrix[i][j] << " ";

        std::cout << endl;

    }

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