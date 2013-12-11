/*
 * Solution for NCPC 2013 problem "Virus" by Jaap Eldering
 *
 * Wrong: doesn't check for length increase when strings matches
 * from left and right overlap.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string before, after;

	cin >> before >> after;

	int lo, hi, diff = after.length() - before.length();

	for(lo=0; lo<min(before.length(),after.length()); lo++)
		if ( before[lo]!=after[lo] ) break;

	for(hi=after.length()-1; hi>=max(0,diff); hi--)
		if ( before[hi-diff]!=after[hi] ) break;

	int len = hi-lo+1;
	if ( len<=0 ) len = 0;

	cout << len << endl;

	return 0;
}
