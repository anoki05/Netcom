import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException; 
import java.net.ServerSocket;
import java.net.Socket; 

public class bytestuffingserver {
    public static void main(String[] args) throws IOException {
        ServerSocket servsock = new ServerSocket(45678);
        Socket socket = servsock.accept();
        DataInputStream dis = new DataInputStream(socket.getInputStream());
        DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
        while (true) {
            String out = new String();
            String res = dis.readUTF();
            System.out.println("Message Recevied...Successfully!!!");
            System.out.println("The Stuffed Message is : " + res);
            for (int i = 1; i < res.length() - 1; i++) {
                if (res.charAt(i) == 'E' )
                    i++;
                if(i!=res.length()-1)
                    out+=res.charAt(i);
            }
            System.out.println("The Destuffed Message is : " + out);
            dos.writeUTF("success");
            String ch = dis.readUTF();
            if (ch.equals("bye")) {
                System.out.println("Messaging is over.....EXITING");
                break;
            }
        }
        socket.close();
        dis.close();
        dos.close();
    }
}