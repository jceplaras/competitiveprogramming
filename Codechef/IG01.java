import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.PrintWriter;

class IG01 {
	InputScanner s = new InputScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	String [] FLAMES = {
			"FRIENDS",
			"LOVE",
			"ADORE",
			"MARRIAGE",
			"ENEMIES",
			"SISTER"
	};
	public static void main(String[] args) {
		IG01 program = new IG01();
		program.begin();
	}

	public void begin() {
		int T = s.nextInt();
		for(int i=0;i<T;i++) {
			ArrayList<String> t = new ArrayList<String>();
			for(String x: FLAMES)
		t.add(x);
		int [] one = new int['Z'-'A'+1];
		int [] two = new int['Z'-'A'+1];
		for(char c: s.nextLine().toUpperCase().toCharArray())
			if(c!=' ')
			one[c-'A']++;
		for(char c: s.nextLine().toUpperCase().toCharArray())
			if(c!=' ')
			two[c-'A']++;
		int temp = 0;
		for(int k=0;k<one.length;k++)
			temp += Math.abs(one[k] - two[k]);
		temp--;
		if(temp==-1)
			out.println("SISTER");
		else {
		int x=temp;
		while(t.size() > 1) {
			x%=t.size();
			t.remove(x);
			x+=temp;
		}
		out.println(t.get(0));
		}
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
