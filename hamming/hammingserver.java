import java.util.*;
import java.lang.*;
import java.io.*;
import java.net.*;
public class hammingserver {
    static int value_of_r_receiver(int a){
        int flag=1;
        int r=0;
        while(flag==1){
            r++;
            if(Math.pow(2,r)>a){
                flag=0;
            }
        }
        return r;
    }
    static int binary_to_decimal(int n){
        int dec_value = 0;
        int base = 1; 
        int temp = n;
        while (temp!=0) {
            int last_digit = temp % 10;
            temp = temp / 10;
            dec_value += last_digit * base;
            base = base * 2;
        } 
        return dec_value;
    }
    static void receiver(int m,int r,int s[], int syn[]){
        int k=0,j=0;
        int x,min,max=0,parity;
        for(int i=1;i<=m+r;i=(int) Math.pow(2,k)){
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
    public static void main(String args[])throws IOException{
        int port =50000;
        ServerSocket socket = new ServerSocket(port);
        Socket s = socket.accept();
        Scanner sc = new Scanner(System.in);
        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        while(true){
            int n;
            n= dis.read();            
            int[] code = new int[n+1];
            for(int i=1;i<=n;i++){
                code[i]=dis.read();
            }
            System.out.println("Received the code successfully !");
            int r=value_of_r_receiver(n);
            int m=n-r;
            int [] syn = new int[m];
            receiver(m,r , code,  syn);
            int num=0;
            for(int i=0;i<r;i++){
                num+=syn[i] * Math.pow(10,i);
            }  
            if(num==0){
                System.out.println("No error !");
            }
            else{
                System.out.println("Eroor occurs at the index of "+binary_to_decimal(num));
                System.out.println("The correct code is : ");
                if(code[binary_to_decimal(num)]==1){
                    code[binary_to_decimal(num)]=0;
                }
                else{
                    code[binary_to_decimal(num)]=1;
                }
                for(int i=1;i<=n;i++){
                    System.out.print(code[i]+" ");
                }
            }
            dos.writeUTF("success");
            
            break;
        }
        s.close();
        dis.close();
        dos.close();
    }
}
