	/*
	24. Swap Nodes in Pairs
	Given a linked list, swap every two adjacent nodes and return its head.
	For example, Given 1->2->3->4, you should return the list as 2->1->4->3.
	Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
	*/
class Solution{
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *new_head = new ListNode(0);
		ListNode *front_head = new ListNode(0);
		ListNode *rear_head = new ListNode(0);
		front_head->next = head, new_head = head->next;
		while (head != NULL && head->next != NULL) {
			rear_head = head->next;
			front_head->next = rear_head;
			head->next = rear_head->next;
			rear_head->next = head;
			front_head = head;
			head = head->next;
		}
		return new_head;
    }
}