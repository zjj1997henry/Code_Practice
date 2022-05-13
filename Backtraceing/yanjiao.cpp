#include "yanjiao.h"
#include <algorithm>

YanJiao::YanJiao()
{

}

void YanJiao::setNums(vector<int> nums)
{
    this->nums = nums;
}


vector<vector<vector<int>>> YanJiao::calc()
{
    backtracing(0, 0, 0);
    return res;
}

void YanJiao::backtracing(int sum_a, int sum_b, int index)
{
    if(sum_a == sum_b && sum_a > 0){

        res.push_back({va, vb});
        return;
    }

    //每张牌都有三种情况，A选，B选，都不选
    for(size_t i = index; i < nums.size(); i++){

        {
            va.push_back(nums[i]);
            backtracing(sum_a + nums[i], sum_b, i+1);
            va.pop_back();
        }

        {
            vb.push_back(nums[i]);
            backtracing(sum_a, sum_b + nums[i], i+1);
            vb.pop_back();
        }

        {
            backtracing(sum_a, sum_b, i+1);
        }
    }
}
