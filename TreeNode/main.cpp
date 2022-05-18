#include <iostream>
#include "TreeNode.h"
#include "BSTree.h"
using namespace std;

int main()
{

    TreeNode* root = mallocTree({1,2,4,8,9,5,3,6,7}, {8,4,9,2,5,1,6,3,7});

    cout<<isBSTree(root)<<endl;
    return 0;
}
