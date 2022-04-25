//Nirali codes :)
#include <iostream>
#include <string>
using namespace std;
int main()
{
    // BIT STUFFING
    //sender side 
    string str;
    cout<<"\nEnter a data string to be sent             :";
    cin>>str;
    string receivercode;
    receivercode+='$';
    for(int i=0;i<=str.size();i++){        
        if(str[i] == '$' || str[i]=='@'){
            receivercode+='@';
        }   
        receivercode+=str[i];     
    }
    receivercode+='$';
    cout<<"\nThe data received at the receiver end is   :";
    cout<<receivercode;
    //receiving side 
    string rec;
    cout<<"\n\nEnter the transmitted data received       :";
    cin>>rec;
    string data;
    for(int i=1;i<rec.size()-1;i++){
        if(rec[i]=='@'){
            i++;
        }
        if(i!=rec.size()-1)
        data+=rec[i];
    }
    cout<<"\nThe data recoded at the receiving end      :";
    cout<<data;
}