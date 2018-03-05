import java.math.BigInteger;
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sca=new Scanner(System.in);
        int sum,i;
        BigInteger a,b;BigInteger zero=BigInteger.ZERO;
        BigInteger f[]=new BigInteger[505];
        f[1]=new BigInteger("1");f[2]=new BigInteger("2");
        for(i=3;i<=500;i++) f[i]=f[i-1].add(f[i-2]);
        while(sca.hasNextBigInteger()){
            sum=0;
            a=sca.nextBigInteger();b=sca.nextBigInteger();
            if(a.equals(zero)&&b.equals(zero)) break;
            for(i=1;i<=500;i++){
                if(a.compareTo(f[i])<=0&&b.compareTo(f[i])>=0) sum++;
            if(b.compareTo(f[i])<0) break;
        }
        System.out.println(sum);
    }
}
}