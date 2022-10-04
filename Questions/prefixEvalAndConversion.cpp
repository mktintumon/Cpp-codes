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
    cout << "Enter Prefix Expression: ";
    cin >> str;

    stack<int> eval;
    stack<string> infix;
    stack<string> postfix;

    // travel in reverse order --> start with putting num not optr
    // means here v1 is v1 and v2 is v2
    for(int i=str.length(); i>=0 ; i--){
        char ch = str[i];

        if(ch >= '0' && ch <= '9'){
            eval.push(ch-'0');
            string s = string(1,ch);
            infix.push(s);
            postfix.push(s);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            string op = string(1,ch);

            //evaluation
            int v1 = eval.top();
            eval.pop();
            int v2 = eval.top();
            eval.pop();

            int evalVal = calc(ch , v1 , v2);
            eval.push(evalVal);

            // infix
            string inv1 = infix.top();
            infix.pop();
            string inv2 = infix.top();
            infix.pop();

            string inVal = "(" + inv1 + op + inv2 + ")";
            infix.push(inVal);

            //postfix
            string postv1 = postfix.top();
            postfix.pop();
            string postv2 = postfix.top();
            postfix.pop();

            string postVal = postv1 + postv2 + op;
            postfix.push(postVal);
        }
    }

    cout << endl;
    cout << "prefix Evaluation :" << eval.top() << endl;
    cout << "Infix Expression: " << infix.top() << endl;
    cout << "Postfix Expression: " << postfix.top() << endl;
 
    return 0;
}