import java.util.*;
public class Robot {

	static int m,n,r,c,d,cnt=0;
	static int[][] space;
	static Boolean[][] cleaned;
	static int[] dx= {0,1,0,-1};
	static int[] dy= {-1,0,1,0};

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		r=sc.nextInt();
		c=sc.nextInt();
		d=sc.nextInt(); // 0:북, 1:동, 2:남, 3:서 --> 왼쪽 방향 회전시 (d+3)%4
		
		space=new int[n][m];
		cleaned=new Boolean[n][m];
		for(int i=0;i<n;i++)
		{	for(int j=0;j<m;j++)
			{
				space[i][j]=sc.nextInt();
				cleaned[i][j]=false;
			}
		}
		// 청소 시작
		do {
			if(cnt==4 && space[r-dy[d]][c-dx[d]]==0) { // 4방향 모두 체크하고, 뒤가 벽이 아닌 경우
				// 후진
				r=r-dy[d];
				c=c-dx[d];
				cnt=0;
			}
			else if(cnt==4) { // 뒤가 벽인 경우
				int cnt=0;
				for(int i=0;i<n;i++)
				{	for(int j=0;j<m;j++)
					{
						if(cleaned[i][j])
							cnt++;
					}
				}
				System.out.println(cnt);
				return;
			}
			
			cleaned[r][c]=true; // 현재 위치 청소
			int tmpD=(d+3)%4;
			if(space[r+dy[tmpD]][c+dx[tmpD]]==0 && !cleaned[r+dy[tmpD]][c+dx[tmpD]]) { // 왼쪽 방향 청소 안한 경우
				d=tmpD;
				r=r+dy[tmpD];
				c=c+dx[tmpD];
				cnt=0;
			}
			else { // 청소 공간이 없는 경우
				d=tmpD;
				cnt++;
			}
		}while(true);
	}
}
