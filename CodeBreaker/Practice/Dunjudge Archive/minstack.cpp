// Status: AC

#include <bits/stdc++.h>
// #include "minstack.h"
using namespace std;
int s[3000005];
int m[3000005];
int ind=0,mind=0;
void push(int X) {
	s[ind]=X;
    ind++;
    if(mind==0){
        m[mind]=X;
        mind++;
    }else{
        if(m[mind-1]>=X){
            m[mind]=X;
            mind++;
        }
    }
}

void pop() {
    int x=s[ind-1];
	ind--;
    if(m[mind-1]==x)mind--;
}

int top() {
	return s[ind-1];
}

int getMin() {
	return m[mind-1];
}

/*
int main(){
    push(3);push(2);push(1);pop();
    cout<<getMin()<<endl;
}*/

