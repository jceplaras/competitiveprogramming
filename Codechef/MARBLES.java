import java.util.Scanner;

class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		for(int i=s.nextInt();i > 0; i--) {
			long n = s.nextLong();
			long k = s.nextLong();
			System.out.println(combination(n-1,Math.min(n-k,k-1)));
		}
		
	}
	static long combination(long n, long k) {
		long num = 1;
		
		for(long i = 1;i<=k;i++,n--) {
			num = num*n/i;
			
		}
		return num;
	}
}
