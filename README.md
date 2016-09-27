# 循环赛日程表

## 问题描述

设有n=2^k个运动员要进行羽毛球循环赛，现要设计一个满足以下要求的比赛日程表：

1. 每个选手必须与其他n-1个选手各赛一次；
1. 每个选手一天只能赛一次；
1. 循环赛一共需要进行n-1天
由于n=2^k，显然n为偶数。

## 算法思路

根据分治法的思想，递归地将问题一分为二，直到只剩下两个人比赛，最后在将这些问题合并起来，这样问题就变得十分简单。日程表的制定过程中存在一定的规律，即第i行第j列表示第i个选手在第j天所遇到的选手。这样算法就很容易实现了。

![first-time](https://github.com/Sunlcy/Round-robin-schedule/blob/master/pictures/first-time.jpg)

2^1个选手的比赛日程表

当问题规模为2^1时，此时问题最为简单，只需要将每个选手复制到对角线位置即可。

![second-time](https://github.com/Sunlcy/Round-robin-schedule/blob/master/pictures/second-time.jpg)

2^2个选手的比赛日程表

当问题规模为2^2时，将问题划分为2个规模为2^1的子问题，先解决子问题，然后在将问题规模为2^1的子问题看作一个整体，并复制到对角线位置，这时即可得到总问题的解。

![third-time](https://github.com/Sunlcy/Round-robin-schedule/blob/master/pictures/third-time.jpg)

2^3个选手的比赛日程表

与上面类似，先将问题划分为4个问题规模为2^1的子问题，分别解决后，再将这些子问题看作一个整体分别复制到对角线处，即可得到两个问题规模为2^2的子问题，最后再将规模变大了的子问题分别复制到对角线处，即可得到总问题的解。

……

# 算法实现

这里我只对代码的关键部分做简要的解释，即下面部分：

```c++
#define N 3
...
int sche = pow(2.0, N);      // divide the problem to pow(2, k) subproblems
...

for (int j = 0; j < N; j++)
{
    // gets the size of the problem,
    // every loop the problem will double
    m_size = pow(2.0, j);
    for (int r = 0; r < m_size; r++)
    {
        for (int c = 0; c < sche; c++)
        {
            // uses round to get the index of problem block
            bid = (c + m_size) / m_size;
            c_offset = pow(-1.0, bid + 1) * m_size;
            r_offset = m_size;
            arr[r + r_offset][c + c_offset] = arr[r][c];
        }
    }
}
```

代码中使用了三层循环，最外层的循环控制问题的规模，即当j=0时，问题规模最小，即前面介绍的规模为2^1的问题；当j=1时，问题规模为2^2；当j=2时，问题规模为2^3……以此类推。这部分可以最能体现分治法的特点，将大问题划分为小问题。

第二层与第三层分别控制元素的行和列，这两层循环主要负责解决不同规模的问题，简单地说就是分别将不同规模的问题块复制到对角线的位置。

为了完成这个看似简单的过程，我们首先需要找一下规律(由于2^k必为偶数，所以n为奇数)：

- 子问题规模为2^1(j=0)时，

      a[0][0]-->a[1][1]
      a[0][1]-->a[1][0]
      a[0][2]-->a[1][3]
      a[0][3]-->a[1][2]
      ...
      a[0][n-1]-->a[0+2^0][(n-1)+2^0]
      a[0][n]-->a[0+2^0][n-2^0]

- 子问题规模为2^2(j=1)时，

      a[0][0]-->a[2][2]
      a[0][1]-->a[1][0]
      ...
      a[0][n-1]-->a[1][n]
      a[0][n]-->a[0+1][n-1]


readme尚未完成，请耐心等待
