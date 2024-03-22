#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> s;
        while (fast && fast->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // odd size ll
        if (fast) {
            s.push(slow->val);
        }

        while (!s.empty()) {
            if (!slow) return false;
            if (slow->val != s.top()) return false;
            s.pop();
            slow = slow->next;
        }

        return true;
    }
};