#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
	
    char queue_q[4] = {'q', 'q', 'q', 'q'};
    char queue_no[4] = {'a', 'b', 'c', 'd'};

    for (int i = 0; i < 4; i++) {
    	
        int index = queue_no[i] - 'a';
        
        queue_q[i * 2] = 'q';
        queue_q[i * 2 + 1] = '0' + index;
      
    }
    
    int output[15] = {0};
    char metin[15] = {0};
    
    printf("Giris stringini yaziniz:");
    gets(metin);
    
    int size = strlen(metin);
    int j = 0,k = 0,l = 0;
    
    int state[4] = {0,1,2,3};
     
    int new_state[size][2] = {};
    
    new_state[0][0] = queue_q[0],new_state[0][1] = queue_no[1] - 'b';
   
    for( int i = 0; i < size ; i++,k+=2,l++ ){
    		
		if( k == 6 ) k %= 6; //çift indislerde var ve 0.indeksi 1.ifade kabul edersek 6.indekste yani 7.ifadeden sonra kod bozulmasýn diye ekledik
    		
    	switch( state[j] ){
    						
    		case 0:  metin[i] == 0 ? new_state[l][1] = state[j],j+=2,output[i] = 0           : ( new_state[l][1] = state[j], j+=2,output[i] = 1 );  break; 
    			case 1:  metin[i] == 0 ? (new_state[l][1] = state[j], j++,output[i] = 1)     : ( new_state[l][1] = state[j], j--,output[i] = 1  );  break; 
    				case 2:  metin[i] == 0 ? (new_state[l][1] = state[j], j++,output[i] = 0) : ( new_state[l][1] = state[j], j--,output[i] = 1  );  break; 
    					case 3: metin[i] == 0 ? (new_state[l][1] = state[j], output[i] = 1)  : ( new_state[l][1] = state[j], j-=2,output[i] = 1 );  break;							
    					
	   }
			new_state[l][0] = queue_q[k];
   }

for( int i = 0; i < size ; i++){
	
	printf("\t%c%d %c/%d\n",new_state[i][0],new_state[i][1],metin[i],output[i]);
	printf("\t|\n");
	printf("\tv\n\n");
}

    getch();
    return 0;
}
