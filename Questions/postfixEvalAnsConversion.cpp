#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int calc(char optr , int v1 , int v2){
    if(optr == '+') return  v1 + v2;
    else if(optr == '-') return  v1 - v2;
    else if(optr == '*') return  v1 * v2;
    else if(optr == '/') return  v1 / v2;
    else return 0;
}
 
int main(){
    string str;
    cout << "Enter Postfix Expression: ";
    cin >> str;

    stack<int> eval;
    stack<string> infix;
    stack<string> prefix;

    // travel from start -> start with putting any nums first
    for(int i=0 ; i<str.length() ; i++){
        char ch = str[i];

        if(ch >= '0' && ch <= '9'){
            eval.push(ch-'0');
            string s = string(1,ch);
            infix.push(s);
            prefix.push(s);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            string op = string(1,ch);

            //evaluation
            int v2 = eval.top();
            eval.pop();
            int v1 = eval.top();
            eval.pop();

            int evalVal = calc(ch , v1 , v2);
            eval.push(evalVal);

            // infix
            string inv2 = infix.top();
            infix.pop();
            string inv1 = infix.top();
            infix.pop();

            string inVal = "(" + inv1 + op + inv2 + ")";
            infix.push(inVal);

            //prefix
            string prev2 = prefix.top();
            prefix.pop();
            string prev1 = prefix.top();
            prefix.pop();

            string preVal = op + prev1 + prev2;
            prefix.push(preVal);
        }
    }

    cout << endl;
    cout << "Postfix Evaluation :" << eval.top() << endl;
    cout << "Infix Expression: " << infix.top() << endl;
    cout << "prefix Expression: " << prefix.top() << endl;
 
    return 0;
}