import java.util.Scanner;
public class CRC {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] data;
        int[] divisor;
        int[] div;
        int[] rem;
        int[] crc;
        int data_bits, divisor_bits, tot_length;

        /* ask and store length and contents of databits in data array */
        System.out.println("Enter the number of data bits:");
        data_bits  = sc.nextInt();
        data = new int[data_bits];
        System.out.println("enter the data bits:");
        for (int i = 0;i<data_bits;i++)
            data[i] = sc.nextInt();

        /* ask and store length and contents of divisor in divisor array */
        System.out.println("Enter the number of divisor bits:");
        divisor_bits  = sc.nextInt();
        divisor = new int[divisor_bits];
        System.out.println("enter the divisor bits:");
        for (int i = 0;i<divisor_bits;i++)
            divisor[i] = sc.nextInt();

        tot_length = data_bits+divisor_bits-1;
        div = new int[tot_length];
        rem = new int[tot_length];
        crc = new int[tot_length];
        for (int i = 0;i<data_bits;i++)
            div[i] = data[i];
        System.out.println("Data word after appending 0s:");
        for (int i= 0;i<div.length;i++)
            System.out.println(div[i]);

        for (int i= 0;i<div.length;i++)
            rem[i] = div[i];

        rem = divide(div,divisor,rem);

        for (int i= 0;i<div.length;i++)
            crc[i] = div[i]^rem[i];
        System.out.println("CRC code:");
        for (int i= 0;i<crc.length;i++)
            System.out.println(crc[i]);

        System.out.println("Enter the CRC code of length "+tot_length +":");
        for (int i = 0;i<tot_length;i++)
            crc[i] = sc.nextInt();
        for (int i= 0;i<crc.length;i++)
            rem[i] = crc[i];
        rem = divide(crc, divisor, rem);
        for (int i= 0;i<rem.length;i++){
            if(rem[i] !=0){
                System.out.println("Error");
                break;
            }
            if(i == rem.length-1)
                System.out.println("No Error");
        }

    }

    static int[] divide(int[] div, int[] divisor, int[] rem){
        int cur =0;
        do {
            for (int i = 0; i < divisor.length; i++)
                rem[cur + i] ^= divisor[i];
            while ((rem[cur] == 0 )&&( cur != rem.length - 1))
                cur++;
        } while ((rem.length - cur) >= divisor.length);
        return rem;
    }
}