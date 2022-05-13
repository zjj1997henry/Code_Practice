#include "fangtong.h"

Fangtong::Fangtong()
{

}

void Fangtong::setNums(vector<int> nums)
{
    this->nums = nums;
}

vector<vector<int>> Fangtong::fangtong()
{
    backtracing(0, 0);
    return ft_nums;
}

//sum 已收集的牌点数之和， index 遍历到的序号
void Fangtong::backtracing(int sum, int index){
    if(sum == 36){
        ft_nums.push_back(temp_nums);
        return;
    }

    for(size_t i = index; i < nums.size() && sum + nums[i] < 36; i++){
        temp_nums.push_back(nums[i]);
        backtracing(sum + nums[i], i+1);
        temp_nums.pop_back();
    }
}
