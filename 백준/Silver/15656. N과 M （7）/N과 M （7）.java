import java.io.*;
import java.util.*;

public class Main {
	
	static int N, M;
	static int[] arr, result;
	static BufferedWriter bw;
	
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];
		result = new int[M];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
		
		Arrays.sort(arr);
		
		backtracking(0);
		
		bw.flush();
		bw.close();
	}
	
	public static void backtracking(int level) throws IOException{
		if(level == M) {
			for(int i = 0; i < M; i ++) bw.write(result[i] + " ");
			bw.write("\n");
			return;
		}
		
		for(int i = 1; i < N + 1; i++) {
			result[level] = arr[i - 1];
			backtracking(level + 1);
		}
	}
} 