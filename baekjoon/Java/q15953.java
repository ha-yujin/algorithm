import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int x,y;
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();

		int[] reward=new int[n];
		
		for(int i=0;i<n;i++) {
			x=sc.nextInt();
			y=sc.nextInt();	
			
			if(x==0)
				reward[i]=0;
			else if(x==1)
				reward[i]=5000000;
			else if(x<=3 )
				reward[i]=3000000;
			else if(x<=6)
				reward[i]=2000000;
			else if(x<=10)
				reward[i]=500000;
			else if(x<=15)
				reward[i]=300000;
			else if(x<=21)
				reward[i]=100000;
			else
				reward[i]=0;
			
			if(y==0)
				reward[i]+=0;
			else if(y==1)
				reward[i]+=5120000;
			else if(y<=3)
				reward[i]+=2560000;
			else if(y<=7)
				reward[i]+=1280000;
			else if(y<=15)
				reward[i]+=640000;
			else if(y<=31)
				reward[i]+=320000;
			else
				reward[i]+=0;
		}
		for(int i=0;i<n;i++) {
			System.out.println(reward[i]);
		}
	}
}
