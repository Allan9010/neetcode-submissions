class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token : tokens){
            if(token == "+"){
                int temp = st.top();
                st.pop();
                temp += st.top();
                st.pop();

                st.push(temp);
            }
            else if(token == "-"){
                int temp = st.top();
                st.pop();
                temp = st.top() - temp;
                st.pop();

                st.push(temp);           
            }
            else if(token == "*"){
                int temp = st.top();
                st.pop();
                temp *= st.top();
                st.pop();

                st.push(temp);
            }
            else if(token == "/"){
                int temp = st.top();
                st.pop();
                temp = st.top() / temp;
                st.pop();

                st.push(temp);
            }
            else{
                int temp = std::stoi(token);
                st.push(temp);
            }
        }

        return st.top(); 
    }
};
