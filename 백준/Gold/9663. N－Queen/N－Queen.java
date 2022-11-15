import java.io.*;

public class Main {
	static int[] arr;
	static int N, result;
	
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		N = Integer.parseInt(br.readLine());
	
		arr = new int[N];
		
		backtracking(1);
		
		bw.write(result+"");
		bw.flush();
		bw.close();
	}
	
	public static void backtracking(int level) {
		if(level == N + 1) {
			result++;
			return;
		}
		
		for(int i = 1; i < N + 1; i++) {
			if(level == 1) {
				arr[level - 1] = i;
				backtracking(level + 1);
				arr[level - 1] = 0;
			}
			else {
				if(check(i, level)) {
					arr[level - 1] = i;
					backtracking(level + 1);
					arr[level - 1] = 0;
				}
			}
		}
	}
	
	public static boolean check(int num, int level) {
		for(int i = 1; i < level; i++) {
			if(arr[i - 1] == num) return false;
			if(Math.abs(level - i) == Math.abs(num - arr[i - 1])) return false;
		}
		return true;
	}
} 