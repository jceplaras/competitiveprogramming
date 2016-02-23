import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.BitSet;
import java.util.StringTokenizer;
import java.io.PrintWriter;

class Shuttle {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	BitSet b = new BitSet(10000);
	public static void main(String[] args) {
		Shuttle program = new Shuttle();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		for(int c =0;c<T;c++) {
			int N = s.nextInt();
			
			int count = 0;
			for(int i=1;i<N;i++) {
				if(gcd(i,N)!=1) count++;
			}
			
			out.println(N-1-count);
		}
		out.close();
	}

	int gcd(int a,int b) {
		int oldB;
		while(b!=0) {
			oldB = b;
			b = a%b;
			a = oldB;
		}
		return a;
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