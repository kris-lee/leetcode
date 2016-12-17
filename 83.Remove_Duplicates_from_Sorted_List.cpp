	/*
	83. Remove Duplicates from Sorted List
	Given a sorted linked list, delete all duplicates such that each element appear only once.
	For example,	Given 1->1->2, return 1->2.		Given 1->1->2->3->3, return 1->2->3.
	*/
class Solution{
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *front = head;
		while (front != NULL) {
			ListNode *pTemp = front->next;
			while (pTemp != NULL && pTemp->val == front->val) pTemp = pTemp->next;
			front->next = pTemp;
			front = pTemp;
		}
		return head;
    }
}