class Solution {
public:
    bool isValid(string s) {
        stack<char> stackP;
        stackP.push(s[0]);

        for(int i = 1; i < s.size(); ++i){
            char c = s[i];
            if(c == '(' || c == '{' || c == '['){
                stackP.push(c);
                continue;
            }

            if(stackP.empty()) return false;
            char temp = stackP.top();
            if(temp != '(' && c == ')') return false;
            if(temp != '{' && c == '}') return false;
            if(temp != '[' && c == ']') return false;
            stackP.pop();
        }
        if(!stackP.empty()) return false;

        return true;
    }
};
