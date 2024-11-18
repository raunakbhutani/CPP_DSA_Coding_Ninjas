/*
Problem statement
Given an array A and an integer K, print all subsets of A which sum to K.

Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
*/

void printSubsetSumToKHelper(int input[], int size, int k, int output[], int outputSize){

    if(size == 0){
        if(k == 0){
          for (int i = 0; i < outputSize; i++) {
            // print the subset which have k == 0 when size of input is 0
            cout << output[i] << " ";
          }
          cout << endl;
        }
        return;
    }

    // exclude the current elem & recurse on rem elements
    printSubsetSumToKHelper(input + 1, size - 1, k, output, outputSize);

    // include the current elem in subset & recurse
    output[outputSize] = input[0];
    printSubsetSumToKHelper(input + 1, size - 1, k - input[0], output, outputSize + 1);
}

void printSubsetSumToK(int input[], int size, int k) {
    

    int output[1000];  // array to store the current subset
    printSubsetSumToKHelper(input, size, k, output, 0);
}
