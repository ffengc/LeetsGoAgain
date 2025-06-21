
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <assert.h>

// 逆波兰表达式求值
class Solution {
    using ll = long long;

private:
    int count(ll a, ll b, char op) {
        // note: b是第一个操作数
        switch (op)
        {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/': return b / a;
        default:
            assert(false);
        }
    } //
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<ll> st;
        for (const auto& e : tokens) {
            if (e == "+" || e == "-" || e == "*" || e == "/") {
                auto a = st.top();
                st.pop();
                auto b = st.top();
                st.pop();
                st.push(count(a, b, e[0]));
            } else
                st.push(std::stoi(e));
        }
        assert(st.size() == 1);
        return st.top();
    }
};