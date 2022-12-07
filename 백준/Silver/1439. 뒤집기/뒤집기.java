import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String S = br.readLine();
		
		int count = 0;
		boolean flag;
		if(S.charAt(0) == '0') flag = true;
		else flag = false;
		
		for(int i = 1; i < S.length(); i++) {
			if(flag == true && S.charAt(i) == '1') {
				flag = false;
				count++;
			}
			else if(flag == false && S.charAt(i) == '0') {
				flag = true;
				count++;
			}
		}
		
		bw.write((count + 1) / 2 + "");
		bw.flush();
		bw.close();
	}
}