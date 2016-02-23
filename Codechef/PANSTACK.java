import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.PrintWriter;

class PANSTACK {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	final int MOD = 1000000007;
	public static void main(String[] args) {
		PANSTACK program = new PANSTACK();
		program.begin();
	}

	public void begin() {
		int [][] bell = new int[1001][1001];
		bell[0][0] = 1;
		
		for(int i=1;i<=1000;i++) {
			bell[i][0] = bell[i-1][i-1];
			for(int j=1;j<=i;j++) {
				bell[i][j] = (bell[i][j-1]%MOD + bell[i-1][j-1]%MOD)%MOD;
			}
		}
		
		int T = s.nextInt();
		for(int i=0;i<T;i++) {
			int N = s.nextInt();
			out.println(bell[N-1][N-1]);
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