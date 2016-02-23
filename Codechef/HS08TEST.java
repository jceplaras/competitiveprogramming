import java.util.Scanner;

class Test {
	public static void main(String [] args) {
		
		Scanner s = new Scanner(System.in);

		int a = s.nextInt();
		float b = s.nextFloat();
		
		System.out.println((a%5 == 0 && a <= (b-.5))?b-.5-a:b);
		
	}
}