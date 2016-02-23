import java.util.Scanner;

class Test {
	public static void main(String [] args) {
		Scanner s = new Scanner(System.in);
		
		int testCases = s.nextInt();
		
		
		
		for(int i = 0; i < testCases; i++) {
			Integer j;
			for( j = s.nextInt()+1;!new StringBuffer(j.toString()).reverse().toString().contentEquals(j.toString());j++);
			
			System.out.println(j);
		}
		
		
		
	}
}