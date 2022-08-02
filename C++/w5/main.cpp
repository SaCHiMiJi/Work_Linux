#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isBalanced(string s)
{
    /*
    WRITE YOUR CODE HERE
    */
    string str_open = "([{";
    string str_close = ")]}";
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        // cout << "i : " << i << endl;
        // cout << "s[i] : " << s[i] << endl;
        /* code */
        if (str_open.find(s[i]) != string::npos)
        {
            // cout << "push" << endl;
            st.push(s[i]);
        }
        else if (str_close.find(s[i]) != string::npos)
        {
            // cout << "pop" << endl;
            if (!st.empty())
            {
                char char_top = st.top();
                int stack_size = st.size();
                // cout << "stack_size : " << stack_size << endl;
                // cout << "char_top : " << char_top << endl;
                if ((char_top == '(' && s[i] == ')') || (char_top == '[' && s[i] == ']') || (char_top == '{' && s[i] == '}'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            } 
            else
            {
                return false;
            }
            
        }
        else
        {

            return false;
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s;
    cin >> s;
    while (s != "-1")
    {
        if (isBalanced(s))
        {
            cout << "Parentheses are balanced" << endl;
        }
        else
        {
            cout << "Parentheses are not balanced" << endl;
        }
        cin >> s;
    }
}