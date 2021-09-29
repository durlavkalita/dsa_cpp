// Check for balanced parantheses

#include<bits/stdc++.h>

using namespace std;

checkBalancedparantheses(exp) {
  n = len(exp);
  create stack S;
  for ( i = 0; i < n-1; i++)
  {
    if(exp[i] is '(' || '{' || '[') {
      push(exp[i]);
    }
    else if(exp[i] is ')' || '}' || ']') {
      if(S.empty()) || (top() does not pair with exp[i]) {
        return false;
      }
      else{
        Pop()
      }
    }
    return S is empty? true : false;
  } 
}