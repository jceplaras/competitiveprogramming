import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class TWSTR {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		TWSTR program = new TWSTR();
		program.begin();
	}

	public void begin() {
		ArrayList<Pair> p = new ArrayList<Pair>();
		
		int T = s.nextInt();
		
		for(int i=0;i<T;i++)
			p.add(new Pair(s.next(), s.nextInt()));
		//System.out.println(p);
		T = s.nextInt();
		Collections.sort(p);
		//System.out.println(p);
		for(int i=0;i<T;i++) {
			String q = s.next();
			boolean found = false;
			for(int c=0;c<p.size();c++) {
				Pair x = p.get(c);
				if(x.key.startsWith(q)) {
					out.println(x.key);
					p.remove(x.key);
					found = true;
					break;
				}
			}
			if(!found) out.println("NO");
		}
		out.close();
	}

	class Pair implements Comparable<Pair>{
		
		public int val;
		public String key;
		public Pair( String key, int val) {
			super();
			this.val = val;
			this.key = key;
		}
		@Override
		public int compareTo(Pair arg0) {
			// TODO Auto-generated method stub
			return arg0.val- this.val; 
		}
		
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return key+"-"+val;
		}
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