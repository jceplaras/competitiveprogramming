import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.PrintWriter;

class DUMPLING {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		DUMPLING program = new DUMPLING();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		for(int i=0;i<T;i++) {
			long A = Long.parseLong(s.next());
			long B = Long.parseLong(s.next());
			long C = Long.parseLong(s.next());
			long D = Long.parseLong(s.next());
			long K = Long.parseLong(s.next());
			
			long X = GCD(A,B);
			long Y = GCD(C,D);
			
			long S = X/GCD(X,Y);
			long R = K/S;
			long count = 2*(R/Y)+1;
			
			out.println(count);
		}
		out.close();
	}

	public long GCD(long a,long b){
		if (b==0) return a;
		return GCD(b,a%b);
		}
	public long LCM(long a, long b)
	{
		return b*a/GCD(a,b);
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