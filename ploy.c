/*
 * =====================================================================================
 *
 *       Filename:  threads.c
 *
 *    Description:  Example code to show how to use posix threads
 *
 *        Version:  1.0
 *        Created:  2016年06月14日 10时38分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian 
 *
 * =====================================================================================
 */
#include "polymorphism.h"
#include "TYheader.h"
/*近似根类Shape的方法定义组*/
void displayShape(){printf("Shape\n");}
void ShapeSetX(void *voidShape, int x){Shape *shape = (Shape*)voidShape;shape->x = x;}
void ShapeSetY(void *voidShape, int y){Shape *shape = (Shape*)voidShape;shape->y = y;}
int ShapeGetX(void *voidShape){Shape *shape = (Shape*)voidShape;return shape->x;}
int ShapeGetY(void *voidShape){Shape *shape = (Shape*)voidShape;return shape->y;}

/*近似派生类Rect的方法定义组*/
void displayRect(){printf("Rect\n");}
void RectSetW(void *voidRect, int x){Rect *rect = (Rect *)voidRect;rect->w = x;}
void RectSetH(void *voidRect, int y){Rect *rect = (Rect *)voidRect;rect->h = y;}
int RectGetW(void *voidRect){Rect *rect = (Rect *)voidRect;return rect->w;}
int RectGetH(void *voidRect){Rect *rect = (Rect *)voidRect;return rect->h;}


/*近似根类Shape的构造函数组*/
Shape *newShape()
{
	Shape *shape = (Shape *)malloc(sizeof(Shape));
	shape->x = 10;
	shape->y = 10;
	shape->function.setX = ShapeSetX;
	shape->function.getX = ShapeGetX;
	shape->function.setY = ShapeSetY;
	shape->function.getY = ShapeGetY;
	shape->function.display = displayShape;
	return shape;
}

/*近似派生Rect的构造函数组*/
Rect *newRect()
{
	Rect *rect = (Rect *)malloc(sizeof(Rect));
	rect->w = 20;
	rect->h = 30;
	rect->base.function.setX = RectSetW;
	rect->base.function.getX = RectGetW;
	rect->base.function.setY = RectSetH;
	rect->base.function.getY = RectGetH;
	rect->base.function.display = displayRect;
	return rect;
}

int main(int argc, char const *argv[])
{
	int i;

	Shape *sptr[2];
	sptr[0] = newShape();
	sptr[1] = newShape();
	sptr[0]->function.setX(sptr[0],111);
	sptr[1]->function.setX(sptr[1],112);

	for (i = 0; i < 2; ++i)
	{
		sptr[i]->function.display();
		printf("(%d, %d)\n", sptr[i]->function.getX(sptr[i]), sptr[i]->function.getY(sptr[i]));
	}
	
	Rect *rect = newRect();
	rect->base.function.display();
	printf("(%d, %d)\n", rect->base.function.getX(rect), rect->base.function.getY(rect));

	free(sptr[0]);sptr[0]=NULL;
	free(sptr[1]);sptr[1]=NULL;
	free(rect);rect=NULL;

	return 0;
}
