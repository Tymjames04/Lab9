#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Matrix{
public:
    std::vector<vector<string>> mtx;

    void print(){
        for (int i = 0; i < mtx.size(); ++i) {
            for (int j = 0; j < mtx[i].size(); ++j) {
                cout << mtx[i][j] << " ";
            }
        cout << endl;
        } 
    }
};

void load(string &inputfile, Matrix &mtx1, Matrix &mtx2){
    int size = 0;
    ifstream myFile(inputfile);
    string line;
    int linecounter = 0;
    while(getline (myFile, line)) {
        if(size == 0){
            size = std::stoi(line);
        }
        else{
            int start = 0;
            vector<string> row; 
            for (int j = 0; j < size; j++) {
                int space = line.find(' ', start);
                if (space == string::npos){
                    space = line.length();
                }
                string temp = line.substr(start, space - start);
                row.push_back(temp);
                start = space + 1;
            }
            if (linecounter < size){
                mtx1.mtx.push_back(row);
            }
            else{
                mtx2.mtx.push_back(row);
            }
            linecounter++;
        }
    }
}

void mtxAdd(Matrix &mtx1, Matrix &mtx2){
    Matrix tempmtx;
    for (int i = 0; i < mtx1.mtx.size(); i++) {
        vector<string> row;
        for (int j = 0; j < mtx1.mtx[i].size(); j++) {
            int mtx1int = stoi(mtx1.mtx[i][j]);
            int mtx2int = stoi(mtx2.mtx[i][j]);
            row.push_back(to_string(mtx1int + mtx2int));
        }
        tempmtx.mtx.push_back(row);
    }
    cout << "Matrix 1 and Matrix 2 added together\n";
    tempmtx.print(); 
}

void mtxMultiply(Matrix &mtx1, Matrix &mtx2){
    Matrix outputMtx;
    for (int i = 0; i < mtx1.mtx.size(); i++){
        vector<string> row;
        for (int j = 0; j < mtx1.mtx.size(); j++){
            int sum = 0;
            for (int k = 0; k < mtx1.mtx.size(); k++){
                int mtx1int = stoi(mtx1.mtx[i][k]);
                int mtx2int = stoi(mtx2.mtx[k][j]);
                sum+= mtx1int*mtx2int;
            }
            row.push_back(to_string(sum));
        }
        outputMtx.mtx.push_back(row);
    }
    cout << "Matrix 1 and Matrix 2 multiplied together\n";
    outputMtx.print();
}

void mtxDiagonalSum(Matrix &mtxz){
    int maindiag = 0;
    int seconddiag = 0;
    for (int i = 0; i < mtxz.mtx.size(); i++) {
        int mtxzint1 = stoi(mtxz.mtx[i][i]);
        int mtxzint2 = stoi(mtxz.mtx[i][mtxz.mtx.size()-1-i]);
        maindiag+=mtxzint1;
        seconddiag+=mtxzint2;
    }
    cout << "Sum of main diagonal: " << maindiag << endl;
    cout << "Sum of secondary diagonal: " << seconddiag << endl;
}

void mtxRowSwap(Matrix &mtxz, int row1, int row2){
}

void mtxColumnSwap(Matrix &mtxz, int col1, int col2){
}

void mtxUpdateRows(Matrix &mtxz, int row, int column){
}


int main(){
    Matrix mtx1;
    Matrix mtx2;
    string inputfile;
    string selectedmtx;
    cout << "What is your input file name?: ";
    cin >> inputfile;
    load(inputfile, mtx1, mtx2);

    cout << "Vector 1\n";
    mtx1.print();

    cout << "Vector 2\n";
    mtx2.print();

    mtxAdd(mtx1,mtx2);
    mtxMultiply(mtx1,mtx2);

    cout << "Would you like to use mtx1 or mtx2 for the next operations?: ";
    cin >> selectedmtx;
    
    if (selectedmtx == "mtx1"){
        mtxDiagonalSum(mtx1);
        //mtxRowSwap(mtx1);
        //mtxColumnSwap(mtx1);
        //mtxUpdateRows(mtx1);
    }
    else if (selectedmtx == "mtx2"){
        mtxDiagonalSum(mtx2);
       // mtxRowSwap(mtx2);
        //mtxColumnSwap(mtx2);
        //mtxUpdateRows(mtx2);
    }
    else{
        cout << "You have entered an invalid matrix option";
        return 0;
    }
}