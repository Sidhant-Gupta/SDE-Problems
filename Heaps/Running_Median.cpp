// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1/?track=ppc-heap&batchId=221

void FindMedian::insertHeap(int &x)
{
    if(max.empty()){
        max.push(x);
        median=x;
        return;
    }
    if(x<=max.top()){
        max.push(x);
    }
    else{
        min.push(x);
    }
    if(abs(max.size()-min.size())>1){
        if(max.size()>min.size()){
            min.push(max.top());
            max.pop();
        }
        else{
             max.push(min.top());
            min.pop();
        }
    }
    
    if(max.size()==min.size())
        median= (max.top()+min.top())/2.0;
    else
    {
        if(max.size()>min.size())
            median=max.top();
        else
            median= min.top();
    }
}