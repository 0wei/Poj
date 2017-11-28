#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double x,y,radius;
	int score[2],w;
	while(1)
	{
		memset(score,0,sizeof(score));
		for(int i = 0; i< 6; i++)
		{
			cin>>x>>y;
			if(x==-100)
				return 0;
			radius = sqrt(x*x+y*y);
			if(i<3)
				w=0;
			else w=1;
			if(radius<=3) score[w]+=100;
			else if(radius<=6) score[w]+=80;
			else if(radius<=9) score[w]+=60;
			else if(radius<=12) score[w]+=40;
			else if(radius<=15) score[w]+=20;
		}
		printf("SCORE: %d to %d, ",score[0],score[1]);
		if(score[0]>score[1])
			printf("PLAYER 1 WINS.\n");
		else if(score[0]<score[1])	printf("PLAYER 2 WINS.\n");
		else printf("TIE.\n");
	}
	return 0;
}