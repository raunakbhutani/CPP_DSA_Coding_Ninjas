/*
Problem statement
You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.



You must sort the elements between 'l' and 'r'.

void merge(int a[],int si,int ei){
    int i=si;
    int mid=(si+ei)/2;
    int j=mid+1;
    int k=0;
    
  int* temp=new int[ei-si+1];   //temp array in which we will merge sorted ele
  
  while(i<=mid && j<=ei){       //range till where we 've to sort array
        if(a[i]<=a[j]){                    
            temp[k]=a[i];
            i++;
            k++;
        }
  
  else{
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    
  while(i<=mid){          //for left over ele in any of the array
        temp[k]=a[i];
        k++;
        i++;
    }
    
while(j<=ei){
        temp[k]=a[j];
        k++;
        j++;
    }
    
int m=0;        //copy ele from temp arr to org arr
    while(m<k){
        a[si+m]=temp[m];
        m++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l>=r)
    return;
  
    int mid=(l+r)/2;
  
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,r);
}
