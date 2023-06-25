// Student may implement another function as need

void process(char str[], char outstr[]) {
    int i = 0, j = 0;
    bool prev_space = true;

    while (str[i]) {
        if (str[i] != ' ') {
            outstr[j] = str[i];
            j++;
            prev_space = false;
        } else if (!prev_space && str[i+1] != '\0') {
            outstr[j] = ' ';
            j++;
            prev_space = true;
        }
        i++;
    }

    if (j > 0 && outstr[j-1] == ' ') {
        j--;
    }

    outstr[j] = '\0';
}

// Student may implement another function as need

void process(const char *str, char *outstr) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        outstr[i] = str[len - i - 1];
    }

    outstr[len] = '\0';
}

// Student may implement another function as need

int calc(char str[]) {
    int len = strlen(str);
    int result = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '1') {
            result += (1 << (len - i - 1));
        } else if (str[i] != '0') {
            return -1;
        }
    }

    return result;
}

void cutString(string s, int index){
    std::cout << s.substr(index) << std::endl;
}

void findAllIndex(string s1, string s2){
    std::size_t pos = s1.find(s2[0]);
    while (pos != std::string::npos) {
        std::cout << pos << " ";
        pos = s1.find(s2[0], pos+1);
    }
    std::cout << std::endl;
}

int findMaxColumn(int arr[][1000], int row, int col) {
    int maxSum = INT_MIN;
    int maxCol = -1;
    for (int j = 0; j < col; j++) {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            sum += arr[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxCol = j;
        }
    }
    return maxCol;
}

int diagonalProduct(int arr[][1000], int row, int col) {
    int product = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == j) {
                product *= arr[i][j];
            }
        }
    }
    return product;    
}

bool isSymmetric(int arr[][1000], int row, int col) {
    if (row != col) {
        return false;
    }
    for (int i = 0; i < row; i++) {
        for (int j = i + 1; j < col; j++) {
            if (arr[i][j] != arr[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i - j == x - y) {
                sum1 += arr[i][j];
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i + j == x + y) {
                sum2 += arr[i][j];
            }
        }
    }
    return abs(sum1 - sum2);
}

void calSum(string fileName)   {
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file " << fileName << std::endl;
        return;
    }
    int sum = 0;
    int num;
    while (inFile >> num) {
        if (num >= 0) {
            sum += num;
        }
    }
    std::cout << sum << std::endl;
    inFile.close();
}

#include <iostream>

using namespace std;
// implement calculate factorial function in here
long long calculateFactorial(int n) {
    long long factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int main(int narg, char** argv)
{
    int N;
    cin >> N;
    // call function calculateFactorial in here and assign value to the variable result
    long long result = calculateFactorial(N);
    cout << result << endl;
    return 0;
}

int findMax(int *vals, int numEls) {
    int max = vals[0];
    for (int i = 1; i < numEls; i++) {
        if (vals[i] > max) {
            max = vals[i];
        }
    }
    return max;
}

void sum2(int * array, int numEls, int &result)
{
    result = 0;
    for (int i = 0; i < numEls; i++) {
        result += array[i];
    }
}

bool completeNum(int N)
{
    int sum = 0;
    for (int i = 1; i <= N/2; i++) {
        if (N % i == 0) {
            sum += i;
        }
    }
    return sum == N;
}

