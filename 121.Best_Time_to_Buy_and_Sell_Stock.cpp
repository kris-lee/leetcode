	/*
	121. Best Time to Buy and Sell Stock
	Say you have an array for which the ith element is the price of a given stock on day i.
	If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),design an algorithm to find the maximum profit.
	*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<int> max_profit(prices.size(),0);
		int index = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] < prices[index]) index = i, max_profit[i] = max_profit[i-1];
			else max_profit[i] = max(max_profit[i-1], prices[i] - prices[index]);
		}
		return max_profit[prices.size()-1];
    }
}