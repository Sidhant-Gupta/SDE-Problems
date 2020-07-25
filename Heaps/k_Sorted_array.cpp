// https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1/?track=ppc-heap&batchId=221

// normal sort nLogN

// nlog k
vector <int> nearlySorted(int arr[], int num, int K){
    vector<int>sol;
    priority_queue<int,vector<int>,greater<int>> pq;
    int i;
    for( i=0;i<=K;i++){
        if(i<num)
            pq.push(arr[i]);
    }
    i--;
    while(!pq.empty()){
        sol.push_back(pq.top());
        // cout<<pq.top()<<" ";
        pq.pop();
        i++;
        if(i<num){
            pq.push(arr[i]);
            // cout<<arr[i]<<" ";
        }
    }
    return sol;
}