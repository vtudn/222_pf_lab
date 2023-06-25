#include <iostream>
#include <string>

using namespace std;

/* int calcSum(int *ptr, int n) // pointer basic 1
{
    if (n == 0)
        return 0;
    return *ptr + calcSum(ptr + 1, n - 1);
} */

/* void add(int *ptr, int n, int k) // pointer basic 2
{
    *(ptr + n) = k; // only when the array has enough space
    *(ptr + n + 1) == '\0';
    // int *new_ptr = new int[n + 1];
    // for (int i = 0; i < n; i++){
    //     *(new_ptr + i) = *(ptr + i);
    // }
    // *(new_ptr + n) = k;
    // delete[] ptr;
    // ptr = new_ptr;
} */

/* int **readArray() // pointer 1
{
    int **arr = new int *[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = new int[10];
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
            {
                for (int k = j + 1; k < 10; k++)
                {
                    arr[i][k] = 0;
                }
                break;
            }
        }
    }
    return arr;
} */

/* void addElement(int *&arr, int n, int val, int index) // pointer 2
{
    int *new_arr = new int[n + 1];
    if (index == 0)
    {
        *new_arr = val;
        for (int i = 1; i < n + 1; i++)
        {
            *(new_arr + i) = *(arr + i - 1);
        }
    }
    else if (index == n)
    {
        for (int i = 0; i < n; i++)
        {
            *(new_arr + i) = *(arr + i);
        }
        *(new_arr + n) = val;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            *(new_arr + i) = *(arr + i);
        }
        *(new_arr + index) = val;
        for (int i = index + 1; i < n + 1; i++)
        {
            *(new_arr + i) = *(arr + i - 1);
        }
    }
    delete[] arr;
    arr = new_arr;
} */

/* int *flatten(int **matrix, int r, int c) // pointer 3
{
    int *array_1D = new int[r * c];
    int index_cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            *(array_1D + index_cnt) = matrix[i][j];
            index_cnt++;
        }
    }
    return array_1D;
} */

/* char *concatStr(char *str1, char *str2) // pointer 4
{
    int pos_cnt = 0, pos_cnt2 = 0;
    char *concatStr = new char[100];
    while (*(str1 + pos_cnt) != '\0')
    {
        *(concatStr + pos_cnt) = *(str1 + pos_cnt);
        pos_cnt++;
    }
    while (*(str2 + pos_cnt2) != '\0')
    {
        *(concatStr + pos_cnt) = *(str2 + pos_cnt2);
        pos_cnt++;
        pos_cnt2++;
    }
    *(concatStr + pos_cnt) = '\0';
    return concatStr;
} */

/* int **transposeMatrix(int **matrix, int r, int c) // pointer 5
{
    if (*matrix == nullptr)
        return nullptr;
    int **transMatrix = new int *[c];
    for (int i = 0; i < c; ++i)
    {
        transMatrix[i] = new int[r];
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            transMatrix[i][j] = matrix[j][i];
        }
    }
    return transMatrix;
} */

/* struct SCP // struct 1
{
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string *addendums;
    int numAddendums;
};

SCP createSCP(int id, int objClass, string speConProcedures, string description, string *addendums, int numAddendums)
{
    struct SCP SCP_obj;
    SCP_obj.id = id;
    SCP_obj.objClass = objClass;
    SCP_obj.speConProcedures = speConProcedures;
    SCP_obj.description = description;
    SCP_obj.addendums = addendums;
    SCP_obj.numAddendums = numAddendums;
    return SCP_obj;
} */

/* struct SCP // struct 2
{
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string *addendums;
    int numAddendums;
};

string convertToString(SCP obj)
{
    string str_output;
    // item
    str_output += "Item #: SCP-";
    string str_id = to_string(obj.id);
    if (obj.id < 100)
    {
        if (obj.id < 10)
            str_id.insert(0, "00");
        else
            str_id.insert(0, "0");
    }
    str_output += str_id;
    // objClass
    switch (obj.objClass)
    {
    case 0:
        str_output += "\nObject Class: Safe";
        break;
    case 1:
        str_output += "\nObject Class: Euclid";
        break;
    case 2:
        str_output += "\nObject Class: Keter";
        break;
    default:
        break;
    }
    // speConProcedures
    str_output += "\nSpecial Containment Procedures: ";
    str_output += obj.speConProcedures;
    // description
    str_output += "\nDescription: ";
    str_output += obj.description;
    // addendums
    for (int i = 0; i < obj.numAddendums; i++)
    {
        str_output += '\n';
        str_output += obj.addendums[i];
    }
    return str_output;
} */

/* struct SCP // struct 3
{
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string *addendums;
    int numAddendums;
};

SCP *cloneSCP(SCP *original)
{
    SCP *SCP_clone = new SCP;
    SCP_clone->id = original->id;
    SCP_clone->objClass = original->objClass;
    SCP_clone->speConProcedures = original->speConProcedures;
    SCP_clone->description = original->description;
    SCP_clone->numAddendums = original->numAddendums;
    SCP_clone->addendums = new string[SCP_clone->numAddendums];
    for (int i = 0; i < SCP_clone->numAddendums; i++)
    {
        SCP_clone->addendums[i] = original->addendums[i];
    }
    return SCP_clone;
} */

/* bool checkDuplicate(int *ar, int size) // recursion 1
{
    if (size == 1)
        return true;
    if (ar[0] == ar[1])
        return false;
    if (ar[0] == ar[size - 1])
        return false;
    return checkDuplicate(ar + 1, size - 1);
} */

/* int recursiveSearch(int &n, int m, int arr[], int index) // recursion 2
{
    if (index == n)
    {
        return -1;
    }
    else if (arr[index] == m)
    {
        n = n - 1;
        for (int j = index; j < n; j++)
            arr[j] = arr[j + 1];
        return index;
    }
    else
    {
        return recursiveSearch(n, m, arr, index + 1);
    }
} */

int main()
{

    cout << "Done!" << '\n';
    return 0;
}