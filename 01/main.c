#include <stdio.h>
#include <stdlib.h>

unsigned long int BinarySearch(unsigned long int trees[], unsigned long int LF,unsigned long int left, unsigned long int right) {
	unsigned long int index=(left+right)/2;
	//printf("[%lu;%lu;%lu]",left,index,right);
	if(LF<=trees[0])
		return 0;
	if(LF==trees[index])
	{
		while(LF==trees[index]&&index>0)
			index--;
		return index+1;
	}
	if((right-left)==1)
	{
		if(trees[right]<LF)
			return right+1;
		else
			return left+1;
	}	
	if(LF>trees[index])
		return BinarySearch(trees, LF, index, right);
	else
		return BinarySearch(trees, LF, left, index);
}


void merge(unsigned long int trees[], unsigned long int tmp[], unsigned long int left, unsigned long int right) {
	unsigned long int middleIndex = (left + right)/2;
	unsigned long int leftIndex = left;
	unsigned long int rightIndex = middleIndex + 1;
	unsigned long int tmpIndex = left;
	while (leftIndex <= middleIndex && rightIndex <= right) {
		if (trees[leftIndex] <= trees[rightIndex]) {
			tmp[tmpIndex] = trees[leftIndex++];
		} else {
			tmp[tmpIndex] = trees[rightIndex++];
		}
		tmpIndex++;
	}
	while (leftIndex <= middleIndex) {
		tmp[tmpIndex] = trees[leftIndex++];
		tmpIndex++;
	}
	while (rightIndex <= right) {
		tmp[tmpIndex] = trees[rightIndex++];
		tmpIndex++;
	}
}    


void mergeSort(unsigned long int trees[], unsigned long int tmp[], unsigned long int left, unsigned long int right) {
	if (left == right) return;
	unsigned long int middleIndex = (left + right)/2;
	mergeSort(trees, tmp, left, middleIndex);
	mergeSort(trees, tmp, middleIndex + 1, right);
	merge(trees, tmp, left, right);
	 
	for (unsigned long int i = left; i <= right; i++) {
		trees[i] = tmp[i];
	}
}   


int main() {
    unsigned long int n;
	unsigned long int obvod;
	unsigned long int * trees;
	unsigned long int * tmp;
	unsigned long int TotalTriangles;
	unsigned long int BadTriangles = 0;
	unsigned long int TreesInLoc;
    
    scanf("%lu",&n);
	scanf("%lu",&obvod);
	trees=(unsigned long int*)malloc(sizeof(unsigned long int)*n);
	tmp=(unsigned long int*)malloc(sizeof(unsigned long int)*n);
    
    for (unsigned long int i=0;i<n;i++)
    {
        scanf("%lu",&trees[i]);
		if(trees[i]==0)
			trees[i]=obvod;
    }

	mergeSort(trees,tmp,0,n-1);
	free(tmp);
	tmp=NULL;

    /*for (unsigned long int i=0;i<n;i++)
    {
		printf("%lu.-> %lu\n",i,trees[i]);
    }*/

	TotalTriangles=((n-2)*(n-1)*n)/6;

    for (unsigned long int i=0;i<n;i++)
    {
		//printf("Point: %lu\n",trees[i]);
        if(trees[i]+((obvod+1)/2)>obvod)
		{
			//unsigned long int Increment=i;
			//while((trees[Increment]==trees[Increment+1])&&(Increment<n))
			//	Increment++;
			TreesInLoc=n-i;
			//printf("-> Overex: FromX:%lu TillEnd Pts:%lu\n",trees[i],TreesInLoc);
			TreesInLoc=TreesInLoc+BinarySearch(trees,trees[i]+(obvod+1)/2-obvod,0,n-1);
			//printf("-> Overex: From0 -> To:%lu Binary:%lu\n",trees[i]+obvod/2-obvod,BinarySearch(trees,trees[i]+(obvod+1)/2-obvod,0,n-1));
			BadTriangles+=((TreesInLoc-1)*(TreesInLoc-2))/2;
			//printf("-> Pts:%lu TotalBad:%lu\n",TreesInLoc,BadTriangles);	
		}
		else
		{
			//unsigned long int Increment=i;
			//while((trees[Increment]==trees[Increment+1])&&(Increment<n))
			//	Increment++;
			TreesInLoc=BinarySearch(trees,trees[i]+(obvod+1)/2,0,n-1)-i;
			BadTriangles+=((TreesInLoc-1)*(TreesInLoc-2))/2;
			//printf("-> OK: FromX:%lu Till:%lu\n",trees[i],trees[i]+(obvod+1)/2);
			//printf("-> Pts:%lu TotalBad:%lu Binary:%lu\n",TreesInLoc,BadTriangles,BinarySearch(trees,trees[i]+(obvod+1)/2,0,n-1));
		}
    }
	//printf("BadTriangles:%lu\n",BadTriangles);
	printf("%lu\n",TotalTriangles-BadTriangles);
	free(trees);
	trees=NULL;
    return (0);
}

