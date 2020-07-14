import java.util.*;

public class Main {

    public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		
		int n=sc.nextInt();
		int[][] space=new int[n][n];
		int sk_x=-1,sk_y=-1,pro_x=-1,pro_y=-1, cnt=0;
		boolean exit=false;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				space[i][j]=sc.nextInt();
				if(space[i][j]==2)
				{
					sk_x=i;
					sk_y=j;
				}
				else if(space[i][j]==5) {
					pro_x=i;
					pro_y=j;
				}
			}
		}

        for (int i = Math.min(sk_x, pro_x); i <= Math.max(pro_x, sk_x) && !exit; i++) {
            for (int j = Math.min(pro_y, sk_y); j <= Math.max(pro_y, sk_y); j++) {
                if (space[i][j] == 1)
                    cnt++;
                if (cnt >= 3) {
                    if ((pro_x - sk_x) * (pro_x - sk_x) + (pro_y - sk_y) * (pro_y - sk_y) >= 25)
                        exit = true;
                    break;
                }
            }
        }
        if(exit)
        	System.out.println(1);
        else
        	System.out.println(0);
       System.out.println(exit ? 1 : 0);
    }
}