/*
Problem statement
Given a string, compute recursively a new string where all 'x' chars have been removed.
  */

// Change in the given string itself. So no need to return or print anything

void removeX(char input[]) {
   if(input[0]=='\0'){
    return;
   }
  
    if(input[0]=='x'){
        int i;
        for(i=1;input[i]!='\0';i++){
            input[i-1]=input[i];
        }
      
        input[i-1]='\0';
        removeX(input);
    }
      
    else
    removeX(input+1);
}
