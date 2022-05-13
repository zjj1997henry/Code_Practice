#include "yanjiao.h"
#include <algorithm>
#include <set>


YanJiao::YanJiao()
{


}

void YanJiao::setNums(vector<int> nums)
{
    this->nums = nums;
}


multiset<multiset<multiset<int>>> YanJiao::calc()
{
    backtracing(0, 0, 0);
    return res;
}

void YanJiao::backtracing(int sum_a, int sum_b, int index)
{
    if(sum_a == sum_b && sum_a > 0){

        if(!res.count({va, vb}) && !res.count({vb,va})){
            res.insert({va,vb});
        }
        return;
    }

    //每张牌都有三种情况，A选，B选，都不选
    for(int i = index; i < nums.size(); i++){
        if(sum_b - sum_a < 13 * (int)(nums.size() - i))
        {
            va.insert(nums[i]);
            backtracing(sum_a + nums[i], sum_b, i+1);
            va.erase(va.find(nums[i]));
        }

        if(sum_a - sum_b < 13 * (int)(nums.size() - i))
        {
            vb.insert(nums[i]);
            backtracing(sum_a, sum_b + nums[i], i+1);
            vb.erase(vb.find(nums[i]));
        }

        {
            backtracing(sum_a, sum_b, i+1);
        }
    }
}
