import java.util.*;
import java.net.*;
import java.io.*;
public class crcclient {
    static String xor1(String a, String b)
    {
        String result = new String();     
        int n = b.length();       
        for(int i = 1; i < n; i++)
        {
            if (a.charAt(i) == b.charAt(i))
                result += "0";
            else
                result += "1";
        }
        return result;
    }
    static String mod2div(String divident, String divisor)
    {
        int pick = divisor.length();
        String tmp = divident.substring(0, pick);     
        String str="0";
        int n = divident.length();     
        while (pick < n)
        {
            if (tmp.charAt(0) == '1')
                tmp = xor1(divisor, tmp) + divident.charAt(pick);
            else
                tmp = xor1(str.repeat(pick), tmp) +divident.charAt(pick);
            pick += 1;
        }
        if (tmp.charAt(0) == '1')
            tmp = xor1(divisor, tmp);
        else
            tmp = xor1(str.repeat(pick), tmp);
            
        return tmp;
    }
    static String encodeData(String data, String key)
    {
        int l_key = key.length();
        String str="0";
        String appended_data = (data + str.repeat(l_key-1));     
        String remainder = mod2div(appended_data, key);
        String codeword = data + remainder;
        System.out.println("Remainder : "+ remainder+"\n");
        System.out.println("Encoded Data  :"+ codeword +"\n");
        return codeword;
    }
    public static void main(String args[])throws IOException{
        Scanner sc = new Scanner(System.in);
        InetAddress ip = InetAddress.getLocalHost();
        int port =5000;
        Socket s = new Socket(ip,port);
        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        while(true){
            System.out.println("Enter the data to be transmitted :");
            String data = sc.nextLine();
            System.out.println("Enter the divisor : ");
            String divisor = sc.nextLine();
            String codeword = new String();
            codeword = encodeData(data, divisor);
            System.out.println("Sending the encoded data ....");
            dos.writeUTF(codeword);
            System.out.println("Sending the generator ...");
            dos.writeUTF(divisor);
            if(dis.readUTF().equals("success")){
                System.out.println("Success!!");
            }
            break;
        }
        s.close();
        dis.close();
        dos.close();
    }
}
