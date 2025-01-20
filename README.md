The calculator works as follows :

  1-show a user interface.
  
  2-read user input or clicks.
  
  3-with each click check if the clicked button is acceptable according to conditions, for example "1++" can't be accepted or more like it can't happen since such sequence of clicks won't be allowed.  
  
  4-when user presses enter or '=' clean the expression by adding ')' to the end of the expression.
  
  5-tokenize the expression, like this : {"exp","(","55","+","1","/","36",")"}
  
  6-change the expression from a infix form "a+b" to postfix form "ab+" using the shunting-yard algorithm.
  
  7-turn the expression to a binary tree.
  
  8-evaluate the tree by going through each node recursively and calculating the result.
  
  9-show result on the user interface.
  
This calculator isn't fully complete the issues that it has are :

  -can't process negative value can give negative results just can't process them cause of the rules put to take a readable expression.
	 
  -contains strange ways for dealing with operators that only take one variable like "sin" or "exp".
	 
  -other issues are to be found.
