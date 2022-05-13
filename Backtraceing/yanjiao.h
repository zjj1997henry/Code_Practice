#ifndef YANJIAO_H
#define YANJIAO_H

#include <vector>
using namespace std;

/*
张妈严教技能
从N（N<10）张牌中选出点数和相同的两组牌，可以有剩余
*/

class YanJiao
{
public:
    YanJiao();

    void setNums(vector<int> nums);

    vector<vector<vector<int>>> calc();

private:
    void backtracing(int sum_a, int sum_b, int index);


    vector<vector<vector<int>>> res;

    vector<int> va;
    vector<int> vb;


    vector<int> nums;

};

#endif // YANJIAO_H
