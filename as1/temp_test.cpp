#include <iostream>

using namespace std;

int main()
{
    int max_3x = -2147483648, min_3x = 2147483647, HP = 432, n2 = 17;
    int n2_trans_sequence[n2] = {-23, 0, 1, 55, -167, -100, 123, 234, 53, 59, 10, 11, 12, 13, 23, 39, 43};
    for (unsigned int h = 0; h < n2; h++)
    {
        if (n2_trans_sequence[h] < 0)
        {
            n2_trans_sequence[h] = -n2_trans_sequence[h];
        }
        n2_trans_sequence[h] = (17 * n2_trans_sequence[h] + 9) % 257;
        cout << n2_trans_sequence[h] << " ";
    }
    cout << '\n';
    int max2_3x = -5;
    int max2_3i = -7;
    if (n2 > 1)
    {
        if (n2 == 2)
        {
            if (n2_trans_sequence[0] > n2_trans_sequence[1])
            {
                max2_3x = n2_trans_sequence[1];
                max2_3i = 1;
            }
            if (n2_trans_sequence[0] < n2_trans_sequence[1])
            {
                max2_3x = n2_trans_sequence[0];
                max2_3i = 0;
            }
        }
        else
        {
            for (unsigned int v = 0; v < 3; v++)
            {
                if (n2_trans_sequence[v] > max_3x)
                {
                    max_3x = n2_trans_sequence[v];
                }
                if (n2_trans_sequence[v] < min_3x)
                {
                    min_3x = n2_trans_sequence[v];
                }
            }
            cout << max_3x << " " << min_3x << "\n";
            if (n2_trans_sequence[0] != n2_trans_sequence[1] && n2_trans_sequence[1] != n2_trans_sequence[2] && n2_trans_sequence[2] != n2_trans_sequence[0]) // 3 diffrent int
            {
                for (unsigned int x = 0; x < 3; x++)
                {
                    if (n2_trans_sequence[x] < max_3x && n2_trans_sequence[x] > min_3x)
                    {
                        max2_3x = n2_trans_sequence[x];
                        max2_3i = x;
                    }
                }
            }
            else // 2 max 1 min or 2 min 1 max, take the first min
            {
                for (unsigned int x = 0; x < 3; x++)
                {
                    if (n2_trans_sequence[x] < max_3x && n2_trans_sequence[x] == min_3x)
                    {
                        max2_3x = n2_trans_sequence[x];
                        max2_3i = x;
                    }
                }
            }
            cout << max2_3x << " " << max2_3i << "\n";
        }
    }
    HP = HP - (max2_3x + max2_3i);
    cout << HP << '\n';

    return 0;
}
