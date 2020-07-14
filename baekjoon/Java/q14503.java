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
		d=sc.nextInt(); // 0:��, 1:��, 2:��, 3:�� --> ���� ���� ȸ���� (d+3)%4
		
		space=new int[n][m];
		cleaned=new Boolean[n][m];
		for(int i=0;i<n;i++)
		{	for(int j=0;j<m;j++)
			{
				space[i][j]=sc.nextInt();
				cleaned[i][j]=false;
			}
		}
		// û�� ����
		do {
			if(cnt==4 && space[r-dy[d]][c-dx[d]]==0) { // 4���� ��� üũ�ϰ�, �ڰ� ���� �ƴ� ���
				// ����
				r=r-dy[d];
				c=c-dx[d];
				cnt=0;
			}
			else if(cnt==4) { // �ڰ� ���� ���
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
			
			cleaned[r][c]=true; // ���� ��ġ û��
			int tmpD=(d+3)%4;
			if(space[r+dy[tmpD]][c+dx[tmpD]]==0 && !cleaned[r+dy[tmpD]][c+dx[tmpD]]) { // ���� ���� û�� ���� ���
				d=tmpD;
				r=r+dy[tmpD];
				c=c+dx[tmpD];
				cnt=0;
			}
			else { // û�� ������ ���� ���
				d=tmpD;
				cnt++;
			}
		}while(true);
	}
}
