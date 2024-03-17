#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;
//Declaracion de strucs
struct zonas
{
    int canttot;
    int cantmoto;
    int cantauto;
    int cantcamioneta;
    int cantcamion;

};

struct repartidores
{
    int dni;
    char nombre[35];
    char patente[6];
    int zona;
    char transp;

};
//Declaracion funciones

int inicializar(zonas zonas[],int k);
int ingreso(zonas VecZona[],repartidores VecRep[],int &cont);
int ordenar(repartidores Vec[],int cont);
void CrearArchivos(repartidores vecrepartidores[],int cont);
void CanRepXtransp(zonas v[],int k);
void disponibilidad(zonas v[],int k);
void MayorRepartidores(zonas v[],int k);
int validarNum(char num[]);
int validarPatente(char Pat[]);
int validarNom(char Nom[]);


//Main
int main()
{
int cont=0;
zonas veczonas[14];
repartidores vecrepartidores[1120];
inicializar(veczonas,14);
ingreso(veczonas,vecrepartidores,cont);
ordenar(vecrepartidores,cont);
CrearArchivos(vecrepartidores,cont);
CanRepXtransp(veczonas,14);
disponibilidad(veczonas,14);
MayorRepartidores(veczonas,14);

return 0;
}

int inicializar(zonas zonas[],int k)
{
    for(int i=0;i<k;i++)
    {
        zonas[i].canttot = 0;
        zonas[i].cantmoto = 0;
        zonas[i].cantauto = 0;
        zonas[i].cantcamioneta = 0;
        zonas[i].cantcamion = 0;
    }
return 0;
}

