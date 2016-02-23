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

class IG04 {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		IG04 program = new IG04();
		program.begin();
	}

	public void begin() {
		
		int T = s.nextInt();
		long [] a = new long[T+2];
		long [] current = new long[T+2];
		for(int t = 1; t<=T; t++) {
			current[t] = a[t] = s.nextInt();
					//(int) (Math.random()*T + 1);
		}
		long cost = 0;
		//System.out.println(Arrays.toString(a));
		for(int i=T-1;i>0;i--) {
			long max = a[i];
			long add = 0;
			
			for(int j=i+1;j<T+1;j++) {
				//System.out.println(i+" "+j+" "+max+" "+a[j]);
				if(a[j] == 0) continue;
				if(a[j] >= max) {
					long cut = (a[j]-max)+1;
					add+=cut;
					a[j]-=cut;
				}
				max=a[j];
			}
			if(add < a[i]) {
				cost+=add;
				current = Arrays.copyOf(a, a.length);
			}
			else {
				cost+=a[i];
				current[i] = 0;
				a = Arrays.copyOf(current, a.length);
				
			}
			
		}
		//System.out.println(Arrays.toString(a));
		out.println(cost);
		
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