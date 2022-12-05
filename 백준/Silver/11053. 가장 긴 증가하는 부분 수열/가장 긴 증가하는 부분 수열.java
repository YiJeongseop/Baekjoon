import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		int[] dp = new int[n];
		
		for(int i = 0; i < n; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		
		Arrays.fill(dp, 1);
		
		for(int i = 1; i < n; i++) 
			for(int j = 0; j < i; j++)
				if(arr[j] < arr[i])
					dp[i] = Math.max(dp[j] + 1, dp[i]);
		
		Arrays.sort(dp);
		
		bw.write(dp[n - 1] + "");
		bw.flush();
		bw.close();
	}
}