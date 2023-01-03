// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

class Solution {
public:
    int compute(int a, int b, char op) {
        switch (op) {
            case '+' : {
                return a+b; 
            }
            case '-' : {
                return b - a; 
            }
            case '*' : {
                return b * a; 
            }
            default: {
                return b / a; 
            }
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> x; 
        for (int i = 0; i < tokens.size(); i++) {
            string t = tokens[i]; 
            if (!( t == "+" || t == "-" || t == "*" || t == "/")) {
                x.push(atoi(t.c_str()));
            } else {
                int a = x.top();
                x.pop(); 
                int b = x.top();
                x.pop(); 
                x.push(compute(a,b,t[0])); 
            }
        }
        return x.top(); 
    }
};