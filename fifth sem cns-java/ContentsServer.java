import java.io.*;
import java.net.*;
public class ContentsServer {
    public static void main(String[] args)throws Exception{
        ServerSocket sersock = new ServerSocket(4000);
        System.out.println("Server ready for connection ");
        Socket sock = sersock.accept();
        System.out.println("Connection successful .waiting for chatting");

        InputStream istream = sock.getInputStream();
        BufferedReader bf = new BufferedReader(new InputStreamReader(istream));
        String filename = bf.readLine();

        OutputStream ostream = sock.getOutputStream();
        BufferedReader bf2 = new BufferedReader(new FileReader(filename));
        PrintWriter pwrite = new PrintWriter(ostream,true);

        String str;
        while ((str= bf2.readLine())!=null){
            pwrite.println(str);
        }
        bf.close();
        bf2.close();
        pwrite.close();
        sersock.close();
    }
}