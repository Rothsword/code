#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *list;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head){
        this->list = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *p = list->next;
        int val = list->val;
        int n = 2;
        while(p) {
            if ((rand()%n)==0) {
                val = p->val;
            }
            p = p->next;
            n++;
        }
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution* obj = new Solution(head);
    int param_1 = obj->getRandom();
    cout << param_1 << endl;
}

