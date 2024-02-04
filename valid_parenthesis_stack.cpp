#include<bits/stdc++.h>
using namespace std;
bool valid_parenthesis(string s){
     stack<char> l;
     for(int i=0;i<l.size();i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            l.push(s[i]);
        }
        else{
            if(!l.empty()){
                //condn match hui toh pop else toh galat hai ye 
                if((s[i]=='{' && l.top()=='}') || (s[i]=='[' && l.top()==']') || (s[i]=='(' && l.top()==')' ))     l.pop();
                else return false;
            }
            else return false;
            
        }
      }
     }

int main(){
     string s;
     cin>>s;
     if(valid_parenthesis(s)) cout<<"it's valid "<<endl;
     else cout<<" it's not valid "<<endl;
     return 0;
}