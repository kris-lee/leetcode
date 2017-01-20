/*
166. Fraction to Recurring Decimal
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
For example,
Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long long l_numerator = numerator;  
        long long l_denominator = denominator;  
        long long rest = 0;  
          
        string result = "";  
        map<long long , int> u_map;
        bool is_positive = true;  
        if (l_denominator == 0) return result;  
        if (l_numerator == 0) return "0";  
        if (l_numerator == INT_MIN && l_denominator == -1) return "2147483648";  
        if (l_numerator < 0) {  
            is_positive = 1 - is_positive;  
            l_numerator = - l_numerator;  
        }  
        if (l_denominator < 0) {  
            is_positive = 1 - is_positive;  
            l_denominator = - l_denominator;  
        }  
        if (l_numerator % l_denominator == 0) {  
            result = to_string(l_numerator/l_denominator);  
        } else {  
            result = to_string(l_numerator / l_denominator) + '.';  
        }  
          
        rest = l_numerator % l_denominator;  
        int index = result.length(); // starting point  
        while (rest != 0 && u_map.find(rest) == u_map.end()) {  
            u_map[rest] = index;  
            rest *= 10;  
            //下面的while完全没有必要。  
            //while (rest * 10 < l_denominator) {  
            //    rest *= 10;  
            //    result +="0";  
            //    index++;  
            //}  
            result += to_string(rest / l_denominator);  
            rest = rest % l_denominator;  
            index++;  
        }  
        if (rest != 0) {  
            result.insert(u_map[rest], 1, '(');  
            result.insert(result.length(), 1, ')');  
        }  
        if (is_positive)  
            return result;  
        else  
            return "-" + result;
    }
};
