#include "full_arrangement.h"
#include <iostream>
using namespace std;

Full_Arrangement::Full_Arrangement()
{

}

void Full_Arrangement::setNums(const vector<int> nums)
{
    this->nums = nums;
}

void Full_Arrangement::arrangement()
{
    backtracing(0);
}

void Full_Arrangement::backtracing(int startIndex)
{
    if(startIndex == nums.size() - 1)
    {
        res.push_back(nums);

        return;
    }

    //交换index元素和之后的某一个元素
    for(int i = startIndex; i < nums.size(); i++){
        swap(nums[startIndex], nums[i]);
        backtracing(startIndex + 1);
        swap(nums[startIndex], nums[i]);
    }
    return;
}
