import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner; 
  
public class bytestuffingclient {
    public static void main(String args[]) throws IOException {
        InetAddress ip = InetAddress.getLocalHost();
        int port = 45678;
        Scanner sc = new Scanner(System.in);
        Socket s = new Socket(ip, port);
        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        while (true) {
            System.out.println("Enter the Message to be Sent : ");
            String data = sc.nextLine();
            String res = new String();
            data = 'F' + data + 'F';
            for (int i = 0; i < data.length(); i++) {
                if (data.charAt(i) == 'F' && i != 0 && i != (data.length() - 1))
                    res = res + 'E' + data.charAt(i);
                else if (data.charAt(i) == 'E')
                    res = res + 'E' + data.charAt(i);
                else
                    res = res + data.charAt(i);
            }
            System.out.println("The data being sent (with byte stuffed) is : " + res);
            dos.writeUTF(res);
            System.out.println("Seding Message....");
            if (dis.readUTF().equals("success"))
                System.out.println("Thanks for the Feedback Server!!");
            dos.writeUTF("bye");
            break;
        }
        s.close();
        dis.close();
        dos.close();
    }
}