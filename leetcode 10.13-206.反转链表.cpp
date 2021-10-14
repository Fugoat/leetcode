
#include <iostream>
using namespace std;

 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
//class Solution {
  //迭代法
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode* pre = NULL;
//        ListNode* current = head;
//        ListNode* nexttemp;
//        while (current != NULL)
//        {
//            nexttemp = current->next;
//            current->next = pre;
//            pre = current;
//            current = nexttemp;
//
//        }
//        return pre;
//    }
//};
int main()
{
   
}


