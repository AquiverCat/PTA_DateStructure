/* 01-复杂度2 Maximum Subsequence Sum

Given a sequence of K integers { N1,N2,...,NK}. A continuous subsequence is defined to be{Ni,Ni+1,...,N​j}where 1≤i≤j≤K. 
The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given 
sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). 
The second line contains K numbers, separated by a space.
Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence.
The numbers must be separated by one space, but there must be no extra space at the end of a line. 
In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). 
If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last
numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21

Sample Output:
10 1 4
*/
#include <stdio.h>

void MaxSubseqSum(int A[], int N)
{	 
    int ThisSum = 0, MaxSum = 0;
    int start, end;         //当前已找到最大子序列的第一个元素和最后一个元素
    int tmp = A[0];         //暂时存储正在扫描子序列的第一个元素
    int max = A[0];         //存储序列中的最大元素
    int i;
    for (i = 0; i < N; i++)
    {
        ThisSum += A[i];
        if(A[i] > max)
        {
           max = A[i];      //获得序列中的最大值
        }
        if(ThisSum > MaxSum)
        {
            MaxSum = ThisSum;       //获得已扫描序列元素的子序列最大和
			start = tmp;            //保存子序列的第一个元素值
            end = A[i];             //保存子序列的最后一个元素值
        }
         else if (ThisSum < 0)      //如果当前子序列和为负，将下一个元素作为子序列的第一个元素，未找到最大值之前，不更新start变量
        {
            ThisSum = 0;
            tmp = A[i + 1];
        }
    }
    if(max < 0)
    {
        start = A[0];
        end = A[N - 1];
    }
     else if(max == 0)
    {
        start = end = 0;
    }
    printf("%d %d %d", MaxSum, start, end);
}
 
int main()
{
    int N;
    scanf("%d", &N);
    int num[N];
    int i;
    for (i = 0; i < N; ++i)
    {
       scanf("%d", &num[i]);
    }
    MaxSubseqSum(num, N);
    return 0;
}
