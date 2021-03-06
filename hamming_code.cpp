//Nirali codes :)
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <tuple> 
#include <forward_list>
#include <stack>
#include <queue> 
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <set>
#include <unordered_set> 
#include <math.h>
using namespace std;
void sender(int m,int r ,int ham[] ){
    int k=0;
    int x,min,max=0,parity,j;
    for(int i=1;i<=m+r;i=pow(2,k)){
        k++;
        parity=0;
        j=i; x=i; min=1; max=i;
        while( j<=m+r){
            for(x=j;max>=min && x<=m+r;min++,x++){
                if(ham[x]==1){parity+=1;}
            }
            j=x+i;
            min=1;
        }
        if(parity%2==0){ham[i]=0;} 
        else{ham[i]=1;}
    }
}
void receiver(int m,int r,int s[], int syn[]){
    int k=0,j=0;
    int x,min,max=0,parity;
    for(int i=1;i<=m+r;i=pow(2,k)){
        parity=0;
        j=i; x=i; min=1; max=i;
        while( j<=m+r){
            for(x=j;max>=min && x<=m+r;min++,x++){
                if(s[x]==1){parity+=1;}
            }
            j=x+i;
            min=1;
        }
        syn[k]= parity%2;
        k++;
    }
}
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1; 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    } 
    return dec_value;
}
unsigned int calculate_one(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
int value_of_r_sender(int k){
    int flag=1;
    int r=0;
    while(flag==1){
        r++;
        int a=k+r;
        if(pow(2,r)>a){
            flag=0;
        }
    }
    return r;
}
int value_of_r_receiver(int a){
    int flag=1;
    int r=0;
    while(flag==1){
        r++;
        if(pow(2,r)>a){
            flag=0;
        }
    }
    return r;
}
int main(){
   
    // Sender side 
    cout<<"\nEnter sender side details : ";
    int m;
    cout<<"\nEnter the number of bits : ";
    cin>>m;
    int data[m+1];
    cout<<"Enter the data to be sent : ";
    for(int i=1;i<=m;i++){
        cin>>data[i];
    }
    int r=value_of_r_sender(m);
    int ham[m+r+1],j=0;
    int b=1;
    for(int i=1;i<=m+r;i++){        
        if(calculate_one(i)==1){
            ham[i]=-1;
        }
        else{
            ham[i]=data[b];
            b++;
        }
    }
    sender(m, r , ham);
    // The hamming code that is sent
    cout<<"\nThe code sent is: ";
    for(int i = 1; i <= m + r; i++)
        cout<<ham[i]<<" "; 

    // Receiver side
    cout<<"\nEnter the receiver side details : ";
    int a;
    cout<<"\nEnter the number of bits : ";
    cin>>a;
    int s[a];
    cout<<"\nEnter the received string ";
    for(int i=1;i<=a;i++){
        cin>>s[i];
    } 
    r=value_of_r_receiver(a);
    m=a-r;
    int syn[r];
    receiver(m,r , s,  syn);
    cout<<"Syndrome: ";
    int num=0;
    for(int i=0;i<r;i++){
        num+=syn[i] * pow(10,i);
    }  
    reverse(syn,syn+r);
    for(int i=0;i<r;i++) {
        cout<<syn[i];
    }
    if(binaryToDecimal(num)==0){
        cout<<"\nNo errors";
    }
    else{
        cout<<"\nError is found at an index of "<<binaryToDecimal(num);
        cout<<"\nThe code message should be :";
        if(s[binaryToDecimal(num)]==0){
            s[binaryToDecimal(num)]=1;
        }
        else{
            s[binaryToDecimal(num)]=0;
        }
        for(int i=1;i<=a;i++){
            cout<<s[i]<<" ";
        }
        cout<<endl<<endl;
    }   
    return 0;
}