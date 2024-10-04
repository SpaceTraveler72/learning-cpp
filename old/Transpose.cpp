#include <iostream>
using namespace std;

int** make2DArray(int row, int col) {
    int** array = (int**)malloc(row*sizeof(int*));
    array[0] = (int*)malloc(col*row*sizeof(int));
    for(int i = 1; i < row; i++) {
        array[i] = array[i-1] + col;
    }
    return array;
}

int** fillArray(int **array, int row, int col) {
    int value = 3;

    for (int i = 0; i < row; i++) {
        for (int index = 0; index < col; index++) {
            array[i][index] = value;
            value+=3;
        }
    }
    
    return array;
}

int** transposeArray(int **array, int row, int col) {
    int** transpose = make2DArray(col, row);

    for (int i = 0; i < row; i++) {
        for (int index = 0; index < col; index++) {
            transpose[index][i] = array[i][index];
        }
    }

    return transpose;
}

void printArray(int **array, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int index = 0; index < col; index++) {
            cout << array[i][index] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row, col;
    cout << "How Many Rows: ";
    cin >> row;

    cout << "How Many Columns: ";
    cin >> col;

    int** array = make2DArray(row, col);
    array = fillArray(array, row, col);

    cout << "Matrix is: " << endl;
    printArray(array, row, col);

    cout << "Transpose is: " << endl;
    array = transposeArray(array, row, col);
    printArray(array, col, row);
}