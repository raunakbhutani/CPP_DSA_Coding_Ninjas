/*
Problem statement
You have been given a vectors of pairs. Your task is to complete the function given which counts the pairs which have first value greater than their second value and returns the count.

Note:
You don't have to print anything it has been already taken care of. Just complete the function as required and return the count.
*/

int countPairs(vector<pair<int,int>> a){
    int n=a.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i].first>a[i].second){
            count++;
        }
    }
    return count;
}
