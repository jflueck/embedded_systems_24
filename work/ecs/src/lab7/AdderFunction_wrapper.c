
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 8
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void AdderFunction_Outputs_wrapper(const boolean_T *u0,
			boolean_T *y0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
unsigned char sumA;
unsigned char sumB;
unsigned char result;
int i;
/* convert the inputs to two unsigned char numbers*/
sumA = (unsigned char)u0[0]
| (unsigned char)u0[1] << 1
| (unsigned char)u0[2] << 2
| (unsigned char)u0[3] << 3;
sumB = (unsigned char)u0[4]
| (unsigned char)u0[5] << 1
| (unsigned char)u0[6] << 2
| (unsigned char)u0[7] << 3;
/* get the sum of the two numbers */
result = sumA + sumB;
/* display the two numbers*/
for(i = 0; i < 5; i++)
{
y0[i] = (result & (1<<i)) ? 1 : 0;
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


