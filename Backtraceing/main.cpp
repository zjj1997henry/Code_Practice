#include <iostream>
#include <vector>
#include "yanjiao.h"
using namespace std;
/*
一 确定参数入参

二 函数返回条件

三 单层递归的逻辑

void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}

*/


int main()
{
    YanJiao zhangchangpu;
    zhangchangpu.setNums({3,5,5,8,10});
    zhangchangpu.calc();

    return 0;
}
