import java.io.*;

public class Main {
	
	static int n;
	static long[] dp0, dp1;
	
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		dp0 = new long[n + 1];
		dp1 = new long[n + 1];
		dp0[1] = 0;
		dp1[1] = 1;
		for(int i = 2; i < n + 1; i++) {
			dp0[i] = dp0[i-1] + dp1[i-1];
			dp1[i] = dp0[i-1];
		}
		
		bw.write(dp0[n] + dp1[n] + "");
		bw.flush();
		bw.close();
	}
}