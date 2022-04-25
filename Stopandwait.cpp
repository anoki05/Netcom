//Nirali codes :)
#include <iostream>
#include <iterator>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
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
void case1(int frames[], int n){
    for(int i=0;i<n;i++){
        cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
        cout<<"\nSender sends frame "<<frames[i]<<"\t\t";
        cout<<"\tReceiver receives frame  "<<frames[i];
        cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[i];
        cout<<"\nAcknowledgement received "<<frames[i]<<"\n";
    }
    cout<<endl<<endl;
}
void lost_data(int frames[],int n){
    int t;
    cout<<"\nEnter the number of frames you want to get lost ";
    cin>>t;
    int lost_frames[t];
    cout<<"\nEnter the frame numbers one by one ";
    for(int i=0;i<t;i++){
        cin>>lost_frames[i];
    }
    for(int i=0;i<n;i++){
        cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
        int flag = operation(frames[i],lost_frames,t);
        if(flag==0){
            cout<<"\nSender sends frame "<<frames[i]<<"\t\t";
            cout<<"\tReceiver receives frame  "<<frames[i];
            cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[i];
            cout<<"\nAcknowledgement received "<<frames[i]<<"\n";
        }
        else{
            cout<<"\nSender sends frame "<<frames[i]<<"\t\t";
            cout<<"\nGets lost in the middle\n";
            cout<<"\n\nTimeout!!";
            cout<<"\n\t\t\t\t\tReceiver does not receive any frame";
            cout<<"\nSender resends the frame "<<frames[i]<<"\t\t";
            cout<<"Receiver receives frame  "<<frames[i];
            cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[i];
            cout<<"\nAcknowledgement received" <<frames[i]<<"\n";

        }
    } 
    cout<<endl<<endl;    

}
void lost_acknowledgement(int frames[],int n)
{
    int t;
    cout<<"Enter the number of frames for which the sender does receive the acknowledge : ";
    cin>>t;
    int lost_frames[t];
    cout<<"\nEnter the frame numbers one by one : ";
    for(int i=0;i<t;i++){
        cin>>lost_frames[i];
    }
    for(int i=0;i<n;i++){
        cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
        int flag=operation(frames[i],lost_frames,t);
        if(flag==0){
            cout<<"\nSender sends frame "<<frames[i]<<"\t\t";
            cout<<"\tReceiver receives frame  "<<frames[i];
            cout<<"\n\t\t\t\t\tAcknowledgement sent ";
            cout<<"\nAcknowledgement received\n";
        }
        else{
            cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
            cout<<"\nSender sends frame "<<frames[i]<<"\t\t";
            cout<<"\tReceiver receives frame  "<<frames[i];
            cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[i];
            cout<<"\nAcknowledgement is lost in the middle";
            cout<<"\n\nTimeout!!";
            cout<<"\nAcknowledgement is not received";
            cout<<"\nSender resends the frame "<<frames[i]<<"\t\t";
            cout<<"Receiver receives frame  "<<frames[i];
            cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[i];
            cout<<"\nAcknowledgement received  "<<frames[i]<<"\n";

        }
    }
    cout<<endl<<endl;

}
void deyaled_acknowledgement(int frames[],int n){
    int t;
    cout<<"Enter the number of frames for which the sender does receive the acknowledgement late ie. delayed : ";
    cin>>t;
    int lost_frames[t];
    cout<<"\nEnter the frame numbers one by one : ";
    for(int i=0;i<t;i++){
        cin>>lost_frames[i];
    }
    for(int i=0;i<n;i++){
        cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
        int flag=operation(frames[i],lost_frames,t);
        if(flag==0){
            cout<<"\nSender sends frame "<<frames[i]<<"\t\t";
            cout<<"\tReceiver receives frame  "<<frames[i];
            cout<<"\n\t\t\t\t\tAcknowledgement sent ";
            cout<<"\nAcknowledgement received\n";
        }
        else{
            cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
            cout<<"\nSender sends frame "<<frames[i]<<"\t\t";
            cout<<"\tReceiver receives frame  "<<frames[i];
            cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[i];
            cout<<"\n\nTimeout!!";
            i++;
            cout<<"\nSender sends frame "<<frames[i]<<"\t\t";
            cout<<"\nAcknowledgement received\n";
            cout<<"\n(This acknowledgement is for the frame "<<frames[i-1];
            cout<<"\n\t\t\t\t\tReceiver receives frame  "<<frames[i];
            cout<<"\n\t\t\t\t\tAcknowledgement sent "<<frames[i];
            cout<<"\nAcknowledgement received  "<<frames[i]<<"\n";
        }
    }
    cout<<endl<<endl;
}

int main()
{
    
    int option;
    cout<<"\nStop and wait protocol ";
    cout<<"\nEnter the required details "<<endl;
    int n;
    cout<<"\nEnter the total number of frames : ";
    cin>>n;
    int frames[n];
    cout<<"Enter the frames one by one : ";
    for(int i=0;i<n;i++){
        cin>>frames[i];
    }
    int time;
    // cout<<"\nEnter the time ";
    // cin>>time;
    do{
    cout<<"\nStop and wait protocol ";
    cout<<"\n------------------- Possible cases -------------------"<<endl;
    cout<<"1. Frame sent and received the acknowledgement within the time"<<endl;
    cout<<"2. Data lost"<<endl;
    cout<<"3. Lost acknowledgement "<<endl;
    cout<<"4. Delayed acknowledgement "<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter the situation you want to see how this prorocol works :  "<<endl;
    cin>>option;
    switch(option){
        case 1:
            cout<<"\nThe situation choosen is Frame sent and received the acknowledgement within the time"<<endl;
            case1(frames,n);
            break;
        case 2:
            cout<<"The situation choosen is Data Lost case"<<endl;
            lost_data(frames,n);
            break;
        case 3:
            cout<<"The situation choosen is Lost acknowledgement"<<endl;
            lost_acknowledgement(frames,n);
            break;
        case 4:
            cout<<"The situation choosen is Delayed acknowledgement"<<endl;
            deyaled_acknowledgement(frames,n);
            break;
        case 5:
            cout<<"The program ends here !";
            return 0;
            break;
        default:
            cout<<"Please enter a valid option !!";
            break;
    }
    }while(option!=4);
}