import java.util.*;
public class Main {

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String[][] board;
		Scanner sc=new Scanner(System.in);
		int c=sc.nextInt();
		
		for(int i=0;i<c;i++) {
			int h=sc.nextInt();
			int w=sc.nextInt();
			board=new String[h][w];
			
			for(int j=0;j<h;j++) {
				for(int k=0;k<w;k++) {
					board[j][k]=sc.next();
				}
			}
		}
	}

}
