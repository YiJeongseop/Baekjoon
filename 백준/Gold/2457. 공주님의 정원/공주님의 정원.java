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
		int[][] time = new int[N][2];

		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int startMonth = Integer.parseInt(st.nextToken()) * 100;
			int startDate = Integer.parseInt(st.nextToken());
			time[i][0] = startMonth + startDate;
			int endMonth = Integer.parseInt(st.nextToken()) * 100;
			int endDate = Integer.parseInt(st.nextToken());
			time[i][1] = endMonth + endDate;
		}
		
		Arrays.sort(time, new Comparator<int[]>() {
		    @Override
			public int compare(int[] o1, int[] o2) {
		    	 if(o1[1] == o2[1]) {
	                	 return o1[0] - o2[0];
		    	 }else {
		    		 return o1[1] - o2[1]; 
		    	 }
	           }
	        });
		
		int result = 0;
		int start = 301;
		int index = -1;
		int temp = -1;
		while(start < 1201) {
			temp = -1;
			for(int i = index + 1; i < N; i++) {
				if(time[i][0] <= start) temp = i;
			}
			if(temp == -1) break;
			index = temp;
			start = time[index][1];
			result++;
		}
		
		if(temp != -1) bw.write(result+"");
		else bw.write(0+"");
		bw.flush();
		bw.close();
	}
}