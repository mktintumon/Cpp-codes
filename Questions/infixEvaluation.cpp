#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

// precedence checker
int precd(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2; //  -->(* ans /)
}


int calc(char optr , int v1 , int v2){
    if(optr == '+') return  v1 + v2;
    else if(optr == '-') return  v1 - v2;
    else if(optr == '*') return  v1 * v2;
    else if(optr == '/') return  v1 / v2;
    else return 0;
}

int main(){
    string str;
    cout << "Enter Expression: ";
    cin >> str;

    stack<int> digit;
    stack<char> optr;

    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        // isdigit(ch) can be used to check if the passed char is digit or not
        if(isdigit(ch)){
            digit.push(ch - '0');
        }
        else if(ch == '('){
            optr.push(ch)  ;
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(optr.size() > 0 && optr.top() != '(' && precd(ch) <= precd(optr.top())){
                int v2 = digit.top();
                digit.pop();
                int v1 = digit.top();
                digit.pop();
                int optr1 = optr.top();
                optr.pop();

                int ans = calc(optr1 , v1 , v2);
                digit.push(ans);
            }

            optr.push(ch);
        }
        else if(ch == ')'){
            while(optr.size() > 0 && optr.top() != '('){
                int v2 = digit.top();
                digit.pop();
                int v1 = digit.top();
                digit.pop();
                int optr1 = optr.top();
                optr.pop();

                int ans = calc(optr1 , v1 , v2);
                digit.push(ans);
            }

            if(optr.size() > 0) optr.pop();
        }
    }

    while(optr.size() > 0){
        int v2 = digit.top();
        digit.pop();
        int v1 = digit.top();
        digit.pop();
        int optr1 = optr.top();
        optr.pop();

        int ans = calc(optr1 , v1 , v2);
        digit.push(ans);
    }

    int ans = digit.top();
    cout << "infix Evaluation: " << ans << endl;

    return 0;
}
