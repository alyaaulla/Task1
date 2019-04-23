import java.io.*;
	import java.net.*;
	
	public class client{
		public static void main(String[] args) throws IOException{
	
		Socket serverSocket = new Socket("192.168.146.129",50000);
	
		System.out.println("Server connected");
		
		InputStreamReader gt = new InputStreamReader(serverSocket.getInputStream());
		BufferedReader ot = new BufferedReader(gt);
	
		PrintWriter rp = new PrintWriter(serverSocket.getOutputStream());
	
		rp.println("ni hao");
		rp.flush();
	
		String recvr = ot.readLine();
		System.out.println(recvr);
		}
	}
Client.java

