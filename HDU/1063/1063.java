import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sca=new Scanner(System.in);
        int t=sca.nextInt(),ca=1;
        BigInteger sum,tmp,zero;
        while(ca<=t){
            sum=zero=BigInteger.ZERO;
            while(sca.hasNextBigInteger()){
                tmp=sca.nextBigInteger();
                if(tmp.equals(zero)) break;
                else sum=sum.add(tmp);
            }
            System.out.println(sum);
            if(ca++!=t) System.out.println();
        }
    }
}