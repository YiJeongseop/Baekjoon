import java.io.*;
import java.util.*;

public class Main {
	static boolean[] visit;
	static int[] dist;
	static ArrayList<Node>[] graph;
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(br.readLine());
		
		visit = new boolean[V];
		dist = new int[V];
		graph = new ArrayList[V];
		
		for (int i = 0; i < V; i++) {
			graph[i] = new ArrayList<>();
			dist[i] = Integer.MAX_VALUE;
		}
		
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			graph[v1 - 1].add(new Node(v2, cost));
		}
		
		dijkstra(K);
			
		for (int i = 0; i < V; i++) {
			if(dist[i] == Integer.MAX_VALUE)
				bw.write("INF\n");
			else
				bw.write(dist[i]+"\n");
		}
		bw.flush();
		bw.close();
	}
	
	static public void dijkstra(int K) {
		PriorityQueue<Node> que = new PriorityQueue<>();
		dist[K - 1] = 0;
		que.add(new Node(K, 0));
		
		while(!que.isEmpty()) {
			Node now = que.poll();
			
			if(visit[now.v2 - 1]) continue;
			visit[now.v2 - 1] = true;
			
			for(Node next : graph[now.v2 - 1]) {
				if(dist[next.v2 - 1] > now.cost + next.cost) {
					dist[next.v2 - 1] = now.cost + next.cost;
					que.add(new Node(next.v2, dist[next.v2 - 1]));
				}
			}
		}
	}
}

class Node implements Comparable<Node>{
	int v2, cost;
	
	public Node(int v2, int cost) {
		this.v2 = v2;
		this.cost = cost;
	}

	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.cost, o.cost);
	}
}