import java.io.*;
import java.net.*;
import java.util.*; 

public class checksumserver
{
	public static void main(String args[]) throws IOException
	{
		// Server
		ServerSocket servsock = new ServerSocket(50000);
		Socket socket = servsock.accept();		
		DataInputStream dis = new DataInputStream(socket.getInputStream());
		DataOutputStream dos = new DataOutputStream(socket.getOutputStream());		
		while (true)
		{
			Scanner sc = new Scanner(System.in);
			int i, l, nob, sum = 0, chk_sum;
			l = dis.readInt();
			int c_data[] = new int[l]; 
			int data[] = new int[l];
			System.out.println("Data received (alond with checksum) is");
			for(i = 0; i< data.length; i++)
			{
				data[i] = dis.readInt();
				System.out.println(data[i]);
				nob = (int)(Math.floor(Math.log(data[i]) / Math.log(2))) + 1;
				c_data[i] = ((1 << nob) - 1) ^ data[i];
				sum += c_data[i];
			}
			System.out.println("Sum(in ones complement) is : "+sum);
			nob = (int)(Math.floor(Math.log(sum) / Math.log(2))) + 1;
			sum = ((1 << nob) - 1) ^ sum;
			System.out.println("Calculated Checksum is : "+sum);
			if(sum == 0)
			{
				dos.writeUTF("success");
				break;
			}	
			else
			{
				dos.writeUTF("failure");
				break;
			}
		}
		dis.close();
		dos.close();
		socket.close();
	}
}