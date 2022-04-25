
import java.util.*;
import java.net.*;
import java.io.*;

public class crcserver {
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
    static void decodeData(String codeword, String key)
    {
        String remainder = mod2div(codeword, key);
        int flag=0;
        for(int i=0;i<remainder.length();i++){
        if(remainder.charAt(i)=='0'){
            flag=1;
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag==1){
        System.out.println("No error");
    }
    else{System.out.println("Error is present ");}
    }
    public static void main(String args[])throws IOException{
        ServerSocket socket = new ServerSocket(5000);
        Socket s = socket.accept();
        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        while(true){
            String encoded_data = new String();
            encoded_data= dis.readUTF();
            String divisor = new String();
            divisor = dis.readUTF();
            System.out.println("Message Recevied...Successfully!!!");
            decodeData(encoded_data, divisor);
            dos.writeUTF("success");
            break;
        }        
    }
}