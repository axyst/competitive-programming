import java.util.*;
import java.math.*;
public class Main {
    public static void main(String args[]) {
        int MAXN=5005;
        BigInteger [] dp=new BigInteger[MAXN];
        for(int i=0;i<MAXN;i++) {
            dp[i]=new BigInteger("0"); 
        }
        dp[0]=BigInteger.valueOf(1);
		for(int j=1;j<MAXN;j++){
			for(int i=j;i<MAXN;i++)
				dp[i]=dp[i].add(dp[i-j]);
		}
		Scanner sc=new Scanner(System.in);
		int n;
		while(sc.hasNextInt()){
			n=sc.nextInt();
			System.out.println(dp[n]);
		}
    }  
}  