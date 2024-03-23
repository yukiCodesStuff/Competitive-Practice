struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        
        // get halfway
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse list
        ListNode* curr = slow;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // merge lists
        ListNode* left = head;
        ListNode* right = prev;
        while (left && right) {
            ListNode* next = left->next;
            left->next = right;
            left = next;

            ListNode* prevNext = right->next;
            right->next = left;
            right = prevNext;
        }
    }
};