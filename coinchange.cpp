// A Dynamic Programming based C++ program to find minimum of coins
// to make a given change V
#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
	// table[i] will be storing the minimum number of coins
	// required for i value. So table[V] will have result
	int table[V+1];
	int coinsSelected[V+1];

	// Base case (If given value V is 0)
	table[0] = 0;
	int f=0;

	// Initialize all table values as Infinite
	for (int i=1; i<=V; i++){
	   table[i] = INT_MAX;
	   coinsSelected[i]=0; 
	}
		

	// Compute minimum coins required for all
	// values from 1 to V
	for (int i=1; i<=V; i++)
	{
		// Go through all coins smaller than i
		for (int j=0; j<m; j++)
		if (coins[j] <= i)
		{
			int sub_res = table[i-coins[j]];
// 			cout<<sub_res<<endl;
			if (sub_res != INT_MAX && sub_res + 1 < table[i])
			    if(i==V){
			        coinsSelected[f]=coins[j];
			        f+=1;
			    }
				table[i] = sub_res + 1;
		}
	}

	if(table[V]==INT_MAX)
		return -1;
	int result=0;
	int selected=0;
	int value=V;
	
	while(value>0){
		int count=1;
	    for (int i=0; i<value; i++){
	    if(coinsSelected[i]<=value && coinsSelected[i]>0){
	        result=coinsSelected[i];
	    }
	   }
	    cout<<"Coin " <<count<<" chosen is "<<result<<endl;
	    value=value-result;
		count+=1;
	    
	    
	}
	
		
		
	

	return table[V];
}


// Driver program to test above function
int main()
{
	int coins[] = {1,4,9,16,25,49};
	int m = sizeof(coins)/sizeof(coins[0]);
	int V = 50;
	cout << "Minimum coins required is "<<endl;
	cout<<"Total coins: "<< minCoins(coins, m, V);
	return 0;
}
