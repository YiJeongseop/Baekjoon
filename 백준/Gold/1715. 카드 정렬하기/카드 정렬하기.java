import java.io.*;
import java.util.*;

public class Main {
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		PriorityQueue<Integer> que = new PriorityQueue<>();
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			que.add(Integer.parseInt(br.readLine()));
		}
		int sum = 0;
		while(que.size() > 1) {
			int temp1 = que.poll();
			int temp2 = que.poll();
			
			sum += temp1 + temp2;
			que.add(temp1 + temp2);
		}
		bw.write(sum+"");
		bw.flush();
		bw.close();
	}
}