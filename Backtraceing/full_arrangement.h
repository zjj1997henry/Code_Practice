#ifndef FULL_ARRANGEMENT_H
#define FULL_ARRANGEMENT_H

#include <vector>
using std::vector;

/*
全排列问题
*/

class Full_Arrangement
{
public:
    Full_Arrangement();

    void setNums(const vector<int> nums);

    void arrangement();


private:
    void backtracing(int startIndex);

    vector<int> nums;
    vector<vector<int>> res;
};

#endif // FULL_ARRANGEMENT_H
