#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>

struct XStackItem{
	XStackItem(long int value,XStackItem * previouz){
		val=value;
		prev=previouz;
		next=NULL;
	};
	~XStackItem() {};
	long int val;
	XStackItem * prev;
	XStackItem * next;
};

struct XStack{
	XStack(){
		bottom=NULL;
		last=NULL;
	};
	~XStack(){};
	void Push(long int val){
		if(bottom==NULL||last==NULL)
		{
			bottom=new XStackItem(val,NULL);
			last=bottom;
		}
		else
		{
			last->next=new XStackItem(val,last);
			last=last->next;
		}
	};
	long int Pop(){
		long int returnthis;
		if(last==NULL)return -1;
		returnthis=last->val;
		if(last->prev!=NULL)
		{
			
			last=last->prev;
			delete last->next;
			last->next=NULL;
			return returnthis;
		}
		delete bottom;
		bottom=NULL;
		last=NULL;
		return returnthis;
	};
	void Print()
	{
		XStackItem * move=bottom;
		while(move)
		{
			printf("%li",move->val);
			move=move->next;
		}
		printf("\n");
	}
	XStackItem * bottom;
	XStackItem * last;
};

struct TNode{
	TNode(long int n){
		TotalCon=n;
		MaxCon=n;
		Con=(long int*)malloc(sizeof(long int)*TotalCon);
		ConVal1=0;
		ConVal2=1;
		parent=NULL;
		Rdy=0;
	};
	~TNode(){};
	TNode * parent;
	long int ConVal1;
	long int ConVal2;
	long int TotalCon;
	long int MaxCon;
	long int * Con;
	bool Rdy;
};

void SetParent(TNode& tnoud, long int Parent){
	

}

int main()
{
	XStack lists;
	long int nodes;
	long int nodeCon;
	long int tmpInput;
	scanf("%li",&nodes);
	TNode * Tree = (TNode*)malloc(sizeof(TNode)*nodes);
	for(long int i=0;i<nodes;i++)
	{
		scanf("%li",&nodeCon);
		Tree[i]=TNode(nodeCon);
		for(long int i2=0;i2<nodeCon;i2++)
		{
			scanf("%li",&tmpInput);
			Tree[i].Con[i2]=tmpInput;
		}
		if(nodeCon == 1)
			lists.Push(i);
	}
		if(nodes==1)
		{
			printf("1\n");
			return 0;
		}
	long int popped;
	//lists.Print();
	while((popped=lists.Pop())>=0){
		//lists.Print();
		//printf("(%li|%li|%li|%li)\n",popped,Tree[popped].ConVal1,Tree[popped].ConVal2,Tree[popped].Con[0]);
		if(Tree[Tree[popped].Con[0]].TotalCon==1&&Tree[popped].TotalCon==1)
		{
			//printf("OMG%liOMG",Tree[popped].Con[0]);
			Tree[popped].ConVal1+=(Tree[Tree[popped].Con[0]].ConVal1+Tree[Tree[popped].Con[0]].ConVal2);
			Tree[popped].ConVal1=Tree[popped].ConVal1%536870909;
			Tree[popped].ConVal2=(Tree[popped].ConVal2*(Tree[Tree[popped].Con[0]].ConVal2+1))%536870909;
			printf("%li\n",(Tree[popped].ConVal1+Tree[popped].ConVal2)%536870909);
			break;
		}
		if(Tree[popped].TotalCon==1)
		{
			Tree[popped].Rdy=1;
			//printf("Rdy %li\n",popped);
		}
		Tree[Tree[popped].Con[0]].ConVal1+=(Tree[popped].ConVal1+Tree[popped].ConVal2);
		Tree[popped].ConVal1=Tree[popped].ConVal1%536870909;
		Tree[Tree[popped].Con[0]].ConVal2=(Tree[Tree[popped].Con[0]].ConVal2*(Tree[popped].ConVal2+1))%536870909;
		Tree[Tree[popped].Con[0]].TotalCon--;
		if(Tree[Tree[popped].Con[0]].TotalCon==1)
		{
			//printf("For started!\n");
			lists.Push(Tree[popped].Con[0]);
			for(long int x=0;x<Tree[Tree[popped].Con[0]].MaxCon;x++)
			{
				if(Tree[Tree[Tree[popped].Con[0]].Con[x]].Rdy==0)
				{
					Tree[Tree[popped].Con[0]].Con[0]=Tree[Tree[popped].Con[0]].Con[x];
					//printf("Set %li for %li\n",Tree[Tree[popped].Con[0]].Con[x],Tree[popped].Con[0]);
					break;
				}
			}
		}
		//lists.Print();
	}
	return 0;
}
