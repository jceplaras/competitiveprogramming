import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.io.PrintWriter;

 class Hdeliver {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	int [][] distanceMatrix;
	int [] mark;
	public static void main(String[] args) {
		Hdeliver program = new Hdeliver();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		for(int c=1;c<=T;c++) {
			int N = s.nextInt();
			int M = s.nextInt();
			
		distanceMatrix = new int[N][N];
			mark = new int[N];
			for(int i=0;i<M;i++) {
				int a = s.nextInt();
				int b = s.nextInt();
				distanceMatrix[a][b] = distanceMatrix[b][a] = 1;
			}
			
			M = s.nextInt();
			int m = 1;
			for(int i=0;i<N;i++) {
				
				if(mark[i] == 0)
					bfs(i,m,N);
				m++;
			}
			for(int i=0;i<M;i++) {
				int a = s.nextInt();
				int b = s.nextInt();
				
				if(mark[a] == mark[b])
					out.println("YO");
				else
					out.println("NO");
			}
		}
		out.close();
	}

	void bfs(int s, int m, int N) {
		LinkedList<Integer> q = new LinkedList<Integer>();
		boolean[] v = new boolean[N];
		
		q.add(s);
		while(!q.isEmpty()) {
			int x = q.remove();
			mark[x] = m;
			if(!v[x]) {
			v[x] = true;
			for(int i=0;i<N;i++)
				if(distanceMatrix[x][i] == 1) q.add(i);
			}
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