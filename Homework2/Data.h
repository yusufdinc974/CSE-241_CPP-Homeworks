#ifndef _DATA_
#define _DATA_

#include <iostream>

class Data{

  public:

    /* Defalut constructre */
    Data() : row(0), index(0), value(0) {};

    /* Constructure that takes three inputs */
    Data(int irow, int iindex, double ivalue) : row(irow), index(iindex), value(ivalue) {};

    /* Constructure that takes two inputs */
    Data(int iindex, double ivalue) : row(0), index(iindex), value(ivalue) {};

    /* Getter method for row */
    int getRow() const;

    /* Setter method for row */
    void setRow(int row);

    /* Getter method for index */
    int getIndex() const;

    /* Setter method for index */
    void setIndex(int index);

    /* Getter method for value */
    double getValue() const;

    /* Setter method for value */
    void setValue(double value);

  private:  

    int row;
    int index;
    double value;

};

#endif