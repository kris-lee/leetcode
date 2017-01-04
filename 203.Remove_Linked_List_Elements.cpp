/*
203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.
Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* new_head = new ListNode(-1);
		ListNode* pTemp = head, *pTemp_front = new_head;
		new_head->next = pTemp;
		while (pTemp) {
			if (pTemp->val == val) pTemp_front->next = pTemp->next;
			else pTemp_front = pTemp;
			pTemp = pTemp->next;
		}
		return new_head->next;
	}
};
