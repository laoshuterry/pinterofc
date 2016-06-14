/*
 * =====================================================================================
 *
 *       Filename:  polymorphism.h
 *
 *    Description:  Example code to show how to use polymorphism  
 *
 *        Version:  1.0
 *        Created:  2016年06月14日 10时38分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y.Tian 
 *
 * =====================================================================================
 */
#ifndef _POLYMORPHISM_H
#define _POLYMORPHISM_H
#endif

typedef void (*fptrSet)(void*, int);
typedef int  (*fptrGet)(void*);
typedef void (*fptrDisplay)();

typedef struct _vfunc
{
	fptrSet 	setX;
	fptrGet 	getX;
	fptrSet 	setY;
	fptrGet 	getY;
	fptrDisplay display;	
} vFunc;

typedef struct _shape
{
	vFunc function;
	int x;
	int y;
} Shape;

typedef struct _rect
{	
	Shape base;
	int w;
	int h;
} Rect;

