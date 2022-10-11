import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static int count[];
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		count = new int[N + 1];
		
		count[1] = 0;
		
		for(int i = 2; i <= N; i++) {
			if(i % 6 == 0) count[i] = Math.min(count[i - 1], Math.min(count[i / 2], count[i / 3])) + 1;
			else if(i % 3 == 0) count[i] = Math.min(count[i - 1], count[i / 3]) + 1;
			else if(i % 2 == 0) count[i] = Math.min(count[i - 1], count[i / 2]) + 1;
			else count[i] = count[i - 1] + 1;
		}
		
		bw.write(count[N]+"");
		bw.flush();
		bw.close();
	}
}