import java.util.*;
import java.math.*;
public class Main{
    public static void main(String[] args){
        BigInteger[][][] dp=new BigInteger[63][63][63];
        dp[0][0][0]=BigInteger.valueOf(1);
        for(int i=1;i<=60;i++){//A>=B>=C
            for(int j=0;j<=i;j++){
                for(int k=0;k<=j;k++){
                    dp[i][j][k]=BigInteger.valueOf(0);
                    if(i>j) dp[i][j][k]=dp[i][j][k].add(dp[i-1][j][k]);//add A
                    if(j>k) dp[i][j][k]=dp[i][j][k].add(dp[i][j-1][k]);//add B
                    if(k>0) dp[i][j][k]=dp[i][j][k].add(dp[i][j][k-1]);//add C
                }
            }
        }
        Scanner sca=new Scanner(System.in);
        int n;
        while(sca.hasNext()){
            n=sca.nextInt();
            System.out.println(dp[n][n][n]);
            System.out.println();
        }
    }
}