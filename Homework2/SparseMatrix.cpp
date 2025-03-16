#include<iostream>
#include<fstream>
#include "SparseMatrix.h"
#include<sstream>

using namespace std;

/* Contructure that takes string as a input */
SparseMatrix::SparseMatrix(string file_name){

    /* Calling readFİle method to fill the vector from text */
    alldata = readFile(file_name);

}

SparseMatrix SparseMatrix::operator+(const SparseMatrix &other){

    SparseMatrix matrix_result;

    /* checking if there are equal indexes and rows in given vectors */
    for(int i=0; i<alldata.size(); ++i){

        bool flag = true;

        for(int j=i+1; j<other.alldata.size(); ++j){

            /* If the row and index of the data's are equal, and if the sum of the values are not zero, then create a result data to pushback to result matrix */
            if(alldata.at(i).getRow() == other.alldata.at(j).getRow() && alldata.at(i).getIndex() == other.alldata.at(j).getIndex() && alldata.at(i).getValue() + other.alldata.at(j).getValue() != 0){

                Data data_result(alldata.at(i).getRow(),alldata.at(i).getIndex(),alldata.at(i).getValue() + other.alldata.at(j).getValue());
                matrix_result.alldata.push_back(data_result);
                flag = false;

            }
        
        }

        /* if flag is true, than there is no equivalent for index i in first vector, so just pushback to result vector */
        if(flag == true){

            matrix_result.alldata.push_back(alldata.at(i));

        }
        
    }

    /* Checking if there is a data in 2nd vector that there is no equivalient in first vector so pushback to result vector */
    for(int i=0; i<other.alldata.size(); ++i){

        bool flag2 = true;

        for(int j=0; j< alldata.size(); ++j){

            if(alldata.at(j).getRow() == other.alldata.at(i).getRow() && alldata.at(j).getIndex() == other.alldata.at(i).getIndex() && alldata.at(j).getValue() + alldata.at(i).getValue() != 0){

                flag2 = false;

            }

        }

        /* if there is no equivalent, pushback to the result vector */
        if(flag2 == true){

            matrix_result.alldata.push_back(other.alldata.at(i));

        }

    }

    return matrix_result;

}

SparseMatrix SparseMatrix::operator-( SparseMatrix &other){
    
    SparseMatrix matrix_result;

    matrix_result = *this + (-other);

    return matrix_result;
}

/* Overloading for "-"  as Negation */
SparseMatrix SparseMatrix::operator-(){

    SparseMatrix matrix_result;

    /* setting new value as negative of ex value */
    for(int i=0; i<alldata.size(); ++i){

        Data data(alldata.at(i).getRow(),alldata.at(i).getIndex(),-alldata.at(i).getValue());
        matrix_result.alldata.push_back(data);    }

    return matrix_result;

}

/* Overloading for "=" "assign" */
SparseMatrix&  SparseMatrix::operator=(const SparseMatrix &other){

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

ostream& operator<<(ostream &out, const SparseMatrix &other){

    int ex_row;

    /* Displaying all data elements - except zeros - by given text format */
    for(int i=0; i<other.alldata.size(); ++i){

        if((ex_row != other.alldata.at(i).getRow()) || i == 0){

            out << endl << other.alldata.at(i).getRow() << " " << other.alldata.at(i).getIndex() << ":" << other.alldata.at(i).getValue() << " ";

        }
        
        else{

            out << other.alldata.at(i).getIndex() << ":" << other.alldata.at(i).getValue() << " ";

        }

        ex_row = other.alldata.at(i).getRow();
    } 

    return out;

}

SparseMatrix SparseMatrix::operator*(SparseMatrix &other) {
    // Check if matrix multiplication is defined
    if (alldata.empty() || other.alldata.empty()) {
        // Return empty matrix if any matrix is empty
        return SparseMatrix();
    }

    // Check if number of columns in *this matches number of rows in other
    int num_cols_this = 0;
    int num_rows_other = 0;
    for (const auto &data : alldata) {
        num_cols_this = max(num_cols_this, data.getIndex() + 1);
    }
    for (const auto &data : other.alldata) {
        num_rows_other = max(num_rows_other, data.getRow() + 1);
    }
    if (num_cols_this != num_rows_other) {
        // Return empty matrix if multiplication is not defined
        return SparseMatrix();
    }

    // Initialize the result matrix
    SparseMatrix result;

    // Transpose the other matrix for efficient multiplication
    SparseMatrix other_transpose = other.transpose();

    // Perform matrix multiplication
    for (const auto &data1 : alldata) {
        
        for (const auto &data2 : other_transpose.alldata) {
        
            // Check if there are common indices
            if (data1.getIndex() == data2.getIndex()) {
                // Calculate dot product of corresponding row and column
                double dot_product = 0.0;
        
                for (const auto &data_this : alldata) {
        
                    if (data_this.getRow() == data1.getRow()) {
        
                        for (const auto &data_other : other_transpose.alldata) {
        
                            if (data_other.getRow() == data2.getRow() && data_this.getIndex() == data_other.getIndex()) {
        
                                dot_product += data_this.getValue() * data_other.getValue();
        
                            }
                        }
                    }
                }
            
                // Store non-zero dot product in result matrix
                if (dot_product != 0.0) {
            
                    Data result_data(data1.getRow(), data2.getRow(), dot_product);
                    result.alldata.push_back(result_data);
            
                }
            }
        }
    }

    // Sort the result matrix
    result.sort();

    return result;
}

/* makes transpose of the original matrix */
SparseMatrix SparseMatrix::transpose() {
    SparseMatrix transposedMatrix;

    // Iterate over each data element in the original matrix
    for (const auto &data : alldata) {
        // Swap row and index to transpose
        Data transposedData(data.getIndex(), data.getRow(), data.getValue());
        transposedMatrix.alldata.push_back(transposedData);
    }

    transposedMatrix.sort();

    return transposedMatrix;
}


/* Private method for reading file */
vector<Data> SparseMatrix::readFile(string file_name){

    /* creating file stream object and opening the desired file */
    ifstream file;
    file.open(file_name);

    int row;
    int index;
    char buffer; /* for colomn */
    double value;

    string line;

    vector<Data> matrix_result;
    Data data_result;

    /* reading Data's information until end of file */
    while(getline(file, line)){
        
        /* turning line to string stream in order to take input easier */
        istringstream linestream(line);

        linestream >> row;

        /* taking input from stream until is over */
        while(linestream >> index >> buffer >> value){

            Data data_result(row,index,value);
            matrix_result.push_back(data_result);

        }

    }

    return matrix_result;

}

void SparseMatrix::sort() {
    
    /* Sort by row and index within each row */
    for (int i = 0; i < alldata.size(); ++i) {
    
        for (int j = i + 1; j < alldata.size(); ++j) {
    
            /* Check if the rows are the same */
            if (alldata[i].getRow() == alldata[j].getRow()) {
    
                /* If rows are equal, sort by index */
                if (alldata[i].getIndex() > alldata[j].getIndex()) {
               
                    swap(alldata[i], alldata[j]);
               
                }
            } 
            else if (alldata[i].getRow() > alldata[j].getRow()) {
            
                /* If rows are different, sort by row */
                swap(alldata[i], alldata[j]);
            
            }
        }
    }
}
