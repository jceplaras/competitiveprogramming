import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

class LUCKYBAL {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		LUCKYBAL program = new LUCKYBAL();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();

		for (int i = 0; i < T; i++) {
			char[] in = s.next().toCharArray();
			long len = in.length;
			long pos = 0;
			long answer = (len*(len+1))/2;
			
			for(char c: in) {
				if(c == '7') pos++;
				else {
					answer-=(pos*(pos+1))/2;
					pos=0;
				}
			}
			answer-=(pos*(pos+1))/2;
			out.println(answer);
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