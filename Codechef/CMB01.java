import java.util.Scanner;

class Test {
	public static void main(String [] args) {
		Scanner s = new Scanner(System.in);
		
		int testCases = s.nextInt();
		int a;
		int b;
		
		
		for(int i = 0; i < testCases; i++) {
			a = Integer.parseInt(new StringBuffer(s.next()).reverse().toString());
			b = Integer.parseInt(new StringBuffer(s.next()).reverse().toString());
			
			
			
			
			System.out.println(Integer.parseInt(new StringBuffer(new Integer(a+b).toString()).reverse().toString()));
		}
		
		
		
	}
}