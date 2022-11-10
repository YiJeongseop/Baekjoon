import java.io.*;
import java.util.*;

public class Main {
	
	static ArrayList<Node>[] graph;
	static int[] dist;
	static int[] dist2;
	static boolean[] visit;
	
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		PriorityQueue<Node> que;
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int X = Integer.parseInt(st.nextToken());
		graph = new ArrayList[N];
		
		for (int i = 0; i < N; i++) {
			graph[i] = new ArrayList<Node>();
		}
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			graph[start - 1].add(new Node(end, cost));
		}
		
		int max = Integer.MIN_VALUE;

		que = new PriorityQueue<>();
		dist = new int[N];
		visit = new boolean[N];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[X - 1] = 0;
		que.add(new Node(X, 0));
		while(!que.isEmpty()) {
			Node now = que.poll();
			if(visit[now.to - 1] == true) continue;
			visit[now.to - 1] = true;

			for(Node next : graph[now.to - 1]) {
				if(dist[next.to - 1] > now.cost + next.cost){
					dist[next.to - 1] = now.cost + next.cost;
					que.add(new Node(next.to, dist[next.to - 1]));
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			que = new PriorityQueue<>();
			dist2 = new int[N];
			visit = new boolean[N];
			Arrays.fill(dist2, Integer.MAX_VALUE);
			dist2[i] = 0;
			que.add(new Node(i + 1, 0));
			while(!que.isEmpty()) {
				Node now = que.poll();
				if(visit[now.to - 1] == true) continue;
				visit[now.to - 1] = true;
				
				for(Node next : graph[now.to - 1]) {
					if(dist2[next.to - 1] > now.cost + next.cost){
						dist2[next.to - 1] = now.cost + next.cost;
						que.add(new Node(next.to, dist2[next.to - 1]));
					}
				}
			}
			if(max < dist2[X - 1] + dist[i])
				max = dist2[X - 1] + dist[i];
		}
		
		bw.write(max+"");
		bw.flush();
		bw.close();
	}
}

class Node implements Comparable<Node>{
	int to;
	int cost;
	
	public Node(int to, int cost) {
		this.to = to;
		this.cost = cost;
	}

	@Override
	public int compareTo(Node o) {
		return this.cost - o.cost;
	}
}
