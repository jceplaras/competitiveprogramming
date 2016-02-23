import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.PrintWriter;
import java.math.BigInteger;

class ALGINT {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		ALGINT program = new ALGINT();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		for(int i=0;i<T;i++) {
			char[] in = s.next().toCharArray();
			String num1 = "";
			String num2 = "";
			String num3 = "";
			int x;
			for(x=0;x<32;x++)
				num1+=in[x]=='0'?'1':'0';
			
			for(;x<48;x++)
				num2+=in[x]=='0'?'1':'0';
			int n2=Integer.parseInt(num2, 2);
			
			for(;x<48+n2;x++)
				num3+=in[x]=='0'?'1':'0';
			
			long n1=Long.parseLong(num1, 2);
			
			BigInteger n3=new BigInteger(num3, 2);
			
			 long outLong = n3.mod(BigInteger.valueOf(n1)).longValue();
			 
			 String sOut = Long.toBinaryString(outLong);
			 
			 for(char c: sOut.toCharArray())
				 out.print(c=='0'?'1':'0');
			 out.println();
			 
		}
		out.close();
	}

	class InputScanner {
		BufferedReader br;
		StringTokenizer strtok = null;

		public InputScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));

		}

		public InputScanner(File file) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(file));
		}

		public String next() {
			if (strtok == null || !strtok.hasMoreTokens()) {
				try {
					strtok = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return strtok.nextToken();
		}

		public int nextInt() {
			int i;
			try {
				i = Integer.parseInt(next());
			} catch (NumberFormatException e) {
				throw new RuntimeException(e);
			}
			return i;
		}

		public String nextLine() {
			if (strtok == null || !strtok.hasMoreTokens()) {
				try {
					strtok = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return strtok.nextToken("\n").trim();
		}

	}

}