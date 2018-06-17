#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
// STRUNTURA TABULKY, RETEZICI KOLIZE
struct ChainingTable{
	ChainingTable(long int val,std::string& nm){value=val;chain=NULL;name=nm;};
	~ChainingTable(){};
	long int value;
	std::string name;
	ChainingTable * chain;
};
// STRUKTURA OBOU STACKU
struct xSTACKelem{
	xSTACKelem(xSTACKelem * prevelem, long int val){prev=prevelem;value=val;next=NULL;};
	xSTACKelem(xSTACKelem * prevelem, long int val, long int val2){prev=prevelem;value=val;value2=val2;next=NULL;};
	~xSTACKelem(){};
	xSTACKelem * prev;
	xSTACKelem * next;
	long int value;
	long int value2;
};
// STACK PRO POCITANI VELIKOSTI DILKU
struct xCOUNTER{
	xCOUNTER(){createrear=1;rear=NULL;}
	~xCOUNTER(){};
	bool Push(long int elem){
		if(!rear&&createrear)
		{
			rear=new xSTACKelem(NULL,elem*-1,0);
			createrear=0;
			return true;
		}
		if(!rear)
		{
			return false;
		}
		rear->value2+=(-1*elem);
		if(rear->value2>rear->value)
			return false;
		rear->next=new xSTACKelem(rear,-1*elem,0);
		rear=rear->next;
		return true;
	};
	bool Pop()
	{
		if(!rear)
		{
			return false;
		}
		else
		{
			if(!rear->prev)
			{
				delete rear;
				rear=NULL;
				return true;
			}
			else
			{
				rear=rear->prev;
				delete rear->next;
				rear->next=NULL;
			}
			return true;
		}
	};
	bool createrear;
	xSTACKelem * rear;
};
// STACK PRO SPRAVNE OTEVIRANI, ZAVIRANI DILKU
struct xSTACK{
	xSTACK(){rear = NULL;fail=0;};
	~xSTACK(){};
	long int GetLast(){
		if(rear)
			return rear->value;
		else 
			return 0;
		};
	bool Push(long int elem){
		if(!deep.Push(elem))
			fail=1;
		if(!rear)
		{
			rear=new xSTACKelem(NULL,-1*elem);
		}
		else
		{
			rear->next=new xSTACKelem(rear,-1*elem);
			rear=rear->next;
		}
		return true;
	};
	bool Pop()
	{
		if(!deep.Pop())
			fail=1;
		if(!rear)
		{
			fail=1;
			return false;
		}
		else
		{
			if(!rear->prev)
			{
				delete rear;
				rear=NULL;
			}
			else
			{
				rear=rear->prev;
				delete rear->next;
				rear->next=NULL;
			}
			return true;
		}
	};
	/*void Print()
	{
		xSTACKelem * printer=rear;
		while(printer)
		{
			std::cout << "<-" << printer->value;
			printer=printer->prev;
		}
		std::cout << std::endl;
	};*/
	xSTACKelem * rear;
	bool fail;
	xCOUNTER deep;
};
// HASHOVACI FUNKCE
unsigned long hash(std::string& str)
{
    unsigned long hash = 5381;
    int c;
	int i=0;
    while (str[i])
	{
		c=str[i];
        hash = ((hash << 5) + hash) + c;
		i++;
	}

    return hash;
}
// ----------------------------------------------------------
int main ( int argc, char * argv [] )
 {
	std::string BestBoy;
	long int TopScore=0;
	bool fail=0;
	long int n;
  	std::string input;
	long int inputval;
	xSTACK bracket;
	std::string EmptyString="";
	scanf("%ld",&n);
	ChainingTable ** table=(ChainingTable**)malloc(sizeof(ChainingTable*)*n);
	for(int i=0;i<n;i++)
	{
		table[i]=new ChainingTable(0,EmptyString);
	}


	for (long int i=0;i<n;i++)
	{
		scanf("%ld ",&inputval);
		getline(std::cin,input);
		ChainingTable * mover=table[hash(input)%n];
		// Leva cast matriosky
		if(inputval<0)
		{
			bracket.Push(inputval);
			while(input!=mover->name)
			{
				if(mover->name=="")
				{
					mover->name=input;
					break;
				}
				if(!mover->chain)
				{
					mover->chain=new ChainingTable(0,EmptyString);
					mover=mover->chain;
					mover->name=input;
					break;
				}
				mover=mover->chain;
			}
			mover->value+=(inputval*-1);
		}
		// Prava cast matriosky
		else
		{
			if(bracket.GetLast()==0)
			{
				fail=1;
			}
			else
			{
				if(bracket.GetLast()==inputval)
					bracket.Pop();
				else
				{
					fail=1;
				}
			}
			while(input!=mover->name)
			{
				if(mover->name=="")
				{
					mover->name=input;
					break;
				}
				if(!mover->chain)
				{
					mover->chain=new ChainingTable(0,EmptyString);
					mover=mover->chain;
					mover->name=input;
					break;
				}
				mover=mover->chain;
			}
			mover->value+=inputval;
		}
		// Pocitani nejlepsiho ditete
		if(mover->value==TopScore)
		{
			if(BestBoy>mover->name)
				BestBoy=mover->name;
		}
		else
		if(mover->value>TopScore)
		{
			BestBoy=mover->name;
			TopScore=mover->value;
		}
		/*for(int i=0;i<n;i++)
		{
			std::cout << "-" << table[i]->name << ":" << table[i]->value;
			mover=table[i];
			while(mover->chain)
			{
				mover=mover->chain;
				std::cout << "->" << mover->name << ":" << mover->value;
			}
			std::cout << std::endl;
		}*/
		if(!fail)
			fail=bracket.fail;
		/*if(fail)std::cout << "FAIL!"<< std::endl;
		bracket.Print();*/
	}
	if(bracket.GetLast()!=0)
		fail=1;
	/*	if(fail)std::cout << "FAIL!"<< std::endl;*/
	if(fail)
		std::cout << "Ne" << std::endl;
	else
		std::cout << "Ano" << std::endl;
	std::cout << BestBoy << std::endl;

	return(0);
 }

















