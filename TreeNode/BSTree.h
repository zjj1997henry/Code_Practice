#ifndef BSTREE_H
#define BSTREE_H

#include "TreeNode.h"
#include <climits>

namespace
{
int BSTree_Pre = INT_MIN;
}

bool isBSTree(TreeNode* root)
{
    if(!root) return true;
    if(!isBSTree(root->left)) return false;
    if(BSTree_Pre >= root->data) return false;
    BSTree_Pre = root->data;
    return isBSTree(root->right);
}

#endif // BSTREE_H