int ingreso(zonas VecZona[],repartidores VecRep[],int &cont)
{
int auxInt,k,z,p,n;
char auxChar[20],auxDni[8],auxZona[2],auxPat[6],auxNom[35],auxAp[20];
string auxStr;
int a=0;
cout<<"INGRESO DE REPARTIDORES"<<endl;
cout<<"Ingrese dni del repartidor(0 fin del proceso): ";
    cin>>auxDni;
    while(a==0)
            {
                k=validarNum(auxDni);
                if(k==0)
                {
                    auxInt=atoi(auxDni);
                    if(auxInt>=1000000 && auxInt<=100000000)
                    {
                    VecRep[cont].dni=auxInt;
                    a++;
                    }
                     else
                     {
                     if(auxInt==0)
                        {
                        VecRep[cont].dni=auxInt;
                        a++;
                        }
                     else
                        {
                        cout<<"Error:Ingrese otra vez: ";
                        cin>>auxDni;
                        }
                    }
                }
                else
                {
                 cout<<"Error:Ingrese otra vez: ";
                        cin>>auxDni;
                }

            }
    a=0;
while(VecRep[cont].dni!=0)
{
        //Ingreso Nombre
        cout<<"Ingrese el nombre del repartidor: ";
            fflush(stdin);
            cin.getline(VecRep[cont].nombre,35);
           while(a==0)
           {
            n=validarNom(VecRep[cont].nombre);
           if(n==0)
           {
            a++;
           }
           else
           {
           cout<<"Error:Ingrese otra vez: ";
            fflush(stdin);
            cin.getline(VecRep[cont].nombre,35);
           }
           }
           a=0;

        //Ingreso Zonas
        cout<<"Ingrese la zona del repartidor(1-14): ";
            cin>>auxZona;
            while(a==0)
            {
                z=validarNum(auxZona);
                if(z==0)
                {
                    auxInt=atoi(auxZona);
                    if(auxInt>=1 && auxInt<=14)
                    {
                    a++;
                    VecRep[cont].zona=auxInt;
                    }
                    else
                    {
                    cout<<"Error:Ingrese otra vez: ";
                        fflush(stdin);
                        cin>>auxZona;
                    }
                }
                else
                {
                cout<<"Error:Ingrese otra vez: ";
                        cin>>auxZona;
                }
            }
            a=0;
            //Ingreso Patentes
        cout<<"Ingrese la patente del repartidor(sin espacios): ";
            cin>>VecRep[cont].patente;
            validarPatente(VecRep[cont].patente);
            while(a==0)
            {
                p=validarPatente(VecRep[cont].patente);
                if(p==0)
                {
                    a++;
                }
                else
                {
                 cout<<"Error:Ingrese otra vez: ";
                    fflush(stdin);
                    cin>>VecRep[cont].patente;
                }
            }
            a=0;
            //ingreso Transporte
        cout<<"Ingrese el modo de transporte del repartidor(auto=a/camion=t/moto=m/camioneta=c): ";
            cin>>auxChar;
        while(a==0)
        {
        if(strlen(auxChar)==1)
        {
            if(auxChar[0]=='a'|| auxChar[0]=='t'||auxChar[0]=='m'||auxChar[0]=='c')
            {
                VecRep[cont].transp=auxChar[0];
                switch (VecRep[cont].transp)
                    {
                        case'a' :
                        if(VecZona[VecRep[cont].zona-1].cantauto<20)
                        {
                            VecZona[VecRep[cont].zona-1].cantauto+=1;
                            VecZona[VecRep[cont].zona-1].canttot+=1;
                            cont++;
                            a++;
                            break;
                        }
                        case 'm':
                        if(VecZona[VecRep[cont].zona-1].cantmoto<20)
                        {
                            VecZona[VecRep[cont].zona-1].cantmoto+=1;
                            VecZona[VecRep[cont].zona-1].canttot+=1;
                            cont++;
                            a++;
                            break;
                        }
                        case 't':
                        if(VecZona[VecRep[cont].zona-1].cantcamion<20)
                        {
                            VecZona[VecRep[cont].zona-1].cantcamion+=1;
                            VecZona[VecRep[cont].zona-1].canttot+=1;
                            cont++;
                            a++;
                            break;
                        }
                        case 'c':
                        if(VecZona[VecRep[cont].zona-1].cantcamioneta<20)
                        {
                            VecZona[VecRep[cont].zona-1].cantcamioneta+=1;
                            VecZona[VecRep[cont].zona-1].canttot+=1;
                            cont++;
                            a++;
                            break;
                        }
                        default:
                        {
                         cout<<"ERROR: Modo de transporte invalido o Capacidad llena. Vuelva a intentar"<<endl;
                            break;
                        }
                    }
            }
            else
            {
            cout<<"Error:Ingrese de nuevo: ";
                    fflush(stdin);
                    cin>>auxChar;
            }
        }
        else
            {
            cout<<"Error:Ingrese de nuevo: ";
                    fflush(stdin);
                    cin>>auxChar;
            }
        }
        a=0;

        cout<<endl;

        //Ingreso DNI
        cout<<"Ingrese dni del repartidor(0 fin del proceso): ";
            cin>>auxDni;
            while(a==0)
            {
                k=validarNum(auxDni);
                if(k==0)
                {
                    auxInt=atoi(auxDni);
                    if(auxInt>=1000000 && auxInt<=100000000)
                    {
                    VecRep[cont].dni=auxInt;
                    a++;
                    }
                    else
                        if(auxInt==0)
                        {
                        VecRep[cont].dni=auxInt;
                        a++;
                        }
                        else
                        {
                        cout<<"Error:Ingrese otra vez: ";
                        cin>>auxDni;
                        }
                }
                else
                {
                 cout<<"Error:Ingrese otra vez: ";
                        cin>>auxDni;
                }

            }
            a=0;
}
return 0;
}

int ordenar(repartidores Vec[],int cont)
{
    int i,j,AuxDni,AuxZona;
    char AuxTrans;
    char AuxPat[6],AuxNom[35];
    for(i=1;i<cont;i++)
    {
        for(j=0;j<cont-1;j++)
        {
            if(Vec[j].dni>Vec[j+1].dni)
            {
                AuxDni=Vec[j].dni;
                AuxZona=Vec[j].zona;
                AuxTrans=Vec[j].transp;
                strcpy(AuxNom,Vec[j].nombre);
               // AuxNom=Vec[j].nombre;
                //AuxPat=Vec[j].patente;
                strcpy(AuxPat,Vec[j].patente);
                Vec[j].dni=Vec[j+1].dni;
                Vec[j].zona=Vec[j+1].zona;
                Vec[j].transp=Vec[j+1].transp;
                //Vec[j].nombre=Vec[j+1].nombre;
                strcpy(Vec[j].nombre,Vec[j+1].nombre);
                strcpy(Vec[j].patente,Vec[j+1].patente);
               // Vec[j].patente=Vec[j+1].patente;
                Vec[j+1].dni=AuxDni;
                Vec[j+1].zona=AuxZona;
                Vec[j+1].transp=AuxTrans;
               // Vec[j+1].nombre=AuxNom;
                //Vec[j+1].patente=AuxPat;
                strcpy(Vec[j+1].nombre,AuxNom);
                strcpy(Vec[j+1].patente,AuxPat);
            }
        }
    }
    return 0;
}

