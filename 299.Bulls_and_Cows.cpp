/*
299. Bulls and Cows
ou are playing the following Bulls and Cows game with your friend: 
You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates 
how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and 
how many digits match the secret number but locate in the wrong position (called "cows"). 
Your friend will use successive guesses and hints to eventually derive the secret number.
For example:Secret number:  "1807" Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, 
use A to indicate the bulls and B to indicate the cows. In the above example, 
your function should return "1A3B".
*/
class Solution {
public:
	string getHint(string secret, string guess) {
		int bullsCount = 0, cowsCount = 0;
		for (int i = 0; i < secret.size(); i++)
			if (secret[i] == guess[i]) ++bullsCount;
		if (bullsCount == secret.size()) return to_string(bullsCount)+'A'+to_string(0)+'B'; 
		map<char, int> mapString;
		for (int i = 0; i < secret.size(); i++) {
			if (mapString.count(secret[i]) == 0) mapString[secret[i]] = 1;
			else ++mapString[secret[i]];
		}
		for (int j = 0; j < guess.size(); j++)
			if (mapString.count(guess[j])!=0 && mapString[guess[j]] > 0) ++cowsCount, --mapString[guess[j]];
		return to_string(bullsCount)+'A'+to_string(cowsCount-bullsCount)+'B';
    }
};
