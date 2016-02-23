import java.util.HashMap;
import java.util.Scanner;

class Main {

	static HashMap<Long,Long> m = new HashMap<Long,Long>();
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Timer t = new Timer();
		
		Scanner s = new Scanner(System.in);
		while(s.hasNext()) {
			//t.start();
			long n = s.nextInt();
			//for(int n=0;n<1000000000;n++)
			//System.out.println((n!=getMaxDollars(n))?n+">"+getMaxDollars(n):n);
			System.out.println(Math.max(n,getMaxDollars(n)));
			//t.stop();
			//System.out.println(t.getTime()/1000+ "s");
		}
		
		
	}

	private static long getMaxDollars(long n) {
		if(n<12) return n;
		else {
			if(m.containsKey(n)) return m.get(n);
			else {
				
				long x = Math.max(n/2, getMaxDollars(n/2))+Math.max(n/3, getMaxDollars(n/3))+Math.max(n/4, getMaxDollars(n/4));
				m.put(n, x);
				return x;
			}
		}
	}
}
