import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static int dp[];
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		dp = new int[N + 1];
		dp[1] = 0;
		
		for(int i = 2; i <= N; i++) {
			if(i % 6 == 0) dp[i] = Math.min(dp[i - 1], Math.min(dp[i / 2], dp[i / 3])) + 1;
			else if(i % 3 == 0) dp[i] = Math.min(dp[i - 1], dp[i / 3]) + 1;
			else if(i % 2 == 0) dp[i] = Math.min(dp[i - 1], dp[i / 2]) + 1;
			else dp[i] = dp[i - 1] + 1;
		}
		
		bw.write(dp[N] + "\n");
		
		bw.write(N + " ");
		while(N != 1) {
			if(N % 6 == 0) {
				if(Math.min(dp[N - 1], Math.min(dp[N / 3], dp[N / 2])) == dp[N - 1])
						N = N - 1;
				else if(Math.min(dp[N - 1], Math.min(dp[N / 3], dp[N / 2])) == dp[N / 2])
						N = N / 2;
				else N = N / 3;
			}
			else if(N % 3 == 0) {
				if(dp[N - 1] > dp[N / 3]) N = N / 3;
				else N = N - 1;
			}
			else if(N % 2 == 0) {
				if(dp[N - 1] > dp[N / 2]) N = N / 2;
				else N = N - 1;
			}
			else N = N - 1;
			bw.write(N + " ");
		}
		
		bw.flush();
		bw.close();
	}
}