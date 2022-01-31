/*

Definition : Find the minimum average waiting time

Time complexity : O(nlogn)

Space complexity : O(n)

Author : Deep Chaklasiya

*/


#include<bits/stdc++.h>
using namespace std;

int minimumAverageTime(vector<pair<int, int>>&customer, int n)
{
	int totalWaitingTime = 0, index = 0;

	/*Logic :
		Here, Priority queue give 1 customer that is suitable for condition and minimize average waiting time
		and best customer present at top of the queue so we can remove it in O(1) time.

	*/
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	int curtime = customer[index].first;
	while (index < n or !pq.empty())
	{
		while (index < n && customer[index].first <= curtime)
		{
			/* Consider all customers who are arrived till now	*/
			pq.push({customer[index].second, customer[index].first});
			index++;
		}
		if (pq.empty())
		{
			/*If none of customer present, consider current customer as a suitable			*/
			curtime = customer[index].first;
		}
		else
		{
			pair<int, int>p = pq.top();
			pq.pop();
			/*Increment the current time by required time of the customer			*/
			curtime += (p.first);
			/* Increment totalwaitingtime by the time differene between when customer arrives and when customer leaves*/
			totalWaitingTime += (curtime - p.second);
		}
	}
	return totalWaitingTime / n;
}

int main()
{
	int numberOfCustomer;
	cin >> numberOfCustomer;
	vector<pair<int, int>> customer;
	for (int i = 0; i < numberOfCustomer; i++)
	{
		int orderTime, RequiredTime;
		cin >> orderTime >> RequiredTime;
		customer.push_back({orderTime, RequiredTime});
	}

	// sort the customers according to their order time
	sort(customer.begin(), customer.end());
	cout << minimumAverageTime(customer, numberOfCustomer);
	return 0;
}