import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Pos implements Comparable<Pos>{
	int v1, v2, value;
	public Pos(int v1, int v2, int value) {
		super();
		this.v1 = v1;
		this.v2 = v2;
		this.value = value;
	}
	@Override
	public int compareTo(Pos o) {
		return value - o.value;
	}
}

public class Main {
	
	static int[] parents;
	
	public static void main (String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		PriorityQueue<Pos> que = new PriorityQueue<>();
		parents = new int[V + 1];
		
		for(int i = 1; i <= V; i++) {
			parents[i] = i;
		}
		
		for(int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine()); 
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			int value = Integer.parseInt(st.nextToken());
			que.add(new Pos(v1, v2, value));
		}
		
		int total = 0;
		while(!que.isEmpty()) {
			Pos temp = que.poll();
			if(find(temp.v1) != find(temp.v2)) {
				total += temp.value;
				union(temp.v1, temp.v2);
			}
		}
		
		bw.write(total+"");
		bw.flush();
		bw.close();
	}
	
	public static int find(int i) {
		if(parents[i] == i) return i;
		else return find(parents[i]);
	}
	
	public static void union(int a, int b) {
		int a_parents = find(a);
		int b_parents = find(b);
		
		if(a_parents > b_parents) 
			parents[a_parents] = b_parents;
		else
			parents[b_parents] = a_parents;
	}
}