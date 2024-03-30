#include <stdio.h>
#include <conio.h>
#include <string.h>

#define SIZE 15

int main(){
	
	FILE *fp = NULL;
	fp = fopen("INPUT.TXT","wb");
	
	fprintf(fp,"100\n200\n230\n101");	
	
	rewind(fp);
	
	fp = fopen("INPUT.TXT","rb");
	
	int dizi[4][3]={0};
	int character_Read = fgetc(fp);

	int i = 0,j = 0;
	
	while(character_Read != EOF){
	
		if(character_Read != '\n' ) {  dizi[i][j++] = character_Read - 48;} 
		
		else  { dizi[i][j] = '\0'; i++; j = 0;	} 
		
		character_Read = fgetc(fp);
			
	}
	
	/*for(i = 0 ; i <= 3 ; i++ ){
		
		for( j = 0 ; j <= 2 ; j++ ){
			printf("%d ",dizi[i][j]);
		}
		printf("\n");
	}*/
	
	char metin[SIZE];
	int output[SIZE]; output[0] = 0;
	
	char state [SIZE * 2][2]; 
	 state[0][1] = 0;
	
	
	printf("Giris stringini giriniz: ");
	gets(metin);
	
	int size = strlen(metin);
	
	for( i = 0; i < SIZE; i++ ){
		
	state[i][0] = 'q';	
	}
	
	 j = 0;
	int k = 0;
	int x = 0;
	
	int old_State[4] = { 0,1,2,3 };
	int output_tutucu[SIZE] = {0}; output_tutucu[0] = dizi[0][2];
		
	printf("\nInput String\t  ");
	
	for( i = 0; i < size ; i++ ) printf("%c  ",metin[i]);
	
	printf("\n");
	
	for( i = 0; i < size; i++ ){
		
		if( !i ) 	printf("State\t%c%d\t  ",state[0][0],state[0][1]); 
		
	switch(old_State[x]){
		
	case 0 : { metin[i] == 'a' ? printf("%c%d ",state[i][0],dizi[k++][j]),x++ : ( printf("%c%d ",state[i][0],dizi[k][++j]),j-- ); break; }	
		case 1:	{ metin[i] == 'a' ? printf("%c%d ",state[i][0],dizi[k++][j]),x++ : ( printf("%c%d ",state[i][0],dizi[k--][++j]),j--,x-- ); break; } 
			case 2: { metin[i] == 'a' ? printf("%c%d ",state[i][0],dizi[k][j]) : ( printf("%c%d ",state[i][0],dizi[k++][++j]),j--,x++ ); break;	}
				case 3: { metin[i] == 'a' ? printf("%c%d ",state[i][0],dizi[k][j]),x-=2,k-=2 : ( printf("%c%d ",state[i][0],dizi[k][++j]),j--,x-=3 ); break; }			
	}
		output_tutucu[i] = dizi[x][2];
 }
 
 printf("\nOutput\t0\t  ");
 
  for( i = 0; i < size; i++ ){
  
  	printf("%d  ",output_tutucu[i]);
  	
  }
  
	return 0;
}

