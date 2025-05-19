
%{
#undef yywrap
#define yywrap() 1
char arr[8];
int valid=1;//to stop the loops once we either have a valid sequence of points or an invalid one

void validpoints(int letters,int start,char name[]){//letters is the amount of points we need. start is the position of the first point on the recognized string
memset(arr,'\0',sizeof(arr));//clears the array of characters
valid=1;
for (int i =0; i<letters; i++){ arr[i]=yytext[start+i]; }
for(int i =0; i<letters-1 && valid==1; i++){
	for(int j=0; j<letters-1 && valid==1; j++){
		if(i==j+1) continue;
		if(arr[i]==arr[j+1]){
			printf("\033[1;31m%s", yytext);
			printf("<Invalid %s %s you have at least two matching points>\n\033[0m", name,arr); valid=0; }}}
if(valid==1){
printf("\033[1;34m%s", yytext);
printf("<Your %s %s is valid>\n\033[0m", name,arr);
}

}

%}
%option noyywrap
%%
"point "[A-Z]{1}[\t\n ,.] {
printf("\033[1;34m%s", yytext);
printf("<Your point %c is valid>\n\033[0m", yytext[6]);
}
"line "[A-Z]{2}[\t\n ,.$] {
validpoints(2,5,"line");
}
"triangle "[A-Z]{3}[\t\n ,.$] {
validpoints(3,9,"triangle");
}
"rectangle "[A-Z]{4}[\t\n ,.$] {
validpoints(4,10,"rectangle");
}
"pentagon "[A-Z]{5}[\t\n ,.$] {
validpoints(5,9,"pentagon");
}
"hexagon "[A-Z]{6}[\t\n ,.$] {
validpoints(6,8,"hexagon");
}
"heptagon "[A-Z]{7}[\t\n ,.$] {
validpoints(7,9,"heptagon");
}
"octagon "[A-Z]{8}[\t\n ,.$] {
validpoints(8,8,"octagon");
}
("point"|"line"|"triangle"|"rectangle"|"pentagon"|"hexagon"|"heptagon"|"octagon")[ ]*[A-Z]* {printf("\033[1;31m%s <Invalid %s>\n\033[0m", yytext , yytext);}
. {printf("%s", yytext);}

%%

int main(void){
yylex();
return(0);
}
