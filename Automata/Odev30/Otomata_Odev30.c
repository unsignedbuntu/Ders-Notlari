#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 22

#define ADD		   operand[0]
#define SUBSTRACT  operand[1]
#define MULTIPLY   operand[2]
#define DIVIDE     operand[3]
#define SWAP(x, y) (*x == *y ? *x = *y : (*x ^= *y ^= *x ^= *y))

//*+* 3+3 456
char metin[SIZE] = { "* + * + 1 2 + 3 4 5 6" };
int l = 0 ,  dondur_sayar = 0;
	int* deger_tutucu = (int* ) malloc( sizeof(int) );


 int* stack( char gonder ){
 	
 	int count , sayac = 0 , x , z = 0 ;

	switch ( gonder ){
		
 		case '+': { deger_tutucu[dondur_sayar] =  (metin[ l + 2 ] - '0' + metin[ l + 4 ] - '0') ; break; }
 			case '-' : { deger_tutucu[dondur_sayar] =  (metin[ l + 2 ] - '0' + metin[ l + 4 ] - '0') ; break; }
 				case '*': { deger_tutucu[dondur_sayar] =  (metin[ l + 2 ] - '0' + metin[ l + 4 ] - '0') ; break; }
 					case '/': { deger_tutucu[dondur_sayar] = (metin[ l + 2 ] - '0' + metin[ l + 4 ] - '0'); break; }
	 }
	 
	 printf("%d\t%c\t%c\n",deger_tutucu[dondur_sayar],metin[ l + 2 ],metin[ l + 4 ] );
	
	
	for ( ; metin[l] ; l ++ )
	{
		for ( x = l + 2; z < 3 ; x+=2 , z++ )
		{	
			SWAP( &metin[ l ], &metin[ x + 2 ] );
		}
		
    }
 
		metin[ x  ] = '\0';
	 deger_tutucu = (int* ) realloc(deger_tutucu,sizeof(int) * 2 );
	 
 	return deger_tutucu;
 }	

int main(){
	
	// {"* + * + 1 2 + 3 4 5 6"}
	char operand[4] = {'+','-','*','/'};
	
	printf("Metin girdisini yaziniz\n");
	scanf("%s",metin);
 	
	int i = 0, j = 0, flag = 0, z,l_tutucu;
	char gonder[1];
	
	
   for(; i < SIZE ; i++){
	
	if( metin[i] == ' ' )	{
	continue; }
		
		if( metin[i] > 41 && metin[i] < 48 ){
			
			l = i;
			
			for(; l < SIZE ; l++ ){
			
				if(  metin[l] > 41 && metin[l] < 48  ) { l_tutucu = l; gonder[0] = metin[l]; }
			}
			
			 l = l_tutucu;
				deger_tutucu[dondur_sayar] = *stack( gonder[0] ) ;
				 printf("Sonuc=%d\n",deger_tutucu[dondur_sayar]);
				 dondur_sayar++;
			
		}
		 l = 0;
   }

free(deger_tutucu);
getch();
return 0;	
}


