#include<array>
#include<iostream>
#include<vector> 
using namespace std; 

void swap(vector<int> &pq, int a, int b)
{
    int t = pq[b];
    pq[b] = pq[a];
    pq[a] = t;
}

void max_heapify(vector<int> &pq, int idx){
    
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    int length = pq.size();
    int idx_largest;
    
    if(left < length and pq[left] > pq[idx]){
        idx_largest = left;
    }
    else{
        idx_largest = idx;
    }
    
    if(right < length and pq[right] > pq[idx_largest]){
        idx_largest = right;
    }
    
    if(idx_largest != idx){
        swap(pq[idx], pq[idx_largest]);
        max_heapify(pq,idx_largest);
    }
    
}

void insert_pq (vector<int> &pq, int val)
{
    int length = pq.size();
    //First add the Element at the last
    pq.push_back(val);

    int i = length;
    //Using a vector/array for representing the HEAP
    //Let i be a root node, 2*i and 2*i+1 will store the left and right childs
    //Go in a bottom to top fashion, swapping the values if MAX HEAP structure is 
    //violated
    while( i >= 0 and pq[i/2] < pq[i] ){
    	swap(pq,i,i/2);
    	i = i/2;
    }
}   

int get_top(vector<int> pq){
    return pq[0];
}

int pop_front(vector<int> &pq){
    //get the first Element 
    int top = pq[0];
    int length = pq.size();
    //replacce the first Element with the last Element in the queue
    pq[0] = pq[length];
    pq.pop_back();
    
    //Call the heapify function, since the MAX heap structure is disturbed
    max_heapify(pq,0);
    
    return top;
}   

void build_pq(vector<int> &pq){
    int start = pq.size()/2 - 1;
    //build the heap in bottom to top order
    for (int i=start;i >=0;i--){
        max_heapify(pq, i);
    }
}

int main() 
{   

	vector<int> pq{ 60, 20, 30, 33, 12, 19, 70 };
	build_pq(pq);
	cout << pq[0]<< pq[1]<< pq[2]<< pq[3]<< pq[4]<<pq[5]<<pq[6]<< endl;
	
	//test
	insert_pq(pq, 55);
    insert_pq(pq, 11);
    insert_pq(pq, 88);
    insert_pq(pq, 60);
    insert_pq(pq, 56);
    cout << pq[0]<< pq[1]<< pq[2]<< pq[3]<< pq[4]<<pq[5]<<pq[6]<<pq[7] << endl;
    
    //return the top priority Element
    int top = get_top(pq);
    cout << top << endl;
        
    top = pop_front(pq);
    cout << top << endl;
    top = pop_front(pq);
    cout << top << endl;
    top = pop_front(pq);
    cout << top << endl;
    top = pop_front(pq);
    cout << top << endl;
} 