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

![second-time](http://i1.piimg.com/567571/b40679ee52cf02b1.jpg)

2^2个选手的比赛日程表

![third-time](http://i2.buimg.com/567571/0b1effa313cf26eb.jpg)

2^3个选手的比赛日程表
