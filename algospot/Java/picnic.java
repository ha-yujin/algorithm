import java.util.*;
public class Main {

	public static int n;
	public static boolean[][] areFriends;
	private static int findFriends(boolean[] matched) {
		int first=-1;
		
		for(int i=0;i<n;++i) {
			if(!matched[i]) {
				first=i;
				break;
			}
		}
		
		if(first==-1)
			return 1;
		
		int result=0;
		for(int i=first+1;i<n;++i) {
			if(!matched[i] && areFriends[first][i]) {
				matched[i]=matched[first]=true;
				result+=findFriends(matched);
				matched[i]=matched[first]=false;
			}
		}
		return result;
	}

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int c=sc.nextInt();
		int[] result=new int[c];
		for(int i=0;i<c;i++) {
			n=sc.nextInt();
			int m=sc.nextInt();
			areFriends=new boolean[10][10];
			boolean[] matched=new boolean[10];
			for(int k=0;k<10;k++)
				matched[k]=false;
			for(int j=0;j<m;j++) {
				int a=sc.nextInt();
				int b=sc.nextInt();
				areFriends[a][b]=areFriends[b][a]=true;
			}
			
			result[i]=findFriends(matched);
		}
		for(int i=0;i<c;i++)
			System.out.println(result[i]);
	}
}
