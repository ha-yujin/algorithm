import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc=new Scanner(System.in);
		int n,k;
		n=sc.nextInt();
		k=sc.nextInt();
		int[] cnt=new int[n];
		double min=Double.MAX_VALUE;

		for(int i=0;i<n;i++) {
			cnt[i]=sc.nextInt();
		}
		
		for(int i=0;i<=(n-k);i++) {
			for(int j=k;j<=(n-i);j++) { // K°³, k+1°³, ....
				min=Math.min(min, calc(cnt,i,j));
			}
		}
		System.out.format("%.11f", min);
	}

	private static double calc(int[] cnt, int start, int num) {
		// TODO Auto-generated method stub
		int sum=0;
		double dev,total=0;
		for(int i=start;i<(start+num);i++)
			sum+=cnt[i];
		double avg=(double)sum/num;
		for(int j=start;j<(start+num);j++)
			total+=Math.pow(cnt[j]-avg, 2);
		return Math.sqrt(total/num);
	}
}