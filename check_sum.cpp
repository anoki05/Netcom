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

string HexToBin(string hexdec)
{
    long int i = 0;
    string binary_number="";
    for(int i=0;i<hexdec.length();i++) {
 
        switch (hexdec[i]) {
        case '0':
            binary_number+="0000";
            break;
        case '1':
            binary_number+="0001";
            break;
        case '2':
            binary_number+="0010";
            break;
        case '3':
            binary_number+="0011";
            break;
        case '4':
            binary_number+="0100";
            break;
        case '5':
            binary_number+="0101";
            break;
        case '6':
            binary_number+="0110";
            break;
        case '7':
            binary_number+="0111";
            break;
        case '8':
            binary_number+="1000";
            break;
        case '9':
            cout << "1001";
            break;
        case 'A':
        case 'a':
            binary_number+="1010";
            break;
        case 'B':
        case 'b':
            binary_number+="1011";
            break;
        case 'C':
        case 'c':
            binary_number+="1100";
            break;
        case 'D':
        case 'd':
            binary_number+="1101";
            break;
        case 'E':
        case 'e':
            binary_number+="1110";
            break;
        case 'F':
        case 'f':
            binary_number+="1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit ";
        }
    }
    return binary_number;
}
string complement_func(string data)
{
    for (int i = 0; i < data.length(); i++) {
        if (data[i] == '0')
            data[i] = '1';
        else
            data[i] = '0';
    }
    return data;
}
string checkSum_func(string data, int size)
{
    int n = data.length();
    if (n % size != 0) {
        int pad_size = size - (n % size);
        for (int i = 0; i < pad_size; i++) {
            data = '0' + data;
        }
    }
    string result = "";
    for (int i = 0; i < size; i++) {
        result += data[i];
    }
    for (int i = size; i < n; i += size) {
        string next_block = "";
 
        for (int j = i; j < i + size; j++) {
            next_block += data[j];
        }
        string additions = "";
        int sum = 0, carry = 0;
        for (int k = size - 1; k >= 0; k--) {
            sum += (next_block[k] - '0')+ (result[k] - '0');
            carry = sum / 2;
            if (sum == 0) {
                additions = '0' + additions;
                sum = carry;
            }
            else if (sum == 1) {
                additions = '1' + additions;
                sum = carry;
            }
            else if (sum == 2) {
                additions = '0' + additions;
                sum = carry;
            }
            else {
                additions = '1' + additions;
                sum = carry;
            }
        }
        string final = "";
 
        if (carry == 1) {
            for (int l = additions.length() - 1; l >= 0;l--) {
                if (carry == 0) {
                    final = additions[l] + final;
                }
                else if (((additions[l] - '0') + carry) % 2== 0) {
                    final = "0" + final;
                    carry = 1;
                }
                else {
                    final = "1" + final;
                    carry = 0;
                }
            }
 
            result = final;
        }
        else {
            result = additions;
        }
    }
    return complement_func(result);
}
bool checker(string sent_message,string rec_message,int block_size) 
{
 
    string sender_checksum = checkSum_func(sent_message, block_size);

    string receiver_checksum = checkSum_func(rec_message + sender_checksum, block_size);
 
    if (count(receiver_checksum.begin(),receiver_checksum.end(), '0')== block_size) {
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    int opt;
    
    do{
    cout<<"\n~~~~~~~~~~~~~~~   Menu   ~~~~~~~~~~~~~~~"<<endl;
    cout<<"1) Sender and receiver message is given in binary format "<<endl;
    cout<<"2) Sender and receiver message is given in hexadecimal format "<<endl;
    cout<<"3) Exit "<<endl;
    cout<<endl<<"Enter your option : ";
    cin>>opt;
    string sender_message;
    string hex;
    string receiver_message;
    switch(opt){
        case 1:
            cout<<"\nSender side details\n\n";
            cout<<"Enter the sender's message : ";
            cin>>sender_message;
            cout<<"\nReceiver side details\n\n";
            cout<<"Enter the receiver's message : ";
            cin>>receiver_message;
            if(sender_message.length()==receiver_message.length()){
                if (checker(sender_message,receiver_message,sender_message.length()/4)) {
                cout << endl<<"No Error"<<endl;
                }
                else {
                    cout <<endl<< "Error"<<endl;
                }
            }  
            else{
                cout<<"The sender's length is not equal to receiver's length, Please enter correct message!";
            }  
            break;
        case 2:
            int n;
            cout<<"\nSender side details\n\n";
            cout<<"Enter the number of bit : ";
            cin>>n;
            cout<<"Enter the sender's message(bit by bit) : "<<endl;
            for(int i=0;i<n;i++){
                cin>>hex;
                sender_message+=HexToBin(hex);
            }
            cout<<"\nReceiver side details\n\n";
            cout<<"Enter the number of bit : ";
            cin>>n;
            cout<<"Enter the receiver's message(bit by bit) : "<<endl;
            for(int i=0;i<n;i++){
                cin>>hex;
                receiver_message+=HexToBin(hex);
            }
            if(sender_message.length()==receiver_message.length()){
                if (checker(sender_message,receiver_message,sender_message.length()/4)) {
                cout << endl<<"No Error"<<endl;
                }
                else {
                    cout <<endl<< "Error"<<endl;
                }
            }  
            else{
                cout<<"The sender's length is not equal to receiver's length, Please enter correct message!\n";
            }
            break;
        case 3:
            cout<<endl<<"The code ends here !"<<endl;
            return 0;
            break;
        default:
            cout<<"PLease enter a valid option ";
    }
    }while(opt!=3);
    return 0;
}