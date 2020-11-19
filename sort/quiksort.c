/*
 * @author	:	WangZX
 * @created on	:	2020.11.7
 * @brief	:	试验简单的排序算法
 * /

/* Include ----------------------------------------------------------------- */
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
/* ------------------------------------------------------------------------- */

/* Function Propotype -------------------------------------------------------*/
/*
 * @author	:	WangZX
 * @created on	:	2020.11.7
 * @bried	:	交换两数的值
 * @param	:	a	第一个数的指针
 * 			b	第二个数的指针
 * @retval	:	None
 * */
void swap (int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	return;
}

/*
 * @author	:	WangZX
 * @created on	:	2020.11.7
 * @brief	:	分治法和递归实现快速排序
 * @param	:	nums		要排序的数组
 * 			numsSize	要排序的数组的长度
 * @retval	:	None	
 * */
void quikSort (int* nums, int numsSize) {
	int *left, *right;
	int leftSize = 0, rightSize = 0;
	if ( !(left = (int*)malloc( sizeof(int)*numsSize) ) )
	{
		return;
	}
	if (! (right = (int*)malloc( sizeof(int)*numsSize) ) )
	{
		return;
	}

	int pivot = nums[0];
	for (int i = 1; i < numsSize; ++i)
	{
		if(nums[i] <= pivot)
		{
			left[leftSize++] = nums[i];
		}
		else
		{
			right[rightSize++] = nums[i];
		}
	}

	if(leftSize != 0)
	{
		quikSort(left, leftSize);
	}
	if(rightSize != 0)
	{
		quikSort(right, rightSize);
	}

	for (int i = 0; i < numsSize; ++i)
	{
		if(i < leftSize)
		{
			nums[i] = left[i];
		}
		else if(i == leftSize)
		{
			nums[i] = pivot;
		}
		else
		{
			nums[i] = right[i - leftSize - 1];
		}
	}
	free(left);
	free(right);
	return;	
}

/* ------------------------------------------------------------------------- */


/* Main Function ------------------------------------------------------------*/
/*	算法测试	*/
int main(void)
{
	int a[30] = {0};
	srand(time(0));
	for (int i = 0; i < 30; ++i)
	{
		a[i] = rand()%100;
	}
	for (int i = 0; i < 30; ++i)
	{
		printf("%d ", a[i]);
	}
	quikSort(a, 30);
	printf("\n");
	for (int i = 0; i < 30; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}



