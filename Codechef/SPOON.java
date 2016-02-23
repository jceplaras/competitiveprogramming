import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.PrintWriter;

class Spoon {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		Spoon program = new Spoon();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		for(int c=0;c<T;c++) {
			int N = s.nextInt();
			int M = s.nextInt();
			char [][] t = new char[N][M];
			boolean found = false;
			for(int x=0;x<N;x++) {
				t[x] = s.nextLine().toLowerCase().toCharArray();
			}
			
			
			for(int i=0;i<N&&!found;i++) {
				for(int j=0;j<M&&!found;j++) {
					if(t[i][j] == 's') {
						if(N-i >= 5) 
							if(t[i+1][j] == 'p' && t[i+2][j] == 'o'&& t[i+3][j] == 'o' && t[i+4][j] == 'n') {
								found = true;
								break;
							}
						if(M-j >= 5)
							if(t[i][j+1] == 'p' && t[i][j+2] == 'o'&& t[i][j+3] == 'o' && t[i][j+4] == 'n') {
								found = true;
								break;
							}
					}
				}
			}
			
			
			if(found)
				out.println("There is a spoon!");
			else
				out.println("There is indeed no spoon!");


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