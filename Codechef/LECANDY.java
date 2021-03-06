import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

class LECANDY {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		LECANDY program = new LECANDY();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();

		for (int i = 0; i < T; i++) {
			int N = s.nextInt();
			int C = s.nextInt();
			int sum = 0;
			
			for(int c=0;c<N;c++)
				sum+=s.nextInt();
			//System.out.println(sum);
			if(sum > C)
				out.println("No");
			else
				out.println("Yes");

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