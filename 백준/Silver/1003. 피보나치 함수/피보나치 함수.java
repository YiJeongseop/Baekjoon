import java.io.*;

public class Main {
	
	static int N;
	static int[][] dp01 = new int[41][2];
	static int[] fibonacci_dp = new int[41];
	
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		dp01[0][0] = 1;
		dp01[0][1] = 0;
		dp01[1][0] = 0;
		dp01[1][1] = 1;
		
		int T = Integer.parseInt(br.readLine());
		for(int i = 0; i < T; i++) {
			N = Integer.parseInt(br.readLine()); 
			fibonacci(N);
			bw.write(dp01[N][0] + " " + dp01[N][1] + "\n");
		}
		
		bw.flush();
		bw.close();
	}
	
	public static int fibonacci(int n) {
		if(fibonacci_dp[n] != 0) return fibonacci_dp[n];
		if (n == 0) {
			return 0;
		}
		else if (n == 1) {
			return 1;
		}
		else {
			fibonacci_dp[n] = fibonacci(n-1) + fibonacci(n-2);
			dp01[n][0] = dp01[n-1][0] + dp01[n-2][0];
			dp01[n][1] = dp01[n-1][1] + dp01[n-2][1];
			return fibonacci_dp[n];
		}
	}	
}