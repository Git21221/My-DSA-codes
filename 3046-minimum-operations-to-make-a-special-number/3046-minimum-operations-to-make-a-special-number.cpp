class Solution {
public:
    int minimumOperations(string num) {
        stack<char> s5;
        stack<char> s0;
        int n = num.size(), count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (num[i] == '0') {
                if (!s0.empty() && s0.top() == '0') { //for 00 digit
                    s0.pop();
                    return count + s5.size() + s0.size();
                } else {
                    s0.push('0');
                }
            } else if (num[i] == '5') {
                if (!s0.empty() && s0.top() == '0') {   //for 50 digit
                    s0.pop();
                    return count + s5.size() + s0.size();
                } else if (!s5.empty() && s5.top() == '5') { //for 55 invalid digit count++
                    count++;
                } else {
                    s5.push('5');
                }
            } else if (num[i] == '7' || num[i] == '2') {
                if (!s5.empty() && s5.top() == '5') {   //for 75 ot 25
                    s5.pop();
                    return count + s5.size() + s0.size();
                } else {
                    count++;
                }
            } else {
                count++;
            }
        }
        if(!s5.empty()) count += s5.size();
        return count;
    }
};
