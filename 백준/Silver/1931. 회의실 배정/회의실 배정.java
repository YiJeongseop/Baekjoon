import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
	public static void main (String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = Integer.parseInt(br.readLine());
		int[][] arr = new int[N][2];
		
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if(o1[1] == o2[1]) // 끝나는 시간이 같으면
					return o1[0] - o2[0]; // 시작 시간 기준 오름차순 정렬
				return o1[1] - o2[1]; // 끝나는 시간 기준 오름차순 정렬
			}
		});
		
		int result = 0;
		int endtime = 0;
		for(int i = 0; i < N; i++) {
			if(arr[i][0] >= endtime) {
				endtime = arr[i][1];
				result++;
			}
		}
		
		bw.write(result+"");
		bw.flush();
		bw.close();
	}
}