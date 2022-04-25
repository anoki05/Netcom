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
using namespace std;
string xor1(string a, string b)
{
    string result = "";     
    int n = b.length();       
    for(int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}
string mod2div(string divident, string divisor)
{
    int pick = divisor.length();
    string tmp = divident.substr(0, pick);     
    int n = divident.length();     
    while (pick < n)
    {
        if (tmp[0] == '1')
            tmp = xor1(divisor, tmp) + divident[pick];
        else
            tmp = xor1(std::string(pick, '0'), tmp) +divident[pick];
        pick += 1;
    }
    if (tmp[0] == '1')
        tmp = xor1(divisor, tmp);
    else
        tmp = xor1(std::string(pick, '0'), tmp);
         
    return tmp;
}
void encodeData(string data, string key)
{
    int l_key = key.length();
    string appended_data = (data + std::string(l_key - 1, '0'));     
    string remainder = mod2div(appended_data, key);
    string codeword = data + remainder;
    cout << "Remainder : "<< remainder << "\n";
    cout << "Encoded Data  :"<< codeword << "\n";
}
void decodedData(string codedata,string key){
    int l_key = key.length();
    string remainder = mod2div(codedata, key);
    int flag=0;
    for(int i=0;i<remainder.length();i++){
        if(remainder[i]=='0'){
            flag=1;
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag==1){
        cout<<"No error";
    }
    else{cout<<"Error is present ";}
}
int main()
{
    int choice;
    string data = "";
    string divisor = "";
    string codedata="";
    do{
    cout<<"\n\n\n~~~~~~~~~~~~          Menu           ~~~~~~~~~~~~\n";
    cout<<"\n1.Sender Side Operations";
    cout<<"\n2.Receiver Side Operations ";
    cout<<"\n3.Exit";
    cout<<"\n\nEnter you choice : ";
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"~~~~~~~~~~~~   Sender side details   ~~~~~~~~~~~~ ";
            cout<<"\nSender Side:";     
            cout<<"\nEnter the data to be transmitted : ";
            cin>>data;
            cout<<"Enter the divisor : ";
            cin>>divisor;
            encodeData(data, divisor);
            break;
        case 2:
            cout<<"\n~~~~~~~~~~~~   Receiver side details   ~~~~~~~~~~~~ ";
            cout<<"\nReceiver Side:";
            cout<<"\nEnter the codedata to be checked : ";
            cin>>codedata;
            cout<<"Is the codedata for the same data entered ? 1/0 : ";
            int op;
            cin>>op;
            if(op == 0){
                cout<<"Enter the divisor : ";
                cin>>divisor;
            }
            decodedData(codedata,divisor);
            break;
        case 3:
            cout<<"The program ends here!";
            cout<<endl;
            return 0;
        default:
            cout<<"\nPlease enter a valid input !! ";
            break;
            
    }
    }while(choice!=3);
    return 0;
}