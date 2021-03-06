/*
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
		intStack.push(x);
		if (intMap.count(x) == 0) intMap[x] = 1;
		else ++intMap[x];
    }
    
    void pop() {
		int topValue = intStack.top();
		intStack.pop();
		if (intMap[topValue] > 1) --intMap[topValue];
		else intMap.erase(topValue);
    }
    
    int top() {
		return intStack.top();
    }
    
    int getMin() {
		return intMap.begin()->first;
    }
	stack<int> intStack;
	map<int, int> intMap;
};