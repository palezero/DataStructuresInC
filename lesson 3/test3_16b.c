#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void unique(int* data, int length);
void print(int* data, int length);
void Delete(int* data, int length, int position);
int main()
{
	int data[30] = {0,0,0,1,1,
					3,4,5,5,6,
					7,7,8,8,8, 
					9,9,9,10,10,
					11,12,15,17,19,
					19,19,19,19,20};
	 unique(data,30);
	print(data,30);
	return 0;
}
void unique(int* data, int length)
{
	int i,j,count = 0,LastPosition = length - 1;
	for(i = 0; i < LastPosition; i++)
	{
		j = i + 1;
		while(j <= LastPosition)
			if(data[i] == data[j])
			{
				Delete(data, length, j);
				LastPosition--;//如果不进行这一步操作，那么就会卡在后面添加的0那里死循环
			}
			else
				j++;
	}
}
void Delete(int* data, int length, int position)
{
	int i;
	for(i = position; i < length-1; i++)
		data[i] = data[i+1];
	data[length-1] = 0;
}
void print(int* data, int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
		printf("%d\n", data[i]);
}