int validarNum(char num[])
{
    int i=0,sw=0,j;
    j=strlen(num);
    while(i<j && sw==0)
    {
        if(isdigit(num[i])!=0)
        {
            i++;
        }
        else
        {
            sw=1;
        }
    }
    return sw;
}

int validarNom(char Nom[])
{
    int i=0,sw=0;

    while(i<40 && sw==0)
    {
        if(isdigit(Nom[i])!=0)
        {
            sw=1;
        }
        else
        {
            i++;
        }
    }
    return sw;
}

int validarPatente(char Pat[])
{
    int i=0,sw=0,j;
    j=strlen(Pat);
    if(j==6)
    {
    while(i<j && sw==0)
    {
        if(isalpha(Pat[i]) && i<3)
        {
         i++;
        }
        else
           {
            if(isdigit(Pat[i])!=0 && i>=3 && i<6)
                {
                i++;
                }
            else
                {
                sw=1;
                }
            }
        }
    }
    else
        {
        sw=1;
        }
    return sw;
}

void CrearArchivos(repartidores Vec[],int cont)
{
    FILE *ArcMotos=fopen("RepMoto.txt","wb");
    FILE *ArcAutos=fopen("RepAuto.txt","wb");
    FILE *ArcCamion=fopen("RepCamion.txt","wb");
    FILE *ArcCamioneta=fopen("RepCamioneta.txt","wb");


    for(int i=0;i<cont;i++)
    {
    if(Vec[i].transp=='a')
        {
        fwrite(&Vec[i],sizeof(repartidores),1,ArcAutos);
        }
    else if(Vec[i].transp=='m')
        {
        fwrite(&Vec[i],sizeof(repartidores),1,ArcMotos);
        }
    else if(Vec[i].transp=='t')
        {
        fwrite(&Vec[i],sizeof(repartidores),1,ArcCamion);
        }
    else if(Vec[i].transp=='c')
        {
        fwrite(&Vec[i],sizeof(repartidores),1,ArcCamioneta);
        }
    }
    fclose(ArcMotos);
    fclose(ArcAutos);
    fclose(ArcCamion);
    fclose(ArcCamioneta);
}

void CanRepXtransp(zonas v[],int k)
{
    for(int i=0;i<k;i++)
    {
        cout<<"ZONA "<<i+1<<endl;
        cout<<"   -Cantidad de repartidores en auto :"<<v[i].cantauto<<endl;
        cout<<"   -Cantidad de repartidores en moto :"<<v[i].cantmoto<<endl;
        cout<<"   -Cantidad de repartidores en camion :"<<v[i].cantcamion<<endl;
        cout<<"   -Cantidad de repartidores en camioneta :"<<v[i].cantcamioneta<<endl;
    }
}

void disponibilidad(zonas v[],int k)
 {
   int CantTotalAuto=0,CantTotalMoto=0,CantTotalCamion=0,CantTotalCamioneta=0;
   for(int i=0;i<k;i++)
    {
       CantTotalAuto+=v[i].cantauto;
       CantTotalMoto+=v[i].cantmoto;
       CantTotalCamion+=v[i].cantcamion;
       CantTotalCamioneta+=v[i].cantcamioneta;
    }
    cout<<"No habra disponibilidad de: "<<endl;
    if(CantTotalAuto==0)
        cout<<"-Autos"<<endl;
    if(CantTotalMoto==0)
        cout<<"-Motos"<<endl;
    if(CantTotalCamion==0)
        cout<<"-camiones"<<endl;
    if(CantTotalCamioneta==0)
        cout<<"-Camionetas"<<endl;
 }

 void MayorRepartidores(zonas v[],int k)
 {
     int mayor=0;
     for(int i=0;i<k;i++)
     {

         if(mayor<v[i].canttot)
         {
             mayor=v[i].canttot;
         }
     }
     cout<<endl;
     cout<<"La/s Zona/s con mas repartidores son: ";
     for(int i=0;i<k;i++)
     {
         if(mayor==v[i].canttot)
         {
             cout<<" "<<i+1<<" ";
         }
     }
 }



