//thoda error ;)
#include <bits/stdc++.h>
#include <stack>
using namespace std;
void insert_at_bottom(stack<int>& s, int x){
        //base case agar empty hua toh we'll push the element aur phir ofc return
        //karenge toh usse hamnejoo element pop kare the jisko "num" name ke variable pe rakha tha 
        // usko wapis push karenge wapis push ho ske isliye hamne usko recursive fxn ke niche likha
        
        //base.case
        if(s.empty()){
            s.push(x);
            return;
        }
        
        //now recursive wala
        
        int num=s.top();
        s.pop();
        insert_at_bottom(s,x);
        
        // ab wapis inset bhi toh karna hai ..na samjhe toh ek baar khud se page pe karle :)
        s.push(num);
        
    }
    void print_stack(stack<int>& s){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
int main()
{
    std::stack<int> ss = std::stack<int>({3, 6, 9});
    cout<<"before ";
    print_stack(ss);
    insert_at_bottom(ss,99);
    cout<<"after ";
    print_stack(ss);

    return 0;
}
