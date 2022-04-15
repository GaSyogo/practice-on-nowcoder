Description
Merges k ascending chains and returns the result as an ascending chain with its head node.

Data range: total number of nodes satisfies  0≤n≤10^5
and the number of links satisfies 1≤k≤10^5
and the length of each link table satisfies  \1 ≤ len ≤ 200 
and the value of each node satisfies val <=1000
Requirement: Time complexity O(nlogk)O(nlogk)
Example 1
Input.
[{1,2,3},{4,5,6,7}]
Return value.
{1,2,3,4,5,6,7}
Example 2
Input.
[{1,2},{1,4,5},{6}]
Return value.
{1,1,2,4,5,6}
