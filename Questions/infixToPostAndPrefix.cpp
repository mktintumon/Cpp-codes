#include <bits/stdc++.h>
#include<stack>
#include <ctype.h>
using namespace std;

// precedence checker
int precd(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2; //  -->(* ans /)
}

void operations(stack<string> &prefix ,stack<string> &postfix,stack<char> &optr){
    char op = optr.top();
    optr.pop();
    string s = string(1,op);

    //prefix
    string pre2 = prefix.top();
    prefix.pop();
    string pre1 = prefix.top();
    prefix.pop();
    prefix.push(s + pre1 + pre2);

    //postfix
    string post2 = postfix.top();
    postfix.pop();
    string post1 = postfix.top();
    postfix.pop();
    postfix.push(post1 + post2 + s);
}
 
int main(){
    string str;
    cout << "Enter Infix Expression: ";
    cin >> str;

    stack<string> prefix;
    stack<string> postfix;
    stack<char> optr;

    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(ch == '('){
            optr.push(ch);
        }
        else if((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
            string s = string(1,ch);
            prefix.push(s);
            postfix.push(s);
        }
        else if(ch == ')'){
            while(optr.size() > 0 && optr.top() != '('){
                operations(prefix , postfix, optr);
            }
            optr.pop();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(optr.size() > 0 && optr.top() != '(' && precd(ch) <= precd(optr.top())){
                operations(prefix , postfix, optr);
            }
            optr.push(ch);
        }
    }

    while(optr.size() >  0){
        operations(prefix , postfix, optr);
    }

    cout << endl;
    cout << "Prefix Expression: " << prefix.top() << endl;
    cout << "Postfix Expression: " << postfix.top() << endl;

    return 0;
}