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
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeSet;

class RRATING {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		RRATING program = new RRATING();
		program.begin();
	}

	public void begin() {
		
		int T = s.nextInt();
		PriorityQueue<Integer> pqTop = new PriorityQueue<Integer>();
		PriorityQueue<Integer> pqBot = new PriorityQueue<Integer>();
		
		int count = 0;
		for(int i=0;i<T;i++) {
			int c = s.nextInt();
			
			if(c == 1) {
				c = s.nextInt();
				
				if(pqTop.size() == 0 || c > pqTop.peek()) pqTop.add(c);
				else pqBot.add(-c);
				count++;
				if(count >= 3) {
				while(pqTop.size() < count/3)
					pqTop.add(-pqBot.remove());
				while(pqTop.size() > count/3)
					pqBot.add(-pqTop.remove());
				}
			}
			else {
				if(count < 3) out.println("No reviews yet");
				else out.println(pqTop.peek());
			}
			//System.out.println(pqTop+" "+pqBot);
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