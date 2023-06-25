#include <iostream>
#include <string>

using namespace std;

/* int gcdRecursion(int p, int q) // recursion 1
{
    if (q == 0)
    {
        return p;
    }
    else
    {
        return gcdRecursion(q, p % q);
    }
}
int gcdIteration(int p, int q)
{
    while (q != 0)
    {
        int temp = q;
        q = p % q;
        p = temp;
    }
    return p;
} */

/* int strLen(char *str) // recursion 2
{
    if (*str == '\0')
    {
        return 0;
    }
    else
    {
        return 1 + strLen(str + 1);
    }
} */

/* void printPattern(int n) // recursion 3
{
    if (n <= 0)
    {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    printPattern(n - 5);
    cout << n << " ";
} */

/* int getValueAtIndex(int *ptr, int k) // pointer basic 1
{
    int cnt = 0;
    while (ptr != NULL)
    {
        if (cnt == k)
        {
            return *ptr;
        }
        cnt++;
        ptr++;
    }
    return -1;
} */

/* void swap(int *ptr1, int *ptr2) // pointer basic 2
{
    int middle_man = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = middle_man;
} */

/* int *zeros(int n) // pointer 1
{
    if (n <= 0)
    {
        return nullptr;
    }
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    return arr;
} */

/* void shallowCopy(int *&newArr, int *&arr) // pointer 2
{
    newArr = arr;
} */

/* int **deepCopy(int **matrix, int r, int c) // pointer 3
{
    if (r <= 0 || c <= 0 || matrix == nullptr)
    {
        return nullptr;
    }
    int **newMatrix = new int *[r];
    for (int i = 0; i < r; i++)
    {
        newMatrix[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    return newMatrix;
} */

/* void deleteMatrix(int **&matrix, int r) // pointer 4
{
    if (matrix != NULL)
    {
        for (int i = 0; i < r; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = NULL;
    }
} */

/* void insertRow(int **&matrix, int r, int c, int *rowArr, int row) // pointer 5
{
    int **newMatrix = new int *[r + 1];
    for (int i = 0; i < row; i++)
    {
        newMatrix[i] = matrix[i];
    }
    for (int i = row + 1; i < r + 1; i++)
    {
        newMatrix[i] = matrix[i - 1];
    }
    int *newRow = new int[c];
    for (int i = 0; i < c; i++)
    {
        newRow[i] = rowArr[i];
    }
    newMatrix[row] = newRow;
    delete[] matrix;
    matrix = newMatrix;
} */

/* struct SCP // struct 1
{
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string *addendums;
    int numAddendums;
}; */

/* void addAddendum(SCP &obj, string addendum) // struct 2
{
    string *newAddendums = new string[obj.numAddendums + 1];
    for (int i = 0; i < obj.numAddendums; i++)
    {
        newAddendums[i] = obj.addendums[i];
    }
    newAddendums[obj.numAddendums] = addendum;
    delete[] obj.addendums;
    obj.addendums = newAddendums;
    obj.numAddendums++;
} */

int main()
{

    cout << "\nDone!" << '\n';
    return 0;
}