#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

uint32_t get_num(char* temp){
	FILE* pFile = fopen(temp,"r");
        if(pFile==NULL){
                printf("no file!");
                return 0;
        }
        uint8_t buffer[4]={0,};
        fread(buffer,sizeof(uint8_t),4,pFile);
        fclose(pFile);
 	uint32_t* p= reinterpret_cast<uint32_t*>(buffer);
        return  ntohl(*p);	
}

int main(int argc,char *argv[]){
	if(argc!=3){
		printf("input error!");
		return 0;
	}
	uint32_t n1 = get_num(argv[1]);
	uint32_t n2 = get_num(argv[2]);
	printf("%d(0x%x)",n1,n1);
	printf(" + ");
	printf("%d(0x%x)",n2,n2);
	printf(" = ");
	printf("%d(0x%x)",n1+n2,n1+n2);

	return 0;
}
