	/*
	141. Linked List Cycle
	Given a linked list, determine if it has a cycle in it.
	Follow up:Can you solve it without using extra space?
	*/
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *pTemp_one = head;
		ListNode *pTemp_two = head;
		while (pTemp_two && pTemp_two->next) {
			pTemp_one = pTemp_one->next;
			pTemp_two = pTemp_two->next->next;
			if (pTemp_one == pTemp_two) return true;
		}
		return false;
    }
};
