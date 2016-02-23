import java.util.Arrays;
import java.util.Scanner;

class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		
		for(int i=s.nextInt();i!=0;i=s.nextInt()) {
			int [] per = new int[i];
			int [] inv = new int[i];
			
			for(int k=0;k<i;k++) {
				per[k] = s.nextInt();
			}
			
			for(int k=0;k<i;k++) {
				int temp = per[k]-1;
				inv[temp]=k+1;
			}
			
			if(Arrays.equals(per, inv)) {
				System.out.println("ambiguous");
						
			}else System.out.println("not ambiguous");
		}
	}

}
