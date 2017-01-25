#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UINT unsigned int
#define PI 3.14159265
#define CIRCURL 360
typedef struct HexagonPoint
{
     UINT x;
     UINT y;
     UINT z;
     UINT layer;
     UINT serial_num;
 }HexagonPoint;


static UINT g_maxValue=0;

int InitCellularDistrict(int iMaxSeqValue)
{
	if( iMaxSeqValue>=0 && iMaxSeqValue<=100000 )
	{
		g_maxValue=iMaxSeqValue;
		return 0;
	}
	else
		return -1;
}

UINT maxValue(UINT layer)						    
{
	/*
	方式1：递归求解,每层最大值，比上一层多6i
	
	if(layer==0)
		return 1;
	else
		return 6*layer+maxValue(layer-1);
	
	方式2：循环求解，每层个数比上一层多6个，原点不算
	
	UINT temp=1;
	for (UINT i = 1; i <=layer ; ++i)
	{
		temp+=6*i;
	}
	return temp;
	*/
	//方式3：利用公司直接求解，每层最大值为6i(i+1)/2+1 => 3i(i+1)+1
	return 3*layer*(layer+1)+1;

}

void initHexagonPoint( UINT num, HexagonPoint* point )
{
	if ( point == NULL || num <= 0 )
		return;
	UINT	tempLayer;
	UINT	maxValueofLayer;
	UINT	side;
	UINT	step;
	if ( num == 1 )
	{
		maxValueofLayer		= 1;
		point->serial_num	= num;
		point->x		= 0;
		point->y		= 0;
		point->z		= 0;
	}else  {
		// method1:use loop to find the layer number
		// for ( tempLayer = 1; maxValue( tempLayer ) < num; tempLayer++ );
		//method2: 3i^2+3i+1>=num => 3i^2+3i+(1-num)>=0 => result is i and [i] is the layer with the largest number.
		tempLayer=ceil(sqrt((12*num-3)-3)/6);
		
		maxValueofLayer = maxValue( tempLayer );
		printf("%d",tempLayer);
		side		= (maxValueofLayer - num) / tempLayer;
		step		= (maxValueofLayer - num) % tempLayer;
		switch ( side )
		{
		case 0: point->x	= tempLayer; 	point->y = -tempLayer + step; 	point->z = point->x + point->y; break;
		case 1: point->z	= tempLayer; 	point->y = step; 				point->x = point->z - point->y; break;
		case 2: point->y	= tempLayer; 	point->z = tempLayer - step; 	point->x = point->z - point->y; break;
		case 3: point->x	= -tempLayer; 	point->y = tempLayer - step; 	point->z = point->x + point->y; break;
		case 4: point->z	= -tempLayer; 	point->y = -step; 				point->x = point->z - point->y; break;
		case 5: point->y	= -tempLayer; 	point->z = -tempLayer + step; 	point->x = point->z - point->y; break;
		default: break;
		}
	}
}
int GetShortestPathLength( int iFirstValue, int iSecondValue )
{
	if ( iFirstValue <= 0 || iSecondValue <= 0 )
		return(-1);
	if ( iFirstValue > g_maxValue || iSecondValue > g_maxValue )
		return(-1);
	if ( iFirstValue == iSecondValue )
		return(0);

	HexagonPoint	* point1	= (HexagonPoint *) malloc( sizeof(HexagonPoint) );
	HexagonPoint	* point2	= (HexagonPoint *) malloc( sizeof(HexagonPoint) );

	initHexagonPoint( iFirstValue, point1 );
	initHexagonPoint( iSecondValue, point2 );

	printf( "%d\t%d\t%d\n", point1->x, point1->y, point1->z );
	printf( "%d\t%d\t%d\n", point2->x, point2->y, point2->z );

	int	diffX	= abs(point1->x - point2->x);
	int	diffY	= abs(point1->y - point2->y);
	int	diffZ	= abs(point1->z - point2->z);
	printf("%d\n",diffX);
	printf("%d\n",diffY);
	printf("%d\n",diffZ);
	free( point1 ); point1	= NULL;
	free( point2 ); point2	= NULL;

	return(diffX > diffY ? (diffX > diffZ ? diffX : diffZ) : (diffY > diffZ ? diffY : diffZ) );
}

int main(int argc, char **argv)
{
	InitCellularDistrict(100000);
	printf("%d\n",GetShortestPathLength(100000,1));
	return 0;
}
