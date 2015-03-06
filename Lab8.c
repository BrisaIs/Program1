#include <stdio.h>
#include <string.h>

typedef struct tm{
	char Nomb[40];
	int id,U[12];
}TM;
int main(){
	TM t[50] ;
	int u,nd,a,b,opc,op,c=0,SF[50],busq,band;
	char M[12][12];

	for(a=0;a<50;a++)
		SF[a]=0;

		for(a=0;a<50;a++)
			for(b=0;b<12;b++)
				t[a].U[b]=0;

	strcpy(M[0],"Enero");
	strcpy(M[1],"Febrero");
	strcpy(M[2],"Marzo");
	strcpy(M[3],"Abril");
	strcpy(M[4],"Mayo");
	strcpy(M[5],"Junio");
	strcpy(M[6],"Julio");
	strcpy(M[7],"Agosto");
	strcpy(M[8],"Septiembre");
	strcpy(M[9],"Octubre");
	strcpy(M[10],"Noviembre");
	strcpy(M[11],"Diciembre");
	do{
			printf("1] Ingresar trabajador a base de datos\n");
			printf("2] Imprimir reporte\n");
			printf("3] Salir\n");
			scanf("%d",&opc);
			switch(opc){
				case 1:
						if(c<50){
							printf("Ingresar ID del trabajador %d\n",c+1);
							scanf("%d",&t[c].id);
							getchar();
							printf("Ingresa el nombre del trabajador %d\n",c+1);
							gets(t[c].Nomb);
							for(a=0;a<12;a++){
								printf("Ingrese el numero de dias que trabajo en el mes de %s\n",M[a]);
								scanf("%d",&nd);
								for(b=0;b<nd;b++){
									printf("Ingrese el numero de mesas producidas el dia %d\n",b+1);
									scanf("%d",&u);
									t[c].U[a]+=u;
									SF[c]+=u;
								}
							}
							c++;
						}
						else
							printf("Base de datos llena\n");
					break;
				case 2:
					do{
						printf("1] Imprimir reporte indivivual\n");
						printf("2] Imprimir reporte general\n");
						printf("3] Regresar al menu principal\n");
						scanf("%d",&op);
						switch(op){
							case 1:
								printf("Ingrese el ID del trabajador a cosultar\n");
								scanf("%d",&busq);
								for(a=0;a<c;a++){
									if((t[a].id)==busq){
										band=a;
										printf("Id del trabador: %d\n",t[a].id);
										printf("Nombre del trabajador: ");
										puts(t[a].Nomb);
										printf("\n");
										printf("Unidades elaboradas por mes:\n");
										for(b=0;b<12;b++){
											puts(M[b]);
											printf(": %d\n",t[a].U[b]);
										}
										printf("Unidades elaboradas anualmentes: %d\n",SF[band]);
									}
								}
								break;
							case 2:
									for(a=0;a<c;a++){
										printf("Id del trabador: %d\n",t[a].id);
										printf("Nombre del trabajador: ");
										puts(t[a].Nomb);
										printf("\n");
										printf("Unidades elaboradas por mes:\n");
										for(b=0;b<12;b++){
											puts(M[b]);
											printf(": %d\n",t[a].U[b]);
										}
										printf("Suedo anual: %d\n",SF[a]);
									}
								break;
							case 3:
								break;
							default:
								printf("Opcion no valida, intente de nuevo\n");
						}
					}while(opc!=3);
					break;
				case 3:
					break;
				default:
					printf("Opcion no valida, intente de nuevo\n");
			}

	}while(opc!=3);
	return 0;
}
