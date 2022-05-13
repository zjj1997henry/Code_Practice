#ifndef FANGTONG_H
#define FANGTONG_H
#include <vector>
using std::vector;


/*
 * 张梁方统技能
 * 从N张扑克牌中选出点数和为36的牌。
*/
class Fangtong
{
public:
    Fangtong();

    void setNums(vector<int> nums);

    vector<vector<int>> fangtong();

private:
    void backtracing(int sum, int index);

    vector<vector<int>> ft_nums;
    vector<int> nums;
    vector<int> temp_nums;
};

#endif // FANGTONG_H
