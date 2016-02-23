
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		char in[] = s.readLine().toCharArray();
		for(int i=0;i<in.length;i++)
			in[i] = (char) Character.getNumericValue(in[i]);
		
		
		int numOfNonZero = 0;
		
		//System.out.println(Arrays.toString(numOfNonZero));
		long count = 0;
		int val;
		for(int i=0;i<in.length;i++) {
			if(in[i]!=0) numOfNonZero++;
			if(in[i]==8||in[i]==0) count++;
			if(in[i]!=0) {
				if(i<in.length-1) {
					val = in[i]*10+in[i+1];
					if(val%8 == 0) count++;
				}
				
			}
			if(i<in.length-2) {
				
				val = in[i]*100+in[i+1]*10+in[i+2];
				
				if(val%8 == 0) count+=numOfNonZero;
			}
		}
		 
		
		out.println(count);
		out.close();
		
	}

}
