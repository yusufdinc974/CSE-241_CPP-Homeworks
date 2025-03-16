#ifndef _SPARSEVECTOR_
#define _SPARSEVECTOR_

#include<iostream>
#include"Data.h"
#include<vector>
#include<string>

using namespace std;

class SparseVector{

    public:

        /* Default Constructure */
        SparseVector() : alldata() {};

        /* Contructure that takes string as a input */
        SparseVector(string file_name);

        /* Overloading for "+" */
        SparseVector operator+(const SparseVector &other);

        /* Overloading for "-"  as substruction */
        SparseVector operator-( SparseVector &other);

        /* Overloading for "-"  as Negation */
        SparseVector operator-();

        /* Overloading for "=" "assign" */
        SparseVector& operator=(const SparseVector &other);

        /* Overloading for "<<" */
        friend ostream& operator<<(ostream &out, const SparseVector &other);

        /* Dot method for making dot product */
        friend double dot(const SparseVector& first, const SparseVector& second);

    private:
        
        vector<Data> alldata;

        /* Private method for reading file */
        vector<Data> readFile(string file_name);

        /* Private method for sorting */
        vector<Data> sort();

};

#endif