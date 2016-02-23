import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class ALGPRX {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	boolean[] prime;
	
	public static void main(String[] args) {
		ALGPRX program = new ALGPRX();
		program.begin();
	}

	public void begin() {
		sieve(1000001);
		long c[] = new long[1000001];
		c[0] = 0;
		for(int i=1;i<=1000000;i++)
			c[i] = c[i-1]+((prime[i])?i:0);
		int T = s.nextInt();
		for(int i=0;i<T;i++)
			out.println(c[s.nextInt()-1]);
		out.close();
	}

	public void sieve(int n)
	{
	prime=new boolean[n+1];
	Arrays.fill(prime,true);
	prime[0]=false;
	prime[1]=false;
	int m=(int) Math.sqrt(n);
	for (int i=2; i<=m; i++)
	if (prime[i])
	for (int k=i*i; k<=n; k+=i)
	prime[k]=false;
	
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