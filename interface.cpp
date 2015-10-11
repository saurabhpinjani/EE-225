

#include<iostream>
#include<math.h>
#include<process.h>
 using namespace std;

void menu1(){
 cout<<"Menu :"<<endl;
 cout<<"1. Graph Theory based Analysis"<<endl;
 cout<<"2. Circuit solving"<<endl;
 cout<<"3. Re-enter Graph"<<endl;
 cout<<"4. Exit";

 cout<<"Enter option"<<endl;


}
void graphAnalysis(float *&A,int x,int y)
{   bool flag;

    cout<<"Continuity Test "<<endl;
    flag=checkcontinous(A,x,y);
    if(flag==true){
        cout<<"The graph that has been entered is continous "<<endl;
        cout<<"Displaying all trees "<<endl;
        printTree(A,x,y);
    }

    if(flag==false){
        cout<<" The Graph that has been entered is not continous"<<endl;
        return ;

    }
}
void circuitAnalysis(float *&A,int x,int y)
{

    float *Aj,Ar,J,G,Ir;
    int passive,active,*edgeOrder;
    device(G,J,Ar,Aj,active,passive,A,x,y,edgeOrder);
    float *Art;
    float *ArG,*Q,P;
    Art=transpose(Ar,x-1,passive);
    mat_multiply(ArG,Ar,G,x-1,passive,passive,passive);
    mat_multiply(P,ArG,Art,x-1,passive,passive,x-1);
    delete ArG;

    mat_multiply(Q,Aj,J,x-1,active,active,1);
    scalar_multiply(Q,-1,x-1,1);
    solve(P,Ir,Q,x-1);
    //solving Px=Q
    //p=ArGArT
    //Q=-AjJ
}

void main()
{   float *inci_mat;
    int rows,cols;
    int option;

    cout<<"Circuit Simulator"<<endl<<endl;
    inputlabel:
    inci_mat=input(&rows,&cols);

    menulabel:
    menu1();

    cin>>option;
    switch(option){
        case 1: graphAnalysis(inci_mat,rows,cols);
                break;
        case 2: circuitAnalysis(inci_mat,int rows,int cols);
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



    }





