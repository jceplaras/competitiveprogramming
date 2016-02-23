import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.PrintWriter;

class CIELNUM2 {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		CIELNUM2 program = new CIELNUM2();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		int count = 0;
		for(int i=0;i<T;i++) {
			String current = "";
			String temp[] = s.nextLine().split("\\W");
			current = temp[temp.length-1];
			int eight = 0;
			int five = 0;
			int three = 0;
			boolean cielNumber = true;
			for(char c: current.toCharArray()) {
				if(c == '8') eight++;
				else if(c == '5') five++;
				else if(c == '3') three++;
				else {
					cielNumber = false;
					break;
				}
			}
			
			if(cielNumber && eight >= five && five >= three) count++;
		}
		out.println(count);
		out.close();
	}

	public boolean isNumeric(String c)
	{
	   try
	   {
	      Integer.parseInt( c );
	      return true;
	   }
	   catch( Exception e )
	   {
	      return false;
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