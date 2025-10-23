#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Matrix{
public:
    std::vector<vector<string>> mtx;
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

void mtxadd(Matrix &mtx1, Matrix &mtx2){
    Matrix tempmtx;
    for (int i = 0; i < mtx1.mtx.size(); ++i) {
        vector<string> row;
        for (int j = 0; j < mtx1.mtx[i].size(); ++j) {
            int mtx1int = stoi(mtx1.mtx[i][j]);
            int mtx2int = stoi(mtx2.mtx[i][j]);
            row.push_back(to_string(mtx1int + mtx2int));
        }
        tempmtx.mtx.push_back(row);
    }
    cout << "Matrix 1 and Matrix 2 added together\n";
    for (int i = 0; i < tempmtx.mtx.size(); ++i) {
        for (int j = 0; j < tempmtx.mtx[i].size(); ++j) {
            cout << tempmtx.mtx[i][j] << " ";
        }
        cout << endl;
    }   
}

int main(){
    Matrix mtx1;
    Matrix mtx2;
    string inputfile;
    cout << "What is your input file name?: ";
    cin >> inputfile;
    load(inputfile, mtx1, mtx2);

    cout << "Vector 1\n";
    for (int i = 0; i < mtx1.mtx.size(); ++i) {
        for (int j = 0; j < mtx1.mtx[i].size(); ++j) {
            cout << mtx1.mtx[i][j] << " ";
        }
        cout << endl;
    }   
    cout << "Vector 2\n";
    for (int i = 0; i < mtx2.mtx.size(); ++i) {
        for (int j = 0; j < mtx2.mtx[i].size(); ++j) {
            cout << mtx2.mtx[i][j] << " ";
        }
        cout << endl;
    } 

    mtxadd(mtx1,mtx2);
}