

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		
		int N = Integer.parseInt(s.readLine());
		
		char [] temp; 
		int [][] count = new int[2]['z'-'a'+1];
		Arrays.fill(count[0], 100);
		
		
		for(int i=0;i<N;i++) {
			temp = s.readLine().toCharArray();
			for(int j=0;j<temp.length;j++)
				count[1][temp[j]-'a']++;
			
			for(int j=0;j<count[0].length;j++)
				count[0][j] = Math.min(count[0][j], count[1][j]);
			
			Arrays.fill(count[1], 0);
			
		}
		boolean hasPrinted = false;
		for(int i=0;i<count[0].length;i++)
			for(int j=0;j<count[0][i];j++) {
				hasPrinted = true;
				out.print((char)(i+'a'));
			}
		
		if(!hasPrinted) out.print("no such string");
		
		out.println();
		out.close();
		
	}
}
