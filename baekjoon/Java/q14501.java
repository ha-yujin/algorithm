import java.util.*;
public class Main {

	static int n;
	static int[] time;
	static int[] profit;
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		n=sc.nextInt();
		time=new int[n+1];
		profit=new int[n+1];
		
		for(int i=1;i<=n;i++) {
			time[i]=sc.nextInt();
			profit[i]=sc.nextInt();
		}
		System.out.println(calculate(1,0));
	}

	private static int calculate(int t, int max) {
		// TODO Auto-generated method stub
		int sum=0;
		if(t>n) // ��� ���Ŀ��� ����
			return max;
		if(t+time[t]<=n+1)
			sum=Math.max(sum, calculate(t+time[t],max+profit[t])); // t�� ��� ���Ҷ� max�� ã�� ��
		sum=Math.max(sum, calculate(t+1,max)); // t�� ����� ���� �ٽ� ���ؼ� max�� �ֱ�
		return sum;
	}
}