			         	          /*Fractional Knapsack problem solving using Greedy Method*/
#include<bits/stdc++.h>
using namespace std;

//Template of each item
class item
{
	public:
		int price;
		int weight;
};

//Function block to calculate price/weight value of each item
bool ratio(item i1,item i2)
{
	double a,b;
	a=i1.price/i1.weight;
	b=i2.price/i2.weight;
	return a>b;
}

//Function Block to calculate the maximum profit 
void maxprofit(item it[],int n,int w)
{
	sort(it,it+n,ratio); //List of items sorted on the basis of decreasing order of price/weight ratio
	
	double profit=0.0;
	int current_weight=0;
	
	for(int i=0;i<n && w>current_weight;i++)
	{
		//If on addition of the current item,the resultant weight does not exceed the weight of knapsack 
		if(current_weight+it[i].weight<=w)
		{
			cout<<"\nEntire amount of the item with price "<<it[i].price<<" is put in the knapsack.";
			current_weight+=it[i].weight;
			profit+=it[i].price;
		}
		
		//If the current item's weight makes total weight exceed the weight of knapsack,it is considered partly
		else
		{
			int remain=w-current_weight; //The weight that can still  be fitted in the knapsack
			double frac=(double) remain/ (double) it[i].weight; //The fraction of weight of the item to be taken
			cout<<"\n"<<frac<<" fraction of the item with price "<<it[i].price<<" is put in the knapsack.";
			profit+=it[i].price*frac;
			current_weight+=it[i].weight*frac;
		}
		
		cout<<"\n"<<current_weight<<" "<<profit<<endl;
	}
	
	cout<<"\nMaximum profit is-"<<profit<<endl;
	
}

//Driver Code
int main (void)
{
	int n,w;
	
	//Input for weight capacity of the Knapsack
	cout<<"\nEnter the maximum weight capacity of the Knapsack-";
	cin>>w;
	
	//Input for total no of items under consideration
	cout<<"\nEnter the number of items to be considered-";
	cin>>n;
	
	//Array type object of the class item
	item it[n];
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nFor element "<<i+1<<endl;
		cout<<"\tEnter the price-";
		cin>>it[i].price;
		cout<<"\n\tEnter the weight-";
		cin>>it[i].weight;
	}
	
	//Function called to find the maximum profit that can be obtained by placing the items completely or partly in the knapsack
	maxprofit(it,n,w);
	
	return 0;
}
