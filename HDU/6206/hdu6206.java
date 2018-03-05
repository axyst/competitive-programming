import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        int t=cin.nextInt();
        BigDecimal x1,y1,x2,y2,x3,y3,x,y;
        for(int ks=1;ks<=t;ks++){
            x1=cin.nextBigDecimal();
            y1=cin.nextBigDecimal();
            x2=cin.nextBigDecimal();
            y2=cin.nextBigDecimal();
            x3=cin.nextBigDecimal();
            y3=cin.nextBigDecimal();
            x=cin.nextBigDecimal();
            y=cin.nextBigDecimal();
            BigDecimal two=new BigDecimal(2.0);
            BigDecimal a1=(x2.subtract(x1)).multiply(two);
            BigDecimal b1=(y2.subtract(y1)).multiply(two);
            BigDecimal c1=(((x2.multiply(x2)).add(y2.multiply(y2))).subtract(x1.multiply(x1))).subtract(y1.multiply(y1));
            BigDecimal a2=(x3.subtract(x2)).multiply(two);
            BigDecimal b2=(y3.subtract(y2)).multiply(two);
            BigDecimal c2=(((x3.multiply(x3)).add(y3.multiply(y3))).subtract(x2.multiply(x2))).subtract(y2.multiply(y2));
            BigDecimal px=((c1.multiply(b2)).subtract(c2.multiply(b1))).divide((a1.multiply(b2)).subtract(a2.multiply(b1)));
            BigDecimal py=((a1.multiply(c2)).subtract(a2.multiply(c1))).divide((a1.multiply(b2)).subtract(a2.multiply(b1)));
            BigDecimal r=((x1.subtract(px)).multiply(x1.subtract(px))).add((y1.subtract(py)).multiply(y1.subtract(py)));
            BigDecimal r2=((x.subtract(px)).multiply(x.subtract(px))).add((y.subtract(py)).multiply(y.subtract(py)));
            //System.out.println(px+" "+py);
            
            if(r2.compareTo(r) == 1) System.out.println("Accepted");
            else System.out.println("Rejected");
        }
    }
}