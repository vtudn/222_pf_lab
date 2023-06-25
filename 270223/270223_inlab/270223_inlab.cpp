// ******************FUNCTION_INLAB&****************

// ****************** 1 ****************
/* #include <iostream>

using namespace std;

bool isPalindrome(const char* str) {
    const char* end = str;
    while (*end != '\0') {
        end++;
    }
    end--;
    while (str < end) {
        if (*str != *end) {
            return false;
        }
        str++;
        end--;
    }
    return true;
}

int main()
{
    const char *str = "abba";
    cout << isPalindrome(str);
    return 0;
} */

// ****************** 2 ****************

/* #include <iostream>

bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int sum_of_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool isSpecialNumber(int n)
{
    if (!is_prime(n))
    {
        return false;
    }
    int digit_sum = sum_of_digits(n);
    return is_prime(digit_sum);
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << isSpecialNumber(n);
    return 0;
} */

// ****************** 3 ****************

/* #include <iostream>

using namespace std;

void encrypt(char *text, int shift)
{
    for (int i = 0; text[i] != '\0'; ++i)
    {
        char c = text[i];
        if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' + shift) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + shift) % 26 + 'a';
        }
        text[i] = c;
    }
}

void decrypt(char *text, int shift)
{
    for (int i = 0; text[i] != '\0'; ++i)
    {
        char c = text[i];
        if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' - shift + 26) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' - shift + 26) % 26 + 'a';
        }
        text[i] = c;
    }
}

int main()
{
    int n, shift;
    cin >> n >> shift;
    char *text = new char[n + 1];
    for (int i = 0; i < n; i++)
        cin >> text[i];
    text[n] = 0;

    encrypt(text, shift);
    cout << text << '\n';
    decrypt(text, shift);
    cout << text;

    delete[] text;

    return 0;
} */

// ****************** 4 ****************

/* #include <iostream>

using namespace std;

bool checkElementsUniqueness(int *arr, int n)
{
    bool seen[1001] = {false};
    for (int i = 0; i < n; i++)
    {
        if (seen[arr[i]])
        {
            return false;
        }
        seen[arr[i]] = true;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << checkElementsUniqueness(arr, n);
    delete[] arr;
    return 0;
} */

// ****************** 5 ****************
/* #include <iostream>

using namespace std;

long int decimalToBinary(int decimal_number)
{
    if (decimal_number == 0)
        return 0;
    else
        return (decimal_number % 2 + 10 * decimalToBinary(decimal_number / 2));
}

int main()
{
    cout << decimalToBinary(20);

    return 0;
} */

// ******************FILE IO_INLAB&****************

// ****************** 1 ****************
/* #include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void uppercase(string output)
{
    string input;
    getline(cin, input);
    for (char &c : input)
    {
        if (islower(c))
        {
            c = toupper(c);
        }
    }
    ofstream outfile(output);
    outfile << input;
    outfile.close();
}

int main()
{

    return 0;
} */

// ****************** 2 ****************
/* #include <iostream>
#include <fstream>
#include <string>

using namespace std;

void threeChars(string fileName)
{
    ifstream infile(fileName);
    if (!infile.is_open())
    {
        cerr << "Failed to open input file.\n";
        return;
    }
    string row;
    while (getline(infile, row) && row != "***")
    {
        bool isAscending = true;
        for (int i = 0; i < 2; i++)
        {
            if (row[i] > row[i + 1])
            {
                isAscending = false;
                break;
            }
        }
        cout << (isAscending ? "true" : "false") << endl;
    }
    infile.close();
}

int main()
{

    return 0;
} */

// ****************** 3 ****************
/* #include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void process(string fileName)
{
    ifstream infile(fileName);
    if (!infile.is_open())
    {
        cerr << "Failed to open input file.\n";
        return;
    }

    int N, M;
    string line;
    getline(infile, line);
    stringstream ss(line);
    ss >> N >> M;

    vector<vector<double>> rows(N, vector<double>(M));

    for (int i = 0; i < N; i++)
    {
        getline(infile, line);
        stringstream ss(line);
        for (int j = 0; j < M; j++)
        {
            ss >> rows[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        double maxVal = *max_element(rows[i].begin(), rows[i].end());
        cout << maxVal << " ";
    }

    vector<double> allNums;
    for (int i = 0; i < N; i++)
    {
        allNums.insert(allNums.end(), rows[i].begin(), rows[i].end());
    }
    double maxAll = *max_element(allNums.begin(), allNums.end());
    cout << maxAll << endl;

    infile.close();
}

int main()
{

    return 0;
} */

// ******************MULTI-DIMENSIONAL ARRAY_INLAB&****************

