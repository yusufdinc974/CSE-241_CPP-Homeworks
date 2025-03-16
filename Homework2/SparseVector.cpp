#include "SparseVector.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/* Contructure that takes string as a input */
SparseVector::SparseVector(string file_name){

    /* Calling readFİle method to fill the vector from text */
    alldata = readFile(file_name);

}

/* Overloading for "+" */
SparseVector SparseVector::operator+(const SparseVector &other){

    SparseVector vector_result;

    /* checking if there are equal indexes in given vectors */
    for(int i=0; i<alldata.size(); ++i){

        bool flag = true;

        for(int j=0; j<other.alldata.size(); ++j){

            /* If the index of the data's are equal, and if the sum of the values are not zero, then create a result data to pushback to result vector */
            if(alldata.at(i).getIndex() == other.alldata.at(j).getIndex() && alldata.at(i).getValue() + alldata.at(j).getValue() != 0){

                Data data_result(alldata.at(i).getIndex(),alldata.at(i).getValue() + other.alldata.at(j).getValue());
                vector_result.alldata.push_back(data_result);
                flag = false;

            }
        
        }

        /* if flag is true, than there is no equivalent for index i in first vector, so just pushback to result vector */
        if(flag == true){

            vector_result.alldata.push_back(alldata.at(i));

        }
        
    }

    /* Checking if there is a data in 2nd vector that there is no equivalient in first vector so pushback to result vector */
    for(int i=0; i<other.alldata.size(); ++i){

        bool flag2 = true;

        for(int j=0; j< alldata.size(); ++j){

            if(alldata.at(j).getIndex() == other.alldata.at(i).getIndex() && alldata.at(j).getValue() + alldata.at(i).getValue() != 0){

                flag2 = false;

            }

        }

        /* if there is no equivalent, pushback to the result vector */
        if(flag2 == true){

            vector_result.alldata.push_back(other.alldata.at(i));

        }

    }

    vector_result.sort();

    return vector_result;

}

/* Overloading for "-"  as substruction */
SparseVector SparseVector::operator-( SparseVector &other){

    SparseVector vector_result;

    vector_result = *this + (-other); 

    return vector_result;   

}

/* Overloading for "-"  as Negation */
SparseVector SparseVector::operator-(){

    SparseVector vector_result;

    /* setting new value as negative of ex value */
    for(int i=0; i<alldata.size(); ++i){

        Data data(alldata.at(i).getIndex(),-alldata.at(i).getValue());
        vector_result.alldata.push_back(data);
    }

    return vector_result;

}

/* Overloading for "=" "assign" */
SparseVector&  SparseVector::operator=(const SparseVector &other){

    /* if two vectors are same, return this one */
    if(&other == this){

        return *this;

    }

    /* else, assign given to this vector, and return this vector */
    else{

        alldata = other.alldata;
        return *this;
    }

}

/* Overloading for "<<" */
ostream& operator<<(ostream &out, const SparseVector &other){

    /* Displaying all data elements - except zeros - by given text format */
    for(int i=0; i<other.alldata.size(); ++i){

        out << other.alldata.at(i).getIndex() << ":" << other.alldata.at(i).getValue() << " ";

    } 
    return out;

}

/* Dot method for making dot product */
double dot(const SparseVector& first, const SparseVector& second){

    double result = 0;

    /* checking if there are equal indexes in given vectors */
    for(int i=0; i<first.alldata.size(); ++i){

        for(int j=0; j<second.alldata.size(); ++j){

            /* If the index of the data's are equal, make dot product and add to result */
            if(first.alldata.at(i).getIndex() == second.alldata.at(j).getIndex()){

                result = result + first.alldata.at(i).getValue() * second.alldata.at(j).getValue();

            }
        
        }
        
    }   

    return result; 

}

/* Private method for reading file */
vector<Data> SparseVector::readFile(string file_name){

    /* creating file stream object and opening the desired file */
    ifstream file;
    file.open(file_name);

    int index;
    char buffer;
    double value;
    string line;

    vector<Data> vector_result;

    /* reading Data's information */
    while(getline(file, line)){
        
        istringstream linestream(line);

        while(linestream >> index >> buffer >> value){

            Data data_result(index,value);
            vector_result.push_back(data_result);

        }

    }

    return vector_result;

}

vector<Data> SparseVector::sort(){

    /* swapping the values if the index are higher than the left one */
    for(int i=0; i<alldata.size(); ++i){

        for(int j=i+1; j<alldata.size(); ++j){

            if(alldata.at(i).getIndex() > alldata.at(j).getIndex()){


                Data temp(alldata.at(i).getIndex(),alldata.at(i).getValue());
                alldata.at(i) = alldata.at(j);
                alldata.at(j) = temp;

            }

        }

    }

    return alldata;

}