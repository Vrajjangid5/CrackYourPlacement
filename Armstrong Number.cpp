#include <bits/stdc++.h> 
bool isArmstrong(int num) {
    // Write your code here
    int n=num;
   int count=0;
   int sum=0;
    int k=0;
    int temp=num;
    while(n!=0){
        count++;
        int rem=n%10;
        k=k*10+rem;
        n=n/10;
        
    }

    while(temp!=0){
        int rem=temp%10;
        temp=temp/10;
        sum+=pow(rem, count);
    }
    // cout<<sum<<endl;

    return sum==num;
}
