// Problem Link -: https://leetcode.com/problems/evaluate-reverse-polish-notation/


// Solution 


class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack <int> operands;
        for (auto &e : v) {
            if (!e.compare("+") ) {
                int num1 = operands.top();
                operands.pop();
                int num2 = operands.top();
                operands.pop();
                operands.push(num2+num1);
            }
            else if (!e.compare("-") ) {
                int num1 = operands.top();
                operands.pop();
                int num2 = operands.top();
                operands.pop();
                operands.push(num2-num1);
            }
            else if (!e.compare("*") ) {
                int num1 = operands.top();
                operands.pop();
                int num2 = operands.top();
                operands.pop();
                operands.push(num2*num1);
            }
            else if (!e.compare("/") ) {
                int num1 = operands.top();
                operands.pop();
                int num2 = operands.top();
                operands.pop();
                operands.push(num2/num1);
            }
            else operands.push(stoi(e));
        }
        return operands.top();
    }
};

