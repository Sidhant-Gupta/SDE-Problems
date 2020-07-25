// https://practice.geeksforgeeks.org/problems/kth-largest-element5034/1/?track=ppc-heap&batchId=221

// Method 1 - sort nlogn and return element at k-i ind
// method 2 - nax heap , pop k-1 times, top element is ans   --->same time complexity

// Method 3- use alternate heap, if largest element than min heap else max 
// N LOG K

int KthLargest(int arr[], int n, int k) {
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int i=0;i<k;i++)
        pq.push(arr[i]);
    for(int i=k;i<n;i++){
        if(pq.top()>arr[i])
            continue;
        pq.pop();
        pq.push(arr[i]);
    }
    return pq.top();
}

// Using PIVOT  O N