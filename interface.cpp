

#include<iostream>
#include<math.h>
#include<stdlib.h>
#include "incidence.h"
#include "matrix.h"
 using namespace std;

void menu1(){
 cout<<"Menu :"<<endl;
 cout<<"1. Graph Theory based Analysis"<<endl;
 cout<<"2. Circuit solving"<<endl;
 cout<<"3. Re-enter Graph"<<endl;
 cout<<"4. Exit"<<endl;

 cout<<"Enter option"<<endl;


}
void currents(float *&A,float *&potentials,int *&edgeOrder,float *&J,float *&G,int passive,int x,int y){
    int ctr=0,ctr2=y-passive;
    for(int i=0;i<y;++i){
            float v=0;

        for(int j=1;j<x;++j)
        {
            v+=A[j*y+i]*potentials[j-1];

        }
    cout<<"Voltage across edge "<<i<<" is "<<v;

    if((edgeOrder[ctr]==i)&&(ctr<passive)){
        cout<<"\t Current through edge is "<<v*G[ctr*passive+ctr];
        ctr++;
    }
    else if(edgeOrder[y-ctr2]==i){
        cout<<"\t Current through edge is "<<J[y-passive-ctr2];
        ctr2--;
    }
    cout<<endl;
    }
}
void graphAnalysis(float *&A,int x,int y)
{   bool flag;

    cout<<"Continuity Test "<<endl;

    flag=checkcontinous(A,x,y);
    if(flag==true){
        cout<<"The graph that has been entered is continous "<<endl;
        cout<<"Displaying all trees "<<endl;
        printTree(A,y,x);
    }

    if(flag==false){
        cout<<" The Graph that has been entered is not continous"<<endl;
        return ;

    }
}
void circuitAnalysis(float *&A,int x,int y)
{

    float *Aj,*Ar,*J,*G,*potentials;

    float *Art;
    float *ArG,*Q,*P;
    int passive,active,*edgeOrder;
    device(G,J,Ar,Aj,active,passive,A,x,y,edgeOrder);
    
    normalise(Ar,x-1,y,passive);
    normalise(Aj,x-1,y,active);
    normalise(G,passive,y,passive);
    

    Art=transpose(Ar,x-1,passive);
    mat_multiply(ArG,Ar,G,x-1,passive,passive,passive);

    mat_multiply(P,ArG,Art,x-1,passive,passive,x-1);

    mat_multiply(Q,Aj,J,x-1,active,active,1);

    scalar_multiply(Q,-1,x-1,1);

 
    int reply=solve(P,potentials,Q,x-1);

    cout<<"\n\n*******************************OUTPUT********************************\n\n";
    if(reply==1){
            cout<<"Infinite Solutions "<<endl;
            return;
    }
       if(reply==-1){
            cout<<"No Solutions "<<endl;
            return;
       }
    cout<<"Potential of node 0 is 0"<<endl;
    for(int i=0;i<x-1;++i){
        cout<<"Potential of node "<<i+1<< "is "<<potentials[i]<<endl;


    }

    currents(A,potentials,edgeOrder,J,G,passive,x,y);
    delete ArG;

}

int main(){
    float *inci_mat;
    int rows,cols;
    int option;

    cout<<"Circuit Simulator"<<endl<<endl;
    inputlabel:
    inci_mat=input(rows,cols);

    menulabel:
    menu1();

    cin>>option;
    switch(option){
        case 1: graphAnalysis(inci_mat,rows,cols);
                break;
        case 2: circuitAnalysis(inci_mat,rows,cols);
                break;

        case 3: delete inci_mat;
                goto inputlabel;

                break;
        case 4: exit(0);
                break;
        default : cout<<"Invalid option! Please Re-Enter "<<endl;
                goto menulabel;
                break;
    }

    return 0;

    }





