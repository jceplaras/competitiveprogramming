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

class ALGRIV {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	final int MAX = 1000521;
	public static void main(String[] args) {
		ALGRIV program = new ALGRIV();
		program.begin();
	}

	public void begin() {
		int [] one = new int[MAX];
		
		
		for(int i=1;i<1000521;i=i+sumOfDigits(i))
			one[i] = 1;
		for(int i=3;i<1000521;i=i+sumOfDigits(i))
			one[i] = 3;
		for(int i=9;i<1000521;i=i+sumOfDigits(i))
			one[i] = 9;
		/*System.out.println(oneB+" "+threeB+" "+nineB);
		
		System.out.println(one[MAX-1]+" "+three[MAX-1]+" "+nine[MAX-1]);*/
		int T = s.nextInt();
		for(int i=0;i<T;i++) {
			int S = s.nextInt();
			//boolean found = false;
			for(;S<1000521;S=S+sumOfDigits(S)) {
				if(one[S] != 0) {
					out.println(one[S]+" "+S);
					break;
				}
			}
		}
		out.close();
		
		
	}
	
	int sumOfDigits(int n) {
		int x=0;
		for(char c: (n+"").toCharArray()) 
			x+=(c-48);
		return x;
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