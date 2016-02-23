import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

class Lucky1 {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	int MAX = 100001;
	public static void main(String[] args) {
		Lucky1 program = new Lucky1();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		int [] four = new int[MAX];
		int [] seven = new int[MAX];
		int [] ans = new int[MAX];
		HashMap<Integer,Integer> C = new HashMap<Integer, Integer>();
		
		for(int i = 0;i<MAX;i++) {
			four[i] = (i>0)?four[i-1]:0;
			seven[i] = (i>0)?seven[i-1]:0;
			int x = 0;
			for(char c: (i+"").toCharArray()) {
				if(c=='4')  ++four[i];
				else if(c=='7')  ++seven[i];
			}
			x = seven[i]-four[i];
			//System.out.println(C);
			if(!C.containsKey(x)) {
				C.put(x, 0);
			}
			ans[i] += ((i>0)?ans[i-1]:0)+C.get(x);
			C.put(x, C.get(x)+1);
		}
		
		//System.out.println(Arrays.toString(ans));
		for(int i=0;i<T;i++) {
			out.println(ans[s.nextInt()]);
		}
		//System.out.println(Arrays.toString(answer));
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