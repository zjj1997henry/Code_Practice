#ifndef NQUEENS_H
#define NQUEENS_H

#include <iostream>
#include <vector>
using namespace std;

/*
N皇后问题，本质是对{1，2，3，...N}全排列的筛选，时间复杂度为N！
*/

class NQueens
{
public:
    NQueens();

    void setNumber(int n);

    void run();

private:
    void backtracing(int startIndex);

    bool valid();

    vector<int> nums;

    vector<vector<int>> res;
};

#endif // NQUEENS_H
