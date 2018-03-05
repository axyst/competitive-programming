import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sca=new Scanner(System.in);
        BigInteger a[]=new BigInteger[10005];
        a[0]=BigInteger.ONE;
        for(int i=1;i<=10000;i++)
            a[i]=a[i-1].multiply(BigInteger.valueOf(i));
        int n;
        while(sca.hasNextInt()){
            n=sca.nextInt();
            System.out.println(a[n]);
        }
    }
}