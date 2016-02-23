import java.util.Scanner;


class StaticTest {
	static Scanner s;
	static int num;
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		s = new Scanner(System.in);
		for(num = s.nextInt();num!=42;System.out.println(num),num = s.nextInt());
	}

}
