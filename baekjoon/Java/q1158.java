import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int n,k,x=0;
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		k=sc.nextInt();
		ArrayList<Integer> arr=new ArrayList<>();
		for(int i=1;i<=n;i++) {
			arr.add(i);
		}
		System.out.print("<");
		while(!arr.isEmpty()) {
			x=(x+k-1)%arr.size();
			if(arr.size()!=1)
				System.out.print(arr.remove(x)+", ");
			else
				System.out.print(arr.remove(x)+">");
		}
	}
}
