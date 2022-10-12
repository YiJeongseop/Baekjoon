import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static int dp[] = new int[11];
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for(int i = 4; i < 11; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		for(int i = 0; i < T; i++) {
			int N = Integer.parseInt(br.readLine());
			bw.write(dp[N]+"\n");
		}
		bw.flush();
		bw.close();
	}
}