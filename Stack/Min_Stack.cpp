// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
// https://leetcode.com/problems/min-stack/

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
   if(s.empty())
        return -1;
    return s.top();
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty())
        return -1;
    s.pop();
    int ans=s.top();
    s.pop();
    return ans;
}

/*push element x into the stack*/
void _stack::push(int x)
{
    minEle=getMin();
    if(s.empty())
        minEle=x;
    s.push(x);
    if(x<minEle)
        minEle=x;
    s.push(minEle);
}