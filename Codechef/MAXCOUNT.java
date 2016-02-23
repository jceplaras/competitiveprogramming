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

class Maxcount {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		Maxcount program = new Maxcount();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		for(int i=0;i<T;i++) {
			int max = 0;
			int maxNum = -1;
			HashMap<Integer,Integer> map = new HashMap<Integer, Integer>();
			int X = s.nextInt();
			for(int k=0;k<X;k++) {
				int N = s.nextInt();
				if(map.containsKey(N))
					map.put(N, map.get(N)+1);
				else 
					map.put(N, 1);
				
				if(map.get(N) > max || (map.get(N) == max && N < maxNum)) {
					max = map.get(N);
					maxNum = N;
				}
			}
			//System.out.println(map);
			out.print(maxNum+" ");
			out.println(max);
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