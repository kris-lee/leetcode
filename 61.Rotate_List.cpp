/*
61. Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode *pTemp_front = head, *pTemp_back = head, *pTemp = head;
		int count = 0, length = 0;
		while (pTemp) ++length, pTemp = pTemp->next;
		if (length == 0 || k % length == 0) return head;
		while (count < k%length) pTemp_front = pTemp_front->next, ++count;
		while (pTemp_front->next) pTemp_front = pTemp_front->next, pTemp_back = pTemp_back->next;
		ListNode *newHead = pTemp_back->next;
		pTemp_front->next = head, pTemp_back->next = NULL;
		return newHead;
    }
};
