#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else{
            if(st.empty())
                return false;
            else{
                char c = st.top();
                if(s[i] == ')' && c != '(')
                    return false;
                else if(s[i] == '}' && c != '{')
                    return false;
                else if(s[i] == ']' && c != '[')
                    return false;
                st.pop();
            }
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

int main()
{
    string s;
    cin>>s;
    cout<<isValid(s)<<endl;
    return 0;
}