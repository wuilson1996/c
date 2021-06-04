#include <stdio.h>
#define N 100
int llenar(int tam,int tam2,int aux, int n, int k,int m);
int Aspiral[N][N];
int main() {
	int tam,n;
	int i,j,k=0,m=0,fin;
	printf("Ingrese el tamaño de el espiral: ");
	scanf("%d",&tam);
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			Aspiral[i][j]=0;
		}
	}

	printf("\n");
	if(tam % 2 == 0){
		fin = tam/2;
		/*n debe ser par*/
		n=tam-6; /*asignamos el valor de n el cual cambia con el valor de la matriz*/
	}else{
		fin = (tam+1)/2;
		/*n debe ser impar*/
		n=(tam)-6;
	}
	/*printf("%d",fin);*/
	for(i=0;i<fin;i++){
		m = llenar(tam-i,tam,i,n,k,m);/*aux2 y aux lo reemplazamos por i*/
		/*printf("");*/
		/*printf("%d\n",m);*/
		k=k+2;
	}
	for(i=0;i<tam;i++){
		for(j = 0; j <tam; j++){
			printf(" %d ",Aspiral[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int llenar(int tam,int tam2,int aux, int n,int k, int m){
	int i,x=1,aux2;
	for(i=aux;i<tam;i++){
		Aspiral[aux][i] = x + m;										/*((tam2-1)*n)+(i+k);*/
		
		Aspiral[i][(tam-1)] = x + m + 5 -(k*1) + n;  					/*((tam2-1)*(n+1))+(i+k-(m));*/ /* m = 2 */
		Aspiral[tam-1][(tam-1)-i+(aux)] = x	+ m	+ 10 -(k*2) + n*2;		/*((tam2-1)*(n+2))+(i+k-(m*2));*/
		
		if(i < (tam-1)){
			Aspiral[(tam2-1)-i][aux] = x + m + 15 -(k*3) + n*3;
			aux2 = 	x + m + 15 -(k*3) + n*3;												/*((tam2-1)*(n+3))+(i+k-(m*3));*/
		}
		x++;
	}
	return aux2;
}
