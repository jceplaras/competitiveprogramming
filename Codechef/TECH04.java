import java.util.Arrays;
import java.util.Scanner;

class Test {
	public static void main(String [] args) {
		Scanner s = new Scanner(System.in);

		int testCases = s.nextInt();

		for(int i = 0; i < testCases; i++) {
			char [] a = s.next().toLowerCase().toCharArray();
			char [] b = s.next().toLowerCase().toCharArray();
						
			Arrays.sort(a);
			Arrays.sort(b);
			
			System.out.println((new String(a).contentEquals(new String(b)))?"YES":"NO");
		}
	}
}