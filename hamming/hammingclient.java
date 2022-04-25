import java.util.*;
import java.io.*;
import java.net.*;
import java.lang.*;
public class hammingclient {
    static int value_of_r_sender(int n){
        int r=0;
        int flag=1;
        while(flag==1){
            r++;
            int a= r+n;
            if(a<Math.pow(2,r))
                flag=0;
        }
        return r;
    }
    static int calculate_one(int a){
        int count=0;
        while(a!=0){
            count+= a&1;
            a>>=1;
        }
        return count;
    }
    static void sender(int m,int r ,int ham[] ){
        int k=0;
        int x,min,max=0,parity,j;
        for(int i=1;i<=m+r;i=(int) Math.pow(2,k)){
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
    public static void main(String args[]) throws IOException,SocketException{
        InetAddress ip = InetAddress.getLocalHost();
        int port = 50000;
        Scanner sc = new Scanner(System.in);
        Socket s = new Socket(ip, port);
        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        while(true){
            System.out.println("Enter the number of bits : ");
            int n= sc.nextInt();
            int[] data = new int[n+1];
            System.out.println("Enter the data one by one : ");
            for(int i=1;i<=n;i++){
                data[i]=sc.nextInt();
            }
            int r = value_of_r_sender(n);
            int k=1;
            int[] ham = new int[r+n+1];
            for(int i=1;i<=r+n;i++){
                if(calculate_one(i)==1){
                    ham[i]=-1;}
                  else{
                    ham[i]=data[k];
                    k++;
                }
            }
            sender(n,r,ham);
            System.out.println("The Hammed code for the given data is : ");
            for(int i=1;i<=n+r;i++){
                System.out.print(ham[i]+" ");
            }
            System.out.println("Sending the size of the data : ");
            dos.write(n+r);
            dos.flush();
            System.out.println("Sending the hammed code : ");
            // Inducing an error!
            ham[1]=1;
            for(int i=1;i<=n+r;i++){
                dos.write(ham[i]);
                dos.flush();
            }
            if(dis.readUTF().equals("success")){
                System.out.println("COmpleted!!");
            }
            break;            
        }
        s.close();
        dis.close();
        dos.close();
    }
}