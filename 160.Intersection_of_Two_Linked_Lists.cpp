/*
160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
A:          a1 ¡ú a2
                   ¨K
                     c1 ¡ú c2 ¡ú c3
                   ¨J            
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.
Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int len_A = 0, len_B = 0;
		ListNode *ATemp = headA, *BTemp = headB;
		while (ATemp) ++len_A, ATemp = ATemp->next;
		while (BTemp) ++len_B, BTemp = BTemp->next;
		ATemp = headA, BTemp = headB;
		int move_count = max(len_A,len_B) - min(len_A,len_B);
		if (len_A > len_B) while(move_count != 0) ATemp = ATemp->next, --move_count;
		else while(move_count != 0) BTemp = BTemp->next, --move_count;
		while (ATemp != BTemp) ATemp = ATemp->next, BTemp = BTemp->next;
		return ATemp;
    }
};