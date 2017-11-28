#include <cstdio>
using namespace std;
const int MAX = 25000;
typedef struct _Node
{
	int		left;
	int		right;
}Node;
Node	data[MAX];
void	quicksort( int left , int right )
{
	int i = left;
	int j = right;
	int key = data[i].left;
	Node mid = data[i];
	while( i < j )
	{
		while( data[j].left > key && i < j )
			--j;
		if( i < j )
			data[i++] = data[j];
		while( data[i].left < key && i < j )
			++i;
		if( i < j )
			data[j--] = data[i];
	}
	data[i] = mid;
	if( left < i - 1 )
		quicksort( left , i - 1 );
	if( i + 1 < right )
		quicksort( i + 1 , right );
}
int main()
{
	int n , target , i , maxi,max,k;
	scanf("%d%d",&n,&target);
	for( int i = 0 ; i != n ; ++i )
		scanf("%d%d",&data[i].left , &data[i].right );
	quicksort( 0 , n - 1 );
	max = 0;i = 0 ; k = 0 ;
	while( max < target )
	{
		maxi = -1 ;
		for( ; i < n && data[i].left <= max + 1 ; ++i )
			if( data[i].right > maxi )
				maxi = data[i].right;
		if( maxi == -1 )
			break;
		max = maxi;
		++k;
	}
	if( max < target )
		printf("-1\n");
	else
		printf("%d\n",k);
}