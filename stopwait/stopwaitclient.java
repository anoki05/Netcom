//SENDER//
import java.io.*;
import java.net.*;
import java.util.Scanner;
public class stopwaitclient
{
    public static void main(String args[])throws IOException{
        InetAddress ip = InetAddress.getLocalHost();
        int port =5000;
        Socket s = new Socket(ip,port);
        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of packets to be dent : ");
        int n= sc.nextInt();
        System.out.println("Enter the packet numbers one by one : ");
        int [] frame = new int[n];
        for(int i=0;i<n;i++){
            frame[i]=sc.nextInt();
        }
        System.out.println("Sending the frame size : ");
        dos.write(n);
        dos.flush();
        System.out.println("Sending the data packets one bye one : ");
        // if data lost case :
        int flag=1; 
        for(int i=0;i<n;i++){
            System.out.println("Sending the frame : "+frame[i]);
            dos.write(frame[i]);
            dos.flush();     
            if(flag==1){
                dos.writeUTF("success");
                int N= dis.read();
                if(N==1){
                    System.out.println("Acknowedgement received for frame "+frame[i]);
                }
                else if(N==0){
                    System.out.println("Acknowledgement is not received ");
                    System.out.println("Timeout!!");
                    System.out.println("Resending the frame "+frame[i]);
                    System.out.println("Acknowedgement received for frame "+frame[i]);
                }
            }  
            else{
                dos.writeUTF("failure");
                System.out.println("Data packet is lost in the middle : ");
                System.out.println("Timeout!!");
                System.out.println("Resending the frame "+frame[i]);
                System.out.println("Acknowedgement received for frame "+frame[i]);
                flag=1;

            }    
            
        }
        System.out.println("All the frames have been sent successfully!");
        System.out.println("Completed !");
        s.close();
        dis.close();
        dos.close();
    }
}