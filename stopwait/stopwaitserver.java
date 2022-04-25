import java.io.*;
import java.net.*;
public class stopwaitserver
{
    public static void main(String args[])throws Exception
    {
        ServerSocket socket = new ServerSocket(5000);
        Socket s = socket.accept();
        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        int n = dis.read();
        System.out.println("The number of frames that are being sent is "+n);
        int [] frame = new int[n];
        System.out.println("Data Packets are received one by one ....");
        // if acknowledgement lost case:flag=0;
        int flag=1;
        for(int i=0;i<n;i++){
            frame[i]=dis.read();
            String a = dis.readUTF();
            System.out.println("Received frame: "+frame[i]);
            System.out.println("Acknowledgement sent"+frame[i]);
            if(flag==1){
                dos.write(1);
            }
            else{
                dos.write(0);
                System.out.println("Acknowlegment is lost in the middle !");
                flag=1;
            }            
        }
        System.out.println("All the frames are received successfully");
        System.out.println("Completed !");
        s.close();
        dis.close();
        dos.close();
    }
}