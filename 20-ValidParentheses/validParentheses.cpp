#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parent;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                parent.push(c);
            }
            else {
                if (parent.empty() ||
                    c == ')' && parent.top() !='(' ||
                    c == ']' && parent.top() !='[' ||
                    c == '}' && parent.top() !='{') {
                    return false;
                }
                parent.pop();
            }
        }
        return parent.empty();
    }
};

int main() {
    string s = "]";
    cout << Solution().isValid(s);
    return 0;
}
