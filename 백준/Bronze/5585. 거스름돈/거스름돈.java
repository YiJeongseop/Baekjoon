import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main (String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = 1000 - Integer.parseInt(br.readLine());
		int[] coin = {500, 100, 50, 10, 5, 1};
		
		int result = 0;
		for(int i = 0; i < coin.length; i++) {
			result = result + (N/coin[i]);
			N = N - (coin[i] * (N/coin[i]));
		}
		
		bw.write(result+"");
		bw.flush();
		bw.close();
	}
}