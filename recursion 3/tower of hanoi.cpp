/*
Problem statement
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move all disks from source rod to destination rod using third rod (say auxiliary). The rules are :

1) Only one disk can be moved at a time.
2) A disk can be moved only if it is on the top of a rod.
3) No disk can be placed on the top of a smaller disk.
Print the steps required to move n disks from source rod to destination rod.

Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.
  */

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Write your code here

    if (n == 0) {  // base case
    //   cout << source << " " << destination<<endl;  // directly move the disk from source to dest
      return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);

    cout<<source<<" "<<destination<<endl;
    
    towerOfHanoi(n - 1, auxiliary, source, destination);

}
