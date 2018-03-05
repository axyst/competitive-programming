import java.util.*;
import java.math.*;
public class Main{
    public static void main(String[] args){
        int a[]=new int[30];
        Scanner sca=new Scanner(System.in);
        int n;
        while(sca.hasNext()){
            n=sca.nextInt();
            if(n==0) break;
            int sum=0;
            for(int i=0;i<n;i++){
                a[i]=sca.nextInt();
                sum+=a[i];
            }
            BigInteger up=new BigInteger("1");
            for(int i=1;i<=sum;i++){
                up=up.multiply(BigInteger.valueOf(i));
            }
            BigInteger down=new BigInteger("1");
            for(int i=0;i<n;i++){
                for(int j=1;j<=a[i];j++){
                    down=down.multiply(BigInteger.valueOf(j));
                }
            }
            System.out.println(up.divide(down));
        }
    }
}