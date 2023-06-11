ExprList:	Expr ExprList	 	{
									$1->right = $2;
									$$ = $1;
									printf("end of ExprList\n");
}
	| Expr						{
									$$ = $1;
									printf("end of Expr\n");		
	}
;


Expr:  ID PLUS_OP Expr			{} 
;


| ID MINUS_OP Expr				{}
;

| ID MULT_OP Expr				{}
;

| ID DIV_OP Expr				{}
;
	
| ID MOD_OP Expr				{
	globalVariable2 = $1;
	globalVariable3 = globalVariable2 % globalVariable1;
}
;

| ID 							{
	globalVariable1 = $1;
}
;

| NUMBER 						{}
;

| NUMBER PLUS_OP Expr			{} 
;

| NUMBER MINUS_OP Expr			{}
;

| NUMBER MULT_OP Expr			{}
;

| NUMBER DIV_OP Expr			{}
;
	
| NUMBER MOD_OP Expr			{}
;