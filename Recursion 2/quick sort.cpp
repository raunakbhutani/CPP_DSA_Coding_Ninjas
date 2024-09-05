/*
Problem statement
Given the 'start' and the 'end'' positions of the array 'input'. Your task is to sort the elements between 'start' and 'end' using quick sort.
  */

/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	int count_small_ele=0;
  
	for(int i=start+1;i<=end;i++){
		if(input[i]<=input[start])
		count_small_ele++;
	}
  
	int temp=input[start+count_small_ele]; // part indx is at its correct pos
	input[start+count_small_ele]=input[start];
	input[start]=temp;
	
	int part_idx=start+count_small_ele;
	int x=input[part_idx];
	
	int i=start;         // to sort one part of arr before part idx or after
	int j=end;
  
	while(i<part_idx && j>part_idx){
		if(input[i]<=x)
		i++;
		
    else if(input[j]>x)
		j--;
      
		else{
		int temp=input[i];
		input[i]=input[j];
		input[j]=temp;
		i++;
		j--;
	}
	}
	return part_idx;
}

void quickSort(int input[], int start, int end) {
	if(start>=end)
	return;
  
  int part_idx=partitionArray(input,start,end);
	
  quickSort(input,start,part_idx-1);
	quickSort(input,part_idx+1,end);
}
