

#include <iostream>
using namespace std;

void cr_matrix(int**&, int&, int&);
void cout_matrix(int**, int, int);
void sum_c_r(int**, int, int);
void sum_plus2el(int**, int, int);

int main()
{

    int** matrix = 0;
    int rows = 0;
    int cols = 0;
    do {

        cout << "1-INPUT SIZE AND ELEMETS FOR MATRIX" << '\n';
        cout << "2-OUTPUT MATRIX ELEMETS" << '\n';
        cout << "3-WHICH ROWS AND COLUMNS HAVE THE SAME SUM" << '\n';
        cout << "4-SUM ELEMETS WHEARE MATRIX NOT HAVE TWO ZERO ELEMETS" << '\n';
        cout << "5-END" << '\n';

        int Choise;
        cin >> Choise;
        switch (Choise) {
        case 1: {
            cout << "Enter count rows: ";
            cin >> rows;
            cout << "Enter count cols: ";
            cin >> cols;

            matrix = new int* [rows];
            for (int i = 0;i < rows;i++) {
                matrix[i] = new int[cols];
            }
            cout << "Enter elemets matrix: " << endl;
            cr_matrix(matrix, rows, cols);

        }
              break;
        case 2: {
            cout << "Matrix elements" << '\n';
            cout_matrix(matrix,rows, cols);
            

        }
              break;
        case 3: {
            cout << "Rows and columns that have the same amount of elements: " <<'\n';
            sum_c_r(matrix, rows, cols);
        }
              break;
        case 4: {
            sum_plus2el(matrix, rows, cols);
        }
              break;
        case 5: {
            cout << "GOODBYE";

            return 0;
        }
        }
        
    } while (1);
   
}
void cr_matrix(int**&matrix, int& rows, int& cols) {

    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < cols;j++) {
            cin >> matrix[i][j];
        }
    }
}
void cout_matrix(int**matrix, int rows, int cols) {
    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < cols;j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}
void sum_c_r(int**matrix, int rows, int cols) {
    
    int* sum_rows = new int[rows]();
    int* sum_cols = new int[cols]();

    
    for (int i = 0;i < rows;i++) {
        for (int j = 0; j < cols;j++) {
             
            sum_rows[i] += matrix[i][j];
            sum_cols[j] += matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sum_rows[i] == sum_cols[j]) {
                cout << "Row " << i + 1 << " and Column " << j + 1 << " have equal sums." << endl;
            }
        }
    }

}
void sum_plus2el(int**matrix, int rows, int cols) {

    int coun_no_zero = 0;
        int sum_row = 0;
        
    for (int i = 0; i < rows;i++) {
        

        for (int j = 0; j < cols;j++) {
            if (matrix[i][j] != 0) {
                coun_no_zero++;

                sum_row += matrix[i][j];
            }


        }
        if (coun_no_zero >= 2) {
            cout << sum_row << endl;
        }
        coun_no_zero = 0;
        sum_row = 0;
    }
    
}


