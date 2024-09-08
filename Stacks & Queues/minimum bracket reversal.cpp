Problem statement
For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.

If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.
  */


  #include<stack>
#include<algorithm>
int countBracketReversals(string input) {

	int len=input.size();  //length of string
	
	if(len%2!=0)
	return -1;

	stack <char>s;

	for(int i=0;i<len;i++){
		if(input[i]=='{')
		s.push(input[i]);

         else { // if input[i]=='}'
            if (!s.empty() && s.top() == '{')
				s.pop();
				
				else
				s.push(input[i]);
                }
    }
	// stack is now containing unbalanced brackets
	 int count = 0;
        char c1, c2;
        while (!(s.empty())){
            c1 = s.top();
            s.pop();
           
            c2 = s.top();
            if (c1 == c2)
                count++;

            else
                count += 2; // }{ then we have to revrse both {}
            
            s.pop();
        }
        return count;
}
