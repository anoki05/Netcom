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

int operation(int a,int lost_frames[],int t){
    int flag=0;
    for(int j=0;j<t;j++){
        if(lost_frames[j]==a){
            flag=1;
        }
    }
    return flag;
}

void case1(int frames[], int n,int m){
    int i=0;
    while(i<n){
        int x=0;
        for(int j=i;j<i+m && j<n;j++){
            cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
            cout<<"\nSender sends frame "<<frames[j]<<"\t\t";
            cout<<"\tReceiver receives frame  "<<frames[j];
        }
        for(int j=i;j<i+m && j<n;j++){
            cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[j];
            cout<<"\nAcknowledgement received "<<frames[j]<<"\n";
            x++;
        }
        i+=x;
    }
    cout<<endl<<endl;
}

void data_lost(int frames[], int n,int m){
    int t;
    cout<<"\nEnter the number of frames you want to get lost ";
    cin>>t;
    int lost_frames[t];
    cout<<"Enter the frame numbers one by one ";
    for(int i=0;i<t;i++){
        cin>>lost_frames[i];
    }
    int i=0;
    int b=0;
    while(i<n){
        int x=0;
        for(int j=i;j<i+m && j<n;j++){
            int flag = operation(frames[j],lost_frames,t);
            if(flag==0){
                cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
                cout<<"\nSender sends frame "<<frames[j]<<"\t\t";
                cout<<"\tReceiver receives frame  "<<frames[j];
            }
            else{
                cout<<"\nSender sends frame "<<frames[j]<<"\t\t";
                cout<<"\nGets lost in the middle\n";
                cout<<"\n\t\t\t\t\tReceiver does not receive any frame";
            }
            
        }
        for(int j=i;j<i+m && j<n;j++){
            int flag = operation(frames[j],lost_frames,t);
            if(flag==0){
                cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[j];
                cout<<"\nAcknowledgement received "<<frames[j]<<"\n";
                x++;
            }
            else{
                cout<<"\n\t\t\t\t\tNAK("<<frames[j]<<")"<<endl;
                cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
                cout<<"\nSender resends frame "<<frames[j]<<"\t\t";
                cout<<"\tReceiver receives frame  "<<frames[j];
                cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[j];
                cout<<"\nAcknowledgement received "<<frames[j]<<"\n";
                x++;
            }
        }
        i+=x;
    }
    cout<<endl<<endl;
}

void acknowledgement_lost(int frames[], int n,int m){
    int t;
    cout<<"Enter the number of frames for which the sender does receive the acknowledge : ";
    cin>>t;
    int lost_frames[t];
    cout<<"\nEnter the frame numbers one by one : ";
    for(int i=0;i<t;i++){
        cin>>lost_frames[i];
    }
    int i=0;
    while(i<n){
        int x=0;
        for(int j=i;j<i+m && j<n;j++){        
                cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
                cout<<"\nSender sends frame "<<frames[j]<<"\t\t";
                cout<<"\tReceiver receives frame  "<<frames[j];
        }
        for(int j=i;j<i+m && j<n;j++){
            int flag = operation(frames[j],lost_frames,t);
            if(flag==0){
                cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[j];
                cout<<"\nAcknowledgement received "<<frames[j]<<"\n";
                x++;
            }
            else{
                cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[j];
                cout<<"\nAcknowledgement lost in the middle";
                // cout<<"\n\t\t\t\t\tNAK("<<frames[j]<<")"<<endl;
                cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
                cout<<"\nSender resends frame "<<frames[j]<<"\t\t";
                cout<<"\tReceiver receives frame  "<<frames[j];
                cout<<"\n\t\t\t\t\tAcknowledgement sent  "<<frames[j];
                cout<<"\nAcknowledgement received "<<frames[j]<<"\n";
                x++;
            }
        }
        i+=x;
    }
    cout<<endl<<endl;
}

int main()
{
    
    int option;
    cout<<"\nSelective Repeat Protocol";
    cout<<"\nEnter the required details "<<endl;
    int n,m;
    cout<<"\nEnter the number of frames : ";
    cin>>n;
    int frames[n];
    for(int i=0;i<n;i++){
        frames[i]=i+1;
    }
    cout<<"\nEnter the size of the window : ";
    cin>>m;
    do{
    cout<<"\nSelective Repeat Protocol";
    cout<<"\n------------------- Possible cases -------------------"<<endl;
    cout<<"1. Frame sent and received the acknowledgement within the time"<<endl;
    cout<<"2. Data lost"<<endl;
    cout<<"3. Acknowledgement lost"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"\nEnter the situation you want to see how this prorocol works :  "<<endl;
    cin>>option;
    switch(option){
        case 1:
            cout<<"\nThe situation choosen is Frame sent and received the acknowledgement within the time"<<endl;
            case1(frames,n,m);
            break;
        case 2:
            cout<<"\nThe situation choosen is Data lost case"<<endl;
            data_lost(frames,n,m);
            break;
        case 3:
            cout<<"\nThe situation choosen is Acknowledgement lost case"<<endl;
            acknowledgement_lost(frames,n,m);
            break;
        case 4:
            cout<<"The program ends here !";
            return 0;
            break;
        default:
            cout<<"Please enter a valid option !!";
            break;
    }
    }while(option!=4);
}