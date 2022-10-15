import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
		int N = Integer.parseInt(br.readLine());
		int[][] M = new int[N + 1][N + 1];
		int[][] RC = new int[N + 1][2];
		
		for(int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			RC[i][0] = Integer.parseInt(st.nextToken());
			RC[i][1] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 1; i <= N; i++) {
			M[i][i] = 0;
		}
		
		for(int i = 1; i <= N - 1; i++) {
			for(int j = 1; j <= N - i; j++) {
				M[j][j + i] = Integer.MAX_VALUE;
				for(int k = j; k < j + i; k++) {
					int q = M[j][k] + M[k + 1][j + i] + RC[j][0]*RC[k][1]*RC[j + i][1];
					if (q < M[j][j + i]) M[j][j + i] = q;
				}
			}
		}
		
		bw.write(M[1][N]+"");
		bw.flush();
		bw.close();
	}
}