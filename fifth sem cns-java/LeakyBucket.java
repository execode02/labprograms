import java.util.Scanner;

public class LeakyBucket {
    static Scanner sc = new Scanner(System.in);

    static void sendPacket(int packet_size, int bucket_size, int output_rate) {
        if (packet_size > bucket_size)
            System.out.println("Bucket Overflow!!!");
        else {
            while (packet_size > output_rate) {
                System.out.println(output_rate + " bytes of packet outputted");
                packet_size -= output_rate;
            }
            System.out.println(packet_size + " bytes of packet outputted");
        }
    }

    public static void main(String[] args) {
        int no_of_packets, packet_size, bucket_size, output_rate;
        System.out.println("Enter the number of packets, bucket size, output rate:");
        no_of_packets = sc.nextInt();
        bucket_size = sc.nextInt();
        output_rate = sc.nextInt();

        if (no_of_packets > 0) {
            for (int i = 1; i <= no_of_packets; i++) {
                System.out.println("Enter the packet " + i + " size:");
                packet_size = sc.nextInt();
                sendPacket(packet_size, bucket_size, output_rate);
            }
        }
        else {
            System.out.println("no packets to send");
        }
    }
}