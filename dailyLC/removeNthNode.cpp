
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (!head->next) {
            return nullptr;
        }
        
        ListNode* first = new ListNode(0, head);
        ListNode* second = head;
        while (n--) {
            second = second->next;
        }

        if (!second) {
            return head->next;
        }

        while (second) {
            second = second->next;
            first = first->next;
        }

        first->next = first->next->next;
        return head;
    }
};