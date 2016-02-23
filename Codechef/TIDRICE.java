import java.util.Scanner;
import java.util.TreeMap;


class Cook {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		
		
		int T = s.nextInt();
		for(int i = 0;i<T;i++) {
			TreeMap<String, Integer> t = new TreeMap<String, Integer>();
			int vote = 0;
			int N = s.nextInt();
			for(int j = 0;j<N;j++) {
				
				
				String str= s.next();
				int v = (s.next().contains("+"))?1:-1;
				vote+=v;
				if(t.containsKey(str)) {
					vote+=t.get(str)*-1;
					t.put(str,v);
				}
				else {
					t.put(str, v);
				
				}
			
			}
			
			System.out.println(vote);
		}
	}

}
