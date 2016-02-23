import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.io.PrintWriter;

class Wcount {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	final int MOD = 1000000007;
	
	int x;
	int y;
	int lx;
	int ly;
	
	public static void main(String[] args) {
		Wcount program = new Wcount();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		long f[] = new long[501];
		int rf[] = new int[501];
			f[0] = rf[0] = 1;
		for(int i=1;i<=500;i++) {
			f[i] = (i*f[i-1])%MOD;
			rf[i] = invMod(f[i]);
		}
		/*System.out.println(Arrays.toString(f));
		System.out.println(Arrays.toString(rf));
		System.out.println(invMod(200));*/
		for(int i=0;i<T;i++) {
			String str = s.next();
			int size = str.length();
			
			//int num = permutation(size);
			
			HashMap<Character,Integer> map = new HashMap<Character, Integer>();
			for(char N: str.toCharArray()) {
				if(map.containsKey(N))
					map.put(N, map.get(N)+1);
				else 
					map.put(N, 1);
			}
			long ans = f[size];
			
			for(int n: map.values())
				ans = ans*rf[n]%MOD;
			
			
			out.println(ans);
		}
		out.close();
	}
	
	public int invMod(long f) {
		exGCD((int)f, MOD);
		return (x%MOD+MOD)%MOD;
	}
	
	public int exGCD(int a,int b) {
		if(b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		int q = a/b;
		int r = a%b;
		int gcd = exGCD(b,r);
		int t = x;
		x=y;
		y=t-q*y;
		return gcd;
		
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