import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

class LUCKYSTR {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		LUCKYSTR program = new LUCKYSTR();
		program.begin();
	}

	public void begin() {
		int K = s.nextInt();
		int T = s.nextInt();
		
		String [] lucky = new String[K];
		
		for (int i = 0; i < K; i++) {
			lucky[i] = s.next();
		}
		for (int i = 0; i < T; i++) {
			String in = s.next();
			boolean hasMatch = false;
			if(in.length() >= 47) {
				out.println("Good");
				continue;
			}
			for(String l: lucky) {
				if(in.contains(l)) {
					hasMatch = true;
					break;
				}
			}
			
			if(hasMatch) out.println("Good");
			else out.println("Bad");
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