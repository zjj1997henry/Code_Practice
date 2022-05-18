#ifndef LOWESTCOMMONANCESTOR_H
#define LOWESTCOMMONANCESTOR_H

#include "TreeNode.h"


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root || root ==p || root == q){
        return root;
    }

    TreeNode* lchild = lowestCommonAncestor(root->left, p, q);
    TreeNode* rchild = lowestCommonAncestor(root->right, p, q);

    if(lchild && rchild) return root;
    if(!lchild) return rchild;
    return lchild;
}

#endif // LOWESTCOMMONANCESTOR_H
