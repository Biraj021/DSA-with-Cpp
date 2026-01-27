// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
 

// Constraints:

// 1 <= tokens.length <= 104
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
class Solution {
public:
    int kam(int val1, int val2, char c) {
        if(c == '+') return val1 + val2;
        else if(c == '-') return val1 - val2;
        else if(c == '*') return val1 * val2;
        else return val1 / val2; // assume no division by zero
    }

    int evalRPN(vector<string>& t) {
        stack<int> val;

        for(int i = 0; i < t.size(); i++) {
            string token = t[i];

            // If token is an operator
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int val2 = val.top(); val.pop();
                int val1 = val.top(); val.pop();
                val.push(kam(val1, val2, token[0]));
            } 
            else {
                // It's a number, push to stack
                val.push(stoi(token));
            }
        }

        return val.top();
    }

};
