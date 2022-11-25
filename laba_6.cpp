#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int Sum(int a, int b)
{
    return a + b;
}

int Sum(int a, int b, int c)
{
    return a + b + c;
}

double Sum(double a, double b)
{
    return a + b;
}

double Sum(double a, double b, double c)
{
    return a + b + c;
}

int fill_Mat(int x, int y, int matrix[100][100])
{
    ifstream in("input.txt");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            in >> matrix[i][j];
        }
    }
    in.close();
    return matrix[x][y];
}

bool Same_column(int x, int y, int matrix[100][100])
{
    int count{0};
    for (int j = 0; j < y - 1; j++)
    {
        for (int k = 1; k < y; k++)
        {
            count = 0;
            for (int i = 0; i < x; i++)
            {
                if (matrix[i][j] != matrix[i][j + k])
                {
                    continue;
                }
                else
                {
                    count++;
                }
            }
            if (count == x)
            {
                return true;
            }
        }
    }
    return false;
}

bool is_Prime(int x)
{
    for (int i = 2; i < sqrt(x); i++)
    {
        if (abs(x) % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool prime_numeral_exist(int x, int y, int matrix[100][100])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (is_Prime(matrix[i][j]) == true)
            {
                return true;
            }
        }
    }
    return false;
}

void sort_lines(int x, int y, int matrix[100][100])
{
    int mas_sum_lines[100];
    int sum_line{0};
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            sum_line += abs(matrix[i][j]);
        }
        mas_sum_lines[i] = sum_line;
        sum_line = 0;
    }

    for (int i = 0; i < x-1; i++) // line number
    {
        for (int j = 1; j < x; j++) // +to line number
        {
            if (mas_sum_lines[i] > mas_sum_lines[i+j] && i+j < x)
            {
                for (int k = 0; k < y; k++)
                {
                    swap(matrix[i][k], matrix[i + j][k]);
                }
                swap(mas_sum_lines[i], mas_sum_lines[i+j]);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int lines{};
    int columns{};
    int mat[100][100];

    cout << "Введите количество строк" << endl;
    cin >> lines;
    cout << "Введите количество столбцов" << endl;
    cin >> columns;

    fill_Mat(lines, columns, mat);

    if (Same_column(lines, columns, mat) && prime_numeral_exist(lines, columns, mat))
    {
        sort_lines(lines, columns, mat);
    }
    else
    {
        printf("Не выполнены достаточные условия");
        return 0;
    }

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    /*int x, y, z;
    double i, j, k;
    cin >> x;
    cin >> y;
    cin >> z;
    cin >> i;
    cin >> j;
    cin >> k;
    cout << Sum(x, y) << endl;
    cout << Sum(x, y, z) << endl;
    cout << Sum(i, j) << endl;
    cout << Sum(i, j, k) << endl;*/


}