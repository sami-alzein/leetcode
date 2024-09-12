
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode listNodeResult(0);
        ListNode* current = &listNodeResult;

        int sum = 0;
        int rest = 0;

        while (l1 != nullptr || l2 != nullptr || rest != 0)
        {
            int l1Number = (l1 != nullptr) ? l1->val : 0;
            int l2Number = (l2 != nullptr) ? l2->val : 0;

            sum = l1Number + l2Number + rest;
            int value = sum % 10;
            rest = sum / 10 ;

            current->next = new ListNode(value);
            current = current->next;
            
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;


        }

        return listNodeResult.next;
    }
};

#include <iostream>
using namespace std;

int main()
{
    // generate a test for the solution
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next;
    }
    
    return 0;
}
