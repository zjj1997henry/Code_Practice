#ifndef YANJIAO_H
#define YANJIAO_H

#include <vector>
#include <set>
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

    multiset<multiset<multiset<int>>> calc();

private:
    void backtracing(int sum_a, int sum_b, int index);


    multiset<multiset<multiset<int>>> res;

    multiset<int> va;
    multiset<int> vb;


    vector<int> nums;

};

#endif // YANJIAO_H
