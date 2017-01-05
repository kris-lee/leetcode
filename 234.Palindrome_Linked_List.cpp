/*
234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.
Follow up: Could you do it in O(n) time and O(1) space?
*/
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		vector<int> nums;
		while(head) nums.push_back(head->val), head = head->next;
		for (int i = 0, j = nums.size()-1; i < j; i++, j--)
			if (nums[i] != nums[j]) return false;
		return true;
    }
};