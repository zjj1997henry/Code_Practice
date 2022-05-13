#ifndef OUTSTACK_H
#define OUTSTACK_H

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <iostream>
using namespace std;

/*
对入栈顺序为abcde的清空，有多少种出栈顺序
*/

class OutStack {
public:
    OutStack();

    void setSeries(vector<char> series);
    vector<vector<char>> outStack();

private:
    void backtracing(int index);
private:
    vector<char> temp;
    vector<vector<char>> res;
    stack<char> m_stack;
    deque<char> m_series;
};

#endif // OUTSTACK_H
