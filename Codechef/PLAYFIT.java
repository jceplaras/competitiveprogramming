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


class Playfit {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		Playfit program = new Playfit();
		program.begin();
	}

	public void begin() {
		int [] store = new int[100001];
		
		
		int T = s.nextInt();
		for(int i=0;i<T;i++) {
			int N = s.nextInt();
			int start = 0;
			int end = 0;
			
			int minIndex = 0;
			int maxDifference = 0;
			int tempDiff;
			
			for(int j=0;j<N;j++) {
				store[j] = s.nextInt();
				if(store[j] < store[minIndex])
					minIndex = j;
				tempDiff = store[j] - store[minIndex];
				if(tempDiff > maxDifference) {
					start = minIndex;
					end = j;
					maxDifference = tempDiff;
				}
			}
			if(maxDifference >0 )
			out.println(maxDifference);
			else
				out.println("UNFIT");
			//System.out.println(Arrays.toString(store));
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