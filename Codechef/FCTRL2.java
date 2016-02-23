

import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;

class Factorial {
	static HashMap<Integer,BigInteger> m = new HashMap<Integer,BigInteger>();
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		/*Timer t = new Timer();
		t.start();*/
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		for(int i=0;i<n;i++) {
			System.out.println(factorial(s.nextInt()));
		}
		/*t.stop();
		System.out.println(t.getTime());*/
	}
	
	public static BigInteger factorial(int n) {
		if(n==0) return BigInteger.ONE;
		else {
			if(m.containsKey(n)) return m.get(n);
			else {
				BigInteger temp = new BigInteger(""+n);
				temp=temp.multiply(factorial(n-1));
				
				m.put(n, temp);
				return temp;
			}
		}
	}
	


}
