import java.io.*;
import java.util.*;

import javax.management.monitor.MonitorSettingException;

public class Main {
	
	static int N, M;
	static int[] arr, result;
	static BufferedWriter bw;
	static StringBuilder sb = new StringBuilder();
	static HashSet<String> set = new HashSet<String>();
	
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
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
	}
	
	public static void backtracking(int level) throws IOException{
		if(level == M) {
			StringBuilder sb2 = new StringBuilder();
			for(int i = 0; i < M; i ++) sb2.append(result[i] + " ");
			if(!set.contains(sb2.toString())) {
				sb.append(sb2.toString()).append("\n");
				set.add(sb2.toString());
			}
			return;
		}
		
		for(int i = 1; i < N + 1; i++) {
			if(level != 0) 
				if(result[level - 1] > arr[i - 1]) continue;
			result[level] = arr[i - 1];
			backtracking(level + 1);
		}
	}
} 