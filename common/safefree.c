/*
 * =====================================================================================
 *
 *       Filename:  safefree.c
 *
 *    Description:  Modified free() function for a better performance.
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 09时57分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y .Tian
 * =====================================================================================
 */
#include "TYheader.h"
void safeFree(void **p){
    if(p != NULL && *P != NULL){
        free(*p);
        *p =NULL;
    }
}
