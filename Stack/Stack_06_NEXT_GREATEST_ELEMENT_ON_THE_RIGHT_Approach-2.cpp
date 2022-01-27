#include <bits/stdc++.h>
using namespace std;
void display(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
}
vector<int> solve(vector<int> arr)
{
	stack<int> st;
	vector<int> nge(arr.size());
	st.push(0);
	for (int i = 1; i < arr.size(); i++)
	{
		while (st.size() > 0 && arr[i] > arr[st.top()])
		{
			int pos = st.top();
			nge[pos] = arr[i];
			st.pop();
		}
		st.push(i);
	}
	while (st.size() > 0)
	{
		int pos = st.top();
		nge[pos] = -1;
		st.pop();
	}
	return nge;
}
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int> nge(n, 0);
	nge = solve(arr);
	display(nge);
	return 0;
}
