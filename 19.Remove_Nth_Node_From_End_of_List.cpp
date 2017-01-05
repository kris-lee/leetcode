/*
19. Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.
For example, Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
*/
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *pTemp_back = head;
		ListNode *pTemp_front = new ListNode(-1);
		pTemp_front->next = head;
		int count = 1;
		while (count < n) pTemp_back = pTemp_back->next,++count;
		while (pTemp_back->next != NULL) {
			pTemp_back = pTemp_back->next;
			pTemp_front = pTemp_front->next;
		}
		pTemp_front->next = pTemp_front->next->next;
		if (pTemp_front == head) return pTemp_front;
		if (pTemp_front->next == head->next) return head->next;
		return head;
    }
};
