import java.io.*;
import java.util.*;

public class Main {
	static boolean[] visit;
	static int[] result;
	static int N, M;
	static BufferedWriter bw;
	
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		visit = new boolean[N];
		result = new int[M];
		
		backtracking(0);
		
		bw.flush();
		bw.close();
	}
	
	public static void backtracking(int depth) throws IOException {
		if(depth == M) {
			for(int i = 0; i < M; i++) bw.write(result[i]+" ");
			bw.write("\n");
			return;
		}
		
		for(int i = 1; i < N + 1; i++) {
			if(visit[i - 1] == false) {
				result[depth] = i;
				visit[i - 1] = true;
				backtracking(depth + 1);
				visit[i - 1] = false;
			}
		}
	}
} 