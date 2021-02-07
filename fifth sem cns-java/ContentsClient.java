import java.io.*;
import java.net.*;

public class ContentsClient {
    public static void main(String[] args)throws Exception{
        Socket sock = new Socket("127.0.01", 4000);
        System.out.println("Enter the filename:");
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String fname = bf.readLine();

        OutputStream ostream = sock.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream,true);
        pwrite.println(fname);

        InputStream istream = sock.getInputStream();
        BufferedReader bf2 = new BufferedReader(new InputStreamReader(istream));
        String str;
        while ((str = bf2.readLine())!=null){
            System.out.println(str);
        }
        pwrite.close();
        bf.close();
        bf2.close();
    }
}