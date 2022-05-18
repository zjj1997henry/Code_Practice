#include <iostream>
#include "ListNode.h"
#include "ListReverse.h"
#include "ListMerge.h"
#include "ListUnique.h"
#include "ListTotalUnique.h"
using namespace std;

int main()
{

    ListNode * h1 = mallocList({1,3,5,7,9,13});
    ListNode * h2 = mallocList({2,3,3,4,4,4,6,7,7});

    ListNode * h3 = ListTotalUnique(h2);
    printList(h3);


    return 0;
}
