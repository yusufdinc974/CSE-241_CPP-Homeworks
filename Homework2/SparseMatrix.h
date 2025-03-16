#ifndef _SPARSEMATRIX_
#define _SPARSEMATRIX_

#include <iostream>
#include <vector>
#include "SparseVector.h"



using namespace std;

class SparseMatrix{

    public:

        /* Default Constructure */
        SparseMatrix() : alldata() {};

        /* Contructure that takes string as a input */
        SparseMatrix(string file_name);

        /* Overloading for "+" */
        SparseMatrix operator+(const SparseMatrix &other);

        /* Overloading for "-"  as substruction */
        SparseMatrix operator-( SparseMatrix &other);

        /* Overloading for "*" */
        SparseMatrix operator*(SparseMatrix &other);

        /* Overloading for "-"  as Negation */
        SparseMatrix operator-();

        /* Overloading for "=" "assign" */
        SparseMatrix& operator=(const SparseMatrix &other);

        /* Overloading for "<<" */
        friend ostream& operator<<(ostream &out, const SparseMatrix &other);

        /* makes transpose of the original matrix */
        SparseMatrix transpose();

    private:
        
        vector<Data> alldata;

        /* Private method for reading file */
        vector<Data> readFile(string file_name);

        void sort();

};

#endif