#include "Data.h"
#include <iostream>

using namespace std;

/* Getter method for row */
int Data::getRow() const{
    
    return row;

}

/* Setter method for row */
void Data::setRow(int row){

    this->row = row;

}

/* Getter method for index */
int Data::getIndex() const{

    return index;

}

/* Setter method for index */
void Data::setIndex(int index){

    this->index = index;

}

/* Getter method for value */
double Data::getValue() const{

    return value;

}

/* Setter method for value */
void Data::setValue(double value){

    this->value = value;

}