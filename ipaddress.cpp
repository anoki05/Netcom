//Nirali codes :)
#include<math.h>
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
using namespace std;
int value(int a){
    int count=0;
    int temp=a;
    while(temp!=1){
        temp/=2;
        count++;
    }
    return count;
}
int main()
{
    string ipaddress;
    int cidr,no_subcriber;
    cout<<"Enter the ip address ";
    cin>>ipaddress;
    int ip[4];
    int k=0,j;
    string str="";
    for (int i=0;i<ipaddress.length()-1;i++){
        str+=ipaddress[i];
        if(ipaddress[i]=='.'){
            ip[k]=stoi(str);
            str="";
            k++;
        }
        if(k==3){
            j=i;
            break;
        }
    }
    str="";
    for(int i=j+1;i<=ipaddress.length()-1;i++){
        str+=ipaddress[i];
    };
    ip[3]=stoi(str);
    cout<<"\nEnter the cidr value ";
    cin>>cidr;
    cout<<"Enter the number of subcribers : ";
    cin>>no_subcriber;
    int arr1[no_subcriber],arr2[no_subcriber];
    int sum=0;
    for(int i=0;i<=no_subcriber-1;i++){
        cout<<"Enter the number of customers for the subscriber["<<i+1<<"] :  ";
        cin>>arr1[i];
        cout<<"Enter the address : ";
        cin>>arr2[i];
        sum+=arr1[i]*arr2[i];
    }
    int n=pow(2,32-cidr);
    cout<<"\nTotal number of address : "<<n;
    cout<<"\nNumber of alloted slots : "<<sum;
    cout<<"\nBalance slots that are free : "<<n-sum<<endl;
    for(int i=0;i<=no_subcriber-1;i++){
        cout<<"\nSubscriber "<<i+1<<endl;
        int cirdsub=32-value(arr1[i]);
        cout<<"\nCIDR value  : "<<cirdsub;
        cout<<"\nStarting address : ";
        for(int i=0;i<=2;i++){
            cout<<ip[i]<<".";
        }
        cout<<ip[3];
        cout<<"/"<<cirdsub;
        for(int l=1;l<=arr1[i]*arr2[i]-1;l++){
            
                if(ip[3]<255 ){
                    ip[3]++;
                }
                else if(ip[3]==255 && ip[2]<255 ){
                    ip[3]=0;
                    ip[2]++;
                } 
                else if(ip[3]==255 && ip[2]==255 && ip[1]<255){
                    ip[2]=0;
                    ip[1]++;
                }
                else if(ip[3]==255 && ip[2]==255 && ip[1]==255){
                    ip[1]=0;
                    ip[0]++;
                }   
            
        }
        cout<<"\nEnd address : ";
        for(int i=0;i<=2;i++){
            cout<<ip[i]<<".";
        }
        cout<<ip[3];
        cout<<"/"<<cirdsub;
        cout<<endl;
        if(ip[3]<255 ){
            ip[3]++;
        }
        else if(ip[3]==255 && ip[2]<255 ){
            ip[3]=0;
            ip[2]++;
        } 
        else if(ip[3]==255 && ip[2]==255 && ip[1]<255){
            ip[2]=0;
            ip[1]++;
        }
        else if(ip[3]==255 && ip[2]==255 && ip[1]==255){
            ip[1]=0;
            ip[0]++;
        }        
    }     
}