#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

//Gauss Calculator
void printMatrix(vector<vector<double>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "| ";
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << setprecision(1) <<setw(6)<< matrix[i][j] << " ";
        }
        cout <<setw(6)<< "|" << endl;
    }
}

void swapRows(vector<vector<double>>& matrix, int row1, int row2)
{
    for (int j = 0; j < matrix[row1].size(); j++)
    {
        swap(matrix[row1][j], matrix[row2][j]);
    }
    cout << "After swapping R" << row1 << " with R" << row2 << ":" << endl;
    printMatrix(matrix);
}

void normalizeRow(vector<vector<double>>& matrix, int row, int pivot)
{
    double pivotValue = matrix[row][pivot];
    if (pivotValue == 0)

    {
        cout << "Cannot normalize this row\n";
        return;
    }
    for (int j = 0; j < matrix[row].size(); j++)
    {
        matrix[row][j] /= pivotValue;
    }
    cout << "After Normalizing R" << row << ":" << endl;
    printMatrix(matrix);
}

void eliminateRowBelow(vector<vector<double>>& matrix, int pivotRow, int targetRow)
{
    double factor = matrix[targetRow][pivotRow] / matrix[pivotRow][pivotRow];
    for (int j = 0; j < matrix[pivotRow].size(); j++)
    {
        matrix[targetRow][j] -= factor * matrix[pivotRow][j];
    }
    cout << "After eliminating using R" << pivotRow << " on R" << targetRow << ":" << endl;
    printMatrix(matrix);
}

int find_pivot_Row(vector<vector<double>>& matrix, int startRow, int col)
{
    int pivotRow = startRow;
    double largestPivotValue = abs(matrix[startRow][col]);
    for (int j = startRow + 1; j < matrix.size(); j++)
    {
        if (abs(matrix[j][col]) > largestPivotValue)
        {
            largestPivotValue = abs(matrix[j][col]);
            pivotRow = j;
        }
    }
    return pivotRow;
}

bool has_NO_Solution(const vector<vector<double>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        bool allZeros = true;
        for (int j = 0; j < matrix[i].size() - 1; j++)
        {
            if (matrix[i][j] != 0)
            {
                allZeros = false;
                break;
            }
        }
        if (allZeros && matrix[i][matrix[i].size() - 1] != 0)
        {
            return true;
        }
    }
    return false;
}

bool has_Infinite_Solution(const vector<vector<double>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        bool allZeros = true;
        for (int j = 0; j < matrix[i].size() - 1; j++)
        {
            if (matrix[i][j] != 0)
            {
                allZeros = false;
                break;
            }
        }
        if (allZeros && matrix[i][matrix[i].size() - 1] == 0)
        {
            return true;
        }
    }
    return false;
}


void back_substitution(vector<vector<double>>& matrix, vector<double>& sol)
{
    int n = matrix.size();
    sol.assign(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        sol[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++)
        {
            sol[i] -= matrix[i][j] * sol[j];
        }
        sol[i] /= matrix[i][i];
    }
    cout << "Solution:" << '\n';
   
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << sol[i] << '\n';
    }
}


void Gauss(vector<vector<double>>& matrix, vector<double>& sol)
{
    cout << "Enter the number of unknowns: ";
    int n; cin >> n;
    matrix.resize(n, vector<double>(n + 1));

    cout << "Enter the augmented matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Augmented matrix is:\n\n";
    printMatrix(matrix);

    for (int i = 0; i < n; i++)
    {
        int pivRow = find_pivot_Row(matrix, i, i);
        swapRows(matrix, i, pivRow);
        if (matrix[i][i] != 0)
        {
            normalizeRow(matrix, i, i);
            for (int j = i + 1; j < n; j++)
            {
                eliminateRowBelow(matrix, i, j);
            }
        }
        else
        {
            if (has_NO_Solution(matrix))
            {
                cout << "The system has no solution.\n";
                return;
            }
            if (has_Infinite_Solution(matrix))
            {
                cout << "The system has infinite solutions.\n";
                return;
            }
        }
    }

    back_substitution(matrix, sol);
}

int main()
{
    vector<vector<double>> matrix;
    vector<double> sol;
    Gauss(matrix, sol);
    return 0;
}
