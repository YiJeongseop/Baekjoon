import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		int[] score = new int[N];
		
		for(int i = 0; i < N; i++) {
			score[i] = Integer.parseInt(br.readLine());
		}
		
		int result = 0;
		for(int i = N - 2; i >= 0; i--) {
			if(score[i] >= score[i + 1]) {
				int temp = score[i] - score[i + 1] + 1;
				score[i] -= temp;
				result += temp;
			}
		}
		
		bw.write(result+"");
		bw.flush();
		bw.close();
	}
}