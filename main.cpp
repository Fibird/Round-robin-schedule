#include <iostream>
#include <cmath>

#define N 3

using namespace std;

int main()
{
    int k = N;
    int sche = pow(2, k);
    int arr[sche][sche];

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
        int m_size = pow(2, j);
        for (int r = 0; r < pow(2, j); r++)
        {
            for (int c = 0; c < sche; c++)
            {
                int m = 0;

                if (m_size == 1)
                {
                    m = c;
                }
                else
                {
                    if ((c + 1) % 2 == 0)
                    {
                        m = c / m_size;
                    }
                    else
                    {
                        m = (c + 1) / m_size;
                    }
                }

                int c_offset = pow(-1, m) * m_size;
                int r_offset = m_size;
                arr[r + r_offset][c + c_offset] = arr[r][c];
            }
        }
    }
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
