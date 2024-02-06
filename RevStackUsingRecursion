//reverse a stack using recursion again problem horahi hai insertion of stack mai acc to me code right hai
#include<bits/stdc++.h>
using namespace std;
void insert_at_bottom(stack<int>& ss, int n){
        
        if(ss.empty()){
            ss.push(n);
            return;
        } 
        
        int x=ss.top();
        ss.pop();
        
        insert_at_bottom(ss,x);
        
        ss.push(x);
        
        }
void rev_stack_rec(stack<int>& s){
        // pehle top element save karenge phir
        // usko pop karke baaki stack ko reverse hona padega aur phir ham saved top element ko insert at bottom
        
        if(s.empty()) return;//base_case
        
        int num=s.top();// hogaya 1st step 
        s.pop();
        
        rev_stack_rec(s);
        
        insert_at_bottom(s,num);
        
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
    stack<int> l ;
    l.push(3);
    l.push(6);
    l.push(9);
    l.push(0);
   // print_stack(l);
    rev_stack_rec(l);
     print_stack(l);
    return 0;
}
