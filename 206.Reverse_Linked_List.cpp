	/*
	206. Reverse Linked List
	Reverse a singly linked list.
	*/
class Solution{
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *new_head = NULL;
		while (head != NULL) {
			ListNode *pTemp = head->next;
			head->next = new_head;
			new_head = head;
			head = pTemp;
		}
		return new_head;
    }
}