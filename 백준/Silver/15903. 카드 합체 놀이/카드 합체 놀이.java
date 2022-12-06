import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		long card[] = new long[n];
		for(int i = 0; i < n; i++)
			card[i] = Long.parseLong(st.nextToken());
		
		for(int i = 0; i < m; i++) {
			Arrays.sort(card);
			long temp = card[0] + card[1];
			card[0] = temp;
			card[1] = temp;
		}
		
		long sum = 0;
		for(int i = 0; i < n; i++) {
			sum += card[i];
		}
		
		bw.write(sum+"");
		bw.flush();
		bw.close();
	}
}