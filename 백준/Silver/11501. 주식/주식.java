import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		long[][] arr = new long[T][];
		
		for(int i = 0; i < T; i++) {
			int N = Integer.parseInt(br.readLine());
			arr[i] = new long[N];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				arr[i][j] = Long.parseLong(st.nextToken());
			}
		}
		
		for(int i = 0; i < T; i++) {
			long max = 0;
			long result = 0;
			for(int j = arr[i].length - 1; j >= 0; j--) {
				if(arr[i][j] > max) max = arr[i][j];
				else{
					result += max - arr[i][j];
				}
			}
			bw.write(result + "\n");
		}
		
		bw.flush();
		bw.close();
	}
}