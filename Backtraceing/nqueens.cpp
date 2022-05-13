#include "nqueens.h"
#include <math.h>

NQueens::NQueens()
{

}

void NQueens::setNumber(int n)
{
    nums.resize(n);
    for(int i = 0; i < n; i++){
        nums[i] = i;
    }
}

void NQueens::run()
{
    backtracing(0);
}


void NQueens::backtracing(int startIndex)
{
    if(startIndex == nums.size() - 1 && valid())
    {
        res.push_back(nums);

        return;
    }

    for(int i = startIndex; i < nums.size(); i++){
        swap(nums[startIndex], nums[i]);
        backtracing(startIndex + 1);
        swap(nums[startIndex], nums[i]);
    }
    return;
}

bool NQueens::valid()
{

    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(j - i == abs(nums[i] - nums[j])){
                return false;
            }
        }
    }
    return true;
}
