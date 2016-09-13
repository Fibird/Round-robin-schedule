#include <iostream>
#include <cmath>

#define N 3

using namespace std;

int main()
{
    int k = N;
    int sche = pow(2, k);      // divide the problem to pow(2, k) subproblems
    int arr[sche][sche];
    // inits the array with 0 and gives 1 to 8 to line 1
    for (int i = 0; i < sche; i++)
    {
        for (int j = 0; j < sche; j++)
        {
            if (i == 0)
            {
                arr[i][j] = j + 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < k; j++)
    {
        // gets the size of the problem,
        // every loop the problem will triple
        int m_size = pow(2, j);
        for (int r = 0; r < pow(2, j); r++)
        {
            for (int c = 0; c < sche; c++)
            {
                // uses round to get the index of problem block
                int bid = (c + m_size) / m_size;
                int c_offset = pow(-1, bid + 1) * m_size;
                int r_offset = m_size;
                arr[r + r_offset][c + c_offset] = arr[r][c];
            }
        }
    }
    // outputs the schedule of the round robin
    for (int i = 0; i < sche; i++)
    {
        for (int j = 0; j < sche; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
