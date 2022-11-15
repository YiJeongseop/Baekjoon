import java.io.*;
import java.util.*;

public class Main {
	
	static int N, S, result;
	static int[] arr;
	
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		arr = new int[N];
		result = 0;
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
		
		backtracking(0, 0);
		
		if(S == 0) bw.write(result - 1 +"");
		else bw.write(result + "");
		bw.flush();
		bw.close();
	}
	
	public static void backtracking(int level, int sum) {
		if(level == N) {
			if(sum == S) result++;
			return;
		}
		
		backtracking(level + 1, sum);
		backtracking(level + 1, sum + arr[level]);
	}
} 