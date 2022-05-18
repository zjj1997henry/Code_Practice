#ifndef TREENODE_H
#define TREENODE_H

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(const int d, TreeNode* l = nullptr, TreeNode* r = nullptr):data(d), left(l), right(r){

    }
};

namespace
{
void TreeNodePrint(TreeNode const *node)
{
    cout<<node->data<<" ";
}

//先序， 中序， 先序左，先序右，中序左，中序右
//左闭右闭
TreeNode* create_root(const vector<int> &pre_order, const vector<int> &middle_order, int pl, int pr, int ml, int mr)
{
    TreeNode* root = new TreeNode();
    int i;
    for(i = ml ; i <= mr; i++){
        if(middle_order[i] == pre_order[pl])
            break;
    }

    root->data = pre_order[pl];

    if( i - ml >= 1){
        root->left = create_root(pre_order, middle_order, pl + 1, pl + i - ml, ml, i - 1);
    }
    if(mr - i >= 1){
        root->right = create_root(pre_order, middle_order, pr - mr + i + 1, pr, i + 1, mr);
    }
    return root;
}
}

TreeNode* mallocTree(const vector<int> &pre_order, const vector<int> &middle_order)
{
    return create_root(pre_order, middle_order, 0, pre_order.size() - 1, 0, middle_order.size() - 1);
}

void TreeNodeDelete(TreeNode** root){
    if(!*root) return;
    TreeNodeDelete(&(*root)->left);
    TreeNodeDelete(&(*root)->right);
    delete *root;
}

void Floor_Order(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* temp;
    while (!q.empty()) {
        temp = q.front();
        TreeNodePrint(temp);
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

void Pre_Order(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty() || p) {
        if(p){
            TreeNodePrint(p);
            s.push(p);
            p = p->left;
        }else{
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void Middle_Order(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty() || p) {
        if(p){
            s.push(p);
            p = p->left;
        }else{
            p = s.top();
            TreeNodePrint(p);
            s.pop();
            p = p->right;
        }
    }
}

void Post_Order(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* p = root, *pre;
    while (!s.empty() || p) {
        if(p){
            s.push(p);
            p = p->left;
        }else{
            p = s.top();
            if(p->right && p->right != pre){ //右子树存在且未被访问
                p = p->right;
                s.push(p);
                p = p->left;
            }else{                          //可能是左子树，也可能是访问过的右子树
                p = s.top();
                s.pop();
                TreeNodePrint(p);
                pre = p;
                p = nullptr;
            }
        }
    }
}

int Tree_Height(TreeNode* root)
{
    queue<TreeNode*> q;
    TreeNode* p = root;
    q.push(p);
    int height = 0, current_level = 1, next_level = 0;
    while (!q.empty()) {
        while (current_level) {
            p = q.front();
            q.pop();
            if(p->left){
                q.push(p->left);
                next_level++;
            }
            if(p->right){
                q.push(p->right);
                next_level++;
            }
            current_level--;
        }
        height++;
        current_level = next_level;
        next_level = 0;
    }
    return height;
}

#endif // TREENODE_H







