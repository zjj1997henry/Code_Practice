#include "outstack.h"

OutStack::OutStack()
{

}

void OutStack::setSeries(vector<char> series){
    for(auto i : series){
        m_series.push_back(i);
    }
}

vector<vector<char>> OutStack::outStack(){
    backtracing(0);
    return res;
}

void OutStack::backtracing(int index){

    if(m_series.empty() && m_stack.empty()){
        res.push_back(temp);
        return;
    }

    {
        //第一种情况，弹出栈元素
        if(!m_stack.empty()){
            char c = m_stack.top();
            temp.push_back(c);
            m_stack.pop();
            backtracing(index + 1);
            temp.pop_back();
            m_stack.push(c);
        }

        //第二种情况，入栈
        if(!m_series.empty()){
            char c = m_series.front();
            m_stack.push(c);
            m_series.pop_front();
            backtracing(index + 1);
            m_stack.pop();
            m_series.push_front(c);
        }
    }

}
