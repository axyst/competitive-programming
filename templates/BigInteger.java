import java.io.*;

import java.util.*;

import java.math.*;

Scanner cin = Scanner (System.in);

while(cin.hasNext())

n=cin.nextInt();

n=cin.nextBigInteger();

System.out.print(n);

System.out.println();

System.out.printf("%d\n",n);

BigInteger n,m;

BigDecimal n;

String s;

A=BigInteger.ONE;

B=BigInteger.TEN;

C=BigInteger.ZERO;

int k;A=BigInteger.valueOf(k);

valueOf

add:+

subtract:-

multiply:*

divide:/

remainder：this % val

divideAndRemainder：a[0]=this / val; a[1]=this % val

pow：a.pow(b)=a^b

gcd,abs

negate

signum

mod

shiftLeft

shiftRight

and

or

xor

not

BigInteger b = BigInteger.valueOf(0x12345L);
b.toString(2) == 10010001101000101
bitCount(b) == 7
bitLength(b) == 17

isProbablePrime

compareTo: -1,0 or 1

equals

min,max

intValue,longValue,floatValue,doubleValue
