#include <iostream>
#include <cmath>

#define N 3

using namespace std;

int main()
{
    int sche = pow(2.0, N);      // divide the problem to pow(2, k) subproblems
    int **arr;
    int bw, bid;
    int c_offset, r_offset;

    // allocate memory for array
    arr = new int*[sche];
    for (int i = 0; i < sche; i++)
    {
        arr[i] = new int[sche];
    }

    // inits line 1 with 1 to 8
    for (int i = 0; i < sche; i++)
    {
        arr[0][i] = i + 1;
    }

    for (int j = 0; j < N; j++)
    {
        // gets the size of the problem,
        // every loop the problem will triple
        bw = pow(2.0, j);
        for (int r = 0; r < bw; r++)
        {
            for (int c = 0; c < sche; c++)
            {
                // uses round to get the index of problem block
                bid = (c + bw) / bw;
                c_offset = pow(-1.0, bid + 1) * bw;
                r_offset = bw;
                arr[r + r_offset][c + c_offset] = arr[r][c];
            }
        }
    }
    // outputs the schedule of the round robin
    cout << "N\\D\t";
    for (int i = 0; i < sche - 1; i++)
    {
        cout << i + 1 << "\t";
    }
    cout << "\n";
    for (int i = 0; i < sche; i++)
    {
        for (int j = 0; j < sche; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
    for (int i = 0; i < sche; i++)
    {
        delete arr[i];
    }
    delete arr;
    return 0;
}