// ****************** 1 ****************
/* #include <iostream>
#include <string>

using namespace std;

int ascendingRows(int arr[][1000], int row, int col)
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        bool isAscending = true;
        for (int j = 0; j < col - 1; j++)
        {
            if (arr[i][j] > arr[i][j + 1])
            {
                isAscending = false;
                break;
            }
        }
        if (isAscending)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[][1000] = {{-28, -8, -60, 18}, {-100, 44, -1, 24}, {-94, 92, -70, 75}};
    cout << ascendingRows(arr, 3, 4);
    return 0;
} */

// ****************** 2 ****************
/* #include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPrime(int n, int i = 2)
{
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;
    return isPrime(n, i + 1);
}

int primeColumns(int arr[][1000], int row, int col)
{
    int count = 0;
    for (int j = 0; j < col; j++)
    {
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += arr[i][j];
        }
        if (isPrime(sum))
            count++;
    }
    return count;
}

int main()
{
    int arr[][1000] = {{34, -15, 11, -70, -23, 24}, {-39, -90, 63, -45, -52, 48}, {-42, 92, 55, 92, 82, 81}};
    cout << primeColumns(arr, 3, 6);

    return 0;
} */

// ******************CLASSSTRING_INLAB&****************

// ****************** 1 ****************
/* void replaceString(string s, string s1, string s2)
{
    size_t found = s.rfind(s1);
    if (found != string::npos)
    {
        s.replace(found, s1.length(), s2);
        cout << s;
    }
    else
    {
        cout << s;
    }
} */

// ****************** 2 ****************
/* void deleteWord(string s, string s1)
{
    size_t pos = std::string::npos;
    while ((pos = s.find(s1)) != std::string::npos)
    {
        s.erase(pos, s1.length());
    }
    cout << s;
} */

// ****************** 3 ****************
/* #include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int flag = 1;
    int max = 0;
    cin >> input;
    if (input.length() == 1)
    {
        cout << 1;
    }
    else
    {
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] != input[i + 1])
            {
                flag = 1;
            }
            else if (input[i] == input[i + 1])
            {
                flag++;
            }
            if (flag > max)
            {
                max = flag;
            }
        }
        cout << max;
    }
} */

// ******************C-STRING_INLAB&****************

// ****************** 1 ****************
/* #include <iostream>
#include <cstring>

using namespace std;

void process(const char *str, char *outstr)
{
    int len = strlen(str);
    bool is_first = true;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            if (is_first)
            {
                outstr[j++] = toupper(str[i]);
                is_first = false;
            }
            else
            {
                outstr[j++] = tolower(str[i]);
            }
        }
        else if (isspace(str[i]))
        {
            if (!is_first && !isspace(outstr[j - 1]) && i < len - 1 && !isspace(str[i + 1]))
            {
                outstr[j++] = ' ';
                is_first = true;
            }
        }
    }
    if (!is_first && isspace(outstr[j - 1]))
    {
        outstr[j - 1] = '\0';
    }
    else
    {
        outstr[j] = '\0';
    }
}

int main()
{
    char str[] = "423ti !@##   ris423sa aNNA   maRle^&*(y M4234p";
    char *outstr = new char[strlen(str) + 1];
    process(str, outstr);
    cout << outstr;
    return 0;
} */

// ****************** 2 ****************
/* #include <iostream>
#include <cstring>

using namespace std;

void printFirstRepeatedWord(const char str[])
{
    const char *delimiters = " \t\n\r\f\v";
    const int MAX_WORDS = 1000;
    const int MAX_WORD_LENGTH = 100;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int counts[MAX_WORDS] = {0};
    int nWords = 0;
    const char *word = strtok(const_cast<char *>(str), delimiters);

    char save_i[MAX_WORD_LENGTH];
    int order_of_i = 0;
    int min_i = 999999999;

    bool repetitionFound = false;

    while (word != nullptr && nWords < MAX_WORDS)
    {
        bool found = false;
        for (int i = 0; i < nWords; ++i)
        {
            if (strcmp(word, words[i]) == 0)
            {
                save_i[order_of_i] = i;
                order_of_i++;
                found = true;
                repetitionFound = true;
                break;
            }
        }
        if (!found)
        {
            strcpy(words[nWords], word);
            ++counts[nWords];
            ++nWords;
        }
        word = strtok(nullptr, delimiters);
    }

    for (int k = 0; k < order_of_i; k++)
    {
        if (save_i[k] < min_i)
            min_i = save_i[k];
    }

    if (!repetitionFound)
    {
        cout << "No Repetition\n";
    }
    else
        cout << words[min_i];

    if (nWords == MAX_WORDS)
    {
        cerr << "Warning: maximum number of words exceeded\n";
    }
    for (int i = 0; i < nWords; ++i)
    {
        if (counts[i] > 1)
        {
            cout << words[i] << '\n';
            repetitionFound = true;
            break;
        }
    }
}

int main()
{
    char str[] = "car taxi bike bike car taxi";
    printFirstRepeatedWord(str);

    return 0;
} */
