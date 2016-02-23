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

class SAD {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		SAD program = new SAD();
		program.begin();
	}

	
	int [][] matrix;
	int R;
	int C;
	public void begin() {
		R = s.nextInt();
		C = s.nextInt();
		
		matrix = new int[R][C];
		int [] maxInCol = new int[C];
		int [] minInRow = new int[R];
		Arrays.fill(minInRow, (int)10e8);
		for (int i = 0; i < R; i++)
			for(int j=0;j<C;j++) {
				
				matrix[i][j] = s.nextInt();
				maxInCol[j] = Math.max(matrix[i][j], maxInCol[j]);
				minInRow[i] = Math.min(matrix[i][j], minInRow[i]);
			}
		
		for (int i = 0; i < R; i++)
			for(int j=0;j<C;j++) {
				if(minInRow[i] == maxInCol[j]) {
					out.println(minInRow[i]);
					out.close();
					System.exit(0);
				}
			}
		
		out.println("GUESS");
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