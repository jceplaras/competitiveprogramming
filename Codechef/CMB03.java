import java.util.Scanner;

class Test {
	public static void main(String [] args) {
		Scanner s = new Scanner(System.in);

		int testCases = s.nextInt();

		for(int i = 0; i < testCases; i++) {
			System.out.println((s.next().contains(s.next()))?1:0);
		}
	}
}