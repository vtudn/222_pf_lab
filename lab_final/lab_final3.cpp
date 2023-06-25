// Give an integer x, implement function

// int countWaySumOfSquare(int x)
// to find number of ways to express x as sum of squares of unique positive integers.

// For example:

// Input  : x = 100
// Output : 3
// Explain: 100 = 10^2 = 8^2 + 6^2 = 1^2 + 3^2 + 4^2 + 5^2 + 7^2
// Note: Please note that you can't using key work for, while, goto (even in variable names, comment).
// You can implement other recursive functions if needed.

// For this exercise, we have #include <iostream>, #include <math.h> and using namespace std;

#include <iostream>
#include <math.h>

using namespace std;

int countWaySumOfSquare2(int x, int num)
{
    if (x < 0)
        return 0;
    if (x == 1)
        return 1;
    int ways = 0;
    int limits = sqrt(x);
    if (num <= limits){
        int remaining = x - num*num;
        ways += countWaySumOfSquare2(remaining, num +1);
        ways += countWaySumOfSquare2(x, num +1);
    }
    return ways;
}

int countWaySumOfSquare(int x)
{
    return countWaySumOfSquare2(x, 1);
}

int main()
{
    cout << countWaySumOfSquare(100);
    return 0;
}
