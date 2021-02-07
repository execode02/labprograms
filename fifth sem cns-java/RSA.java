import java.util.Scanner;

public class RSA {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int p, q, n, z, i;
        String message;
        int[] plain_text = new int[100];
        int[] cipher_text = new int[100];

        System.out.println("enter the message to be encrypted:");
        message = sc.nextLine();
        System.out.println("Message entered is:\n " + message);
        char[] msg = message.toCharArray();
        for (i = 0; i < msg.length; i++)
            plain_text[i] = msg[i];
        System.out.println("Enter the value of prime numbers p and q:");
        p = sc.nextInt();
        q = sc.nextInt();
        n = p * q;
        z = (p - 1) * (q - 1);

        int e;
        do {
            System.out.println("Enter the value of e (e>2) such that gcd(z,e)=1");
            e = sc.nextInt();
        } while (gcd(z, e) != 1);

        int d = 2;
        while (((d * e) % z) != 1)
            d++;

        System.out.println("Public key pair = {" + e + "," + n + "}");
        System.out.println("Private key pair = {" + d + "," + n + "}");
        System.out.print("Ciphertext = {");
        for (i = 0; i < msg.length; i++) {
            cipher_text[i] = mult(plain_text[i], e, n);
            System.out.print(cipher_text[i] + "\t");
        }
        System.out.println("}");
        System.out.print("Plaintext = ");
        for (i = 0; i < msg.length; i++) {
            plain_text[i] = mult(cipher_text[i], d, n);
            msg[i] = (char) plain_text[i];
            System.out.print(msg[i]);
        }
        System.out.println();
    }

    static int gcd(int m, int n) {
        if (n == 0)
            return m;
        else
            return gcd(n, m % n);
    }

    static int mult(int x, int y, int n) {
        int k = 1, j;
        for (j = 1; j <= y; j++)
            k = (k * x) % n;
        return k;
    }
}