
import java.util.Scanner;

 class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		
		int ans = a-b;
		char [] ansstring= (""+ans).toCharArray();
		if(ansstring[0] == '9') ansstring[0] = '8';
		else ansstring[0] = '9';
		
		System.out.println(ansstring);
	
		
	}

}
