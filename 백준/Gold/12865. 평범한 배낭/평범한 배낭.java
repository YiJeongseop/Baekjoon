import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	final static int INF = 9999;
	
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		int value[] = new int[N];
		int weight[] = new int[N];
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			weight[i] = Integer.parseInt(st.nextToken());
			value[i] = Integer.parseInt(st.nextToken());
		}
		
		int arr[][] = new int[N + 1][K + 1];

		for(int i = 0; i <= N; i++) arr[i][0] = 0;
		
		for(int j = 0; j <= K; j++) arr[0][j] = 0;
		
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= K; j++) {
				if (weight[i - 1] > j) arr[i][j] = arr[i - 1][j];
				else arr[i][j] = Math.max(value[i - 1] + arr[i - 1][j - weight[i - 1]], arr[i - 1][j]);
			}
		}
		
		bw.write(arr[N][K] + "");
		bw.flush();
		bw.close();
	}
}