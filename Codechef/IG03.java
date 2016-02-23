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

class IG03 {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	int [][] d = new int[12][12];
	public static void main(String[] args) {
		IG03 program = new IG03();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		for(int i=0;i<T;i++) {
			int l = s.nextInt();
			int j = s.nextInt();
			int k = s.nextInt();
			
			int x = 1;
			int y = k;
			int c = 1;
			
			
			for(int q = 1; q<=l; q++) { 
				char t[] = s.next().toCharArray(); 
				for(int r=1;r<=j;r++)
					d[q][r] = (t[r-1]=='N')?1:(t[r-1]=='S')?2:(t[r-1]=='W')?3:4;
				}
			/*System.out.println(x+" "+y);
			for(int wq = 0; wq < d.length; wq++)
				System.out.println(Arrays.toString(d[wq]));
			System.out.println();*/
			while(d[x][y] != 0 && d[x][y]>0) {
				int temp = d[x][y];
				d[x][y]=-c;
				switch(temp){
				case 1: x--; break;
				case 2: x++; break;
				case 3: y--; break;
				case 4: y++; break;
				}
				
				c++;
//				System.out.println(x+" "+y);
//				for(int wq = 0; wq < d.length; wq++)
//					System.out.println(Arrays.toString(d[wq]));
//				s.next();
			}
			
			if(d[x][y] == 0)
				out.println((c-1)+"E");
			else
				out.println((c+d[x][y])+"L");
			//out.println(c+""+((d[x][y] == 0)?'E':'L'));
			for(int wq=0;wq<d.length;wq++)
				Arrays.fill(d[wq], 0);
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
