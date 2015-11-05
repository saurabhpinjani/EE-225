#include<iostream>
#include<conio.h>

using namespace std;


float* input(int& x,int&y)
{
    //clearscreen();
    int no_nodes,no_edges;
    cout<<"Enter the number of nodes"<<endl;
    cin>>no_nodes;
    cout<<"Enter the number of edges"<<endl;
    cin>>no_edges;
    //no of edges is number of columns
    //no of rows is number of no of nodes

    float *in_matrix;
    in_matrix=new float[no_edges*no_nodes];

    cout<<"number the nodes from 0 to "<<no_nodes-1<<endl;
    cout<<"number the edges from 0 to "<<no_edges-1<<endl;
    cout<<"Enter the edges.The starting node first then second"<<endl;
    for(int i=0;i<no_edges;++i){

            for(int j=0;j<no_nodes;++j)
            {       //to access [x,y] element [x*no of columns+y]
                    in_matrix[j*no_edges+i]=0;


            }
            cout<<" Enter the "<<i<<"th edge.\n";
            int n1,n2;
            cin>>n1>>n2;
            in_matrix[n1*no_edges+i]=+1;

            in_matrix[n2*no_edges+i]=-1;
            x=no_nodes;
            y=no_edges;

    }
    x=no_nodes;
    y=no_edges;

    return in_matrix;


}


void display(float *mat,int rows,int cols,int tot_cols){
    //clearscreen();
    cout<<"Displaying matrix"<<endl;


    for(int i=0;i<rows;++i){
        cout<<"\t";

        for(int j=0;j<cols;++j){
            cout<<mat[i*tot_cols+j]<<"\t";

        }
        cout<<endl;

    }

}



void continous(float *a,int x,int y,int start,bool *check){

    check[start]=true;
    for(int i=0;i<y;++i){
        if(a[start*y+i]!=0){
            for(int k=0;k<x;++k){
                if(a[k*y +i]!=0)
                {
                    if(check[k]==false){
                        continous(a,x,y,k,check);
                    }

                }
            }
        }
    }



}
bool checkcontinous(float *a,int x,int y){
    bool check[x];
    for(int i=0;i<x;++i){
        check[i]=false;

    }
    continous(a,x,y,0,check);

    for(int i=0;i<x;++i){
        if(check[i]==false){
            return false;
        }
    }

    return true;

}
bool isTree(float *a,int x,int y,int *edges,int no_of_edges){
    bool check[x];
    int no_of_nodes=0;
    for(int i=0;i<x;++i){
        check[i]=false;
    }
    for(int i=0;i<no_of_edges;++i){
        for(int j=0;j<x;++j){
            if(a[j*y+edges[i]]!=0){
                check[j]=true;

            }
        }
    }
    for(int i=0;i<x;++i){
        if(check[i]==true){
            no_of_nodes++;
        }
    }
   // cout<<no_of_nodes<<endl;
    if(no_of_nodes!=x){
        return false;
    }
    if(no_of_nodes-1!=no_of_edges){
        return false;
    }
    float *b;
    b=new float[no_of_edges*no_of_nodes];

    for(int j=0;j<no_of_edges;++j){
        for(int i=0;i<x;++i)
        {
            b[i*no_of_edges+j]=a[i*y+edges[j]];


        }

    }
    cout<<endl;
    //display(b,x,no_of_edges);


    return checkcontinous(b,x,no_of_edges);




}

void combinationGen(float *&mat,float arr[], int data[], int start, int end1, int index, int r)
{
    // Current combination is ready to be printed, print it
    if ((index == r))
    {
        if((isTree(mat,r+1,end1+1,data,r)==true)){


            for (int j=0; j<r; j++){
                cout<<data[j]<<"  ";
                }

            cout<<"\n";
            }



        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end1 && end1-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationGen(mat,arr, data, i+1, end1, index+1, r);
    }
}



void printTree(float *&mat,int no_of_edges, int no_of_nodes)
{   int r=no_of_nodes-1;
    float arr[no_of_edges];
    for(int i=0;i<no_of_edges;++i){
        arr[i]=i;
    }
    // A temporary array to store all combination one by one
    int data[r];

    // Print all combination using temprary array 'data[]'
    combinationGen( mat,arr, data, 0, no_of_edges-1, 0, r);

}



/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
   void copycol(float *&Ar,float *&A,int col1,int col2,int rows,int col)
   {
       for(int i=1;i<rows;++i){
        Ar[(i-1)*col+col1]=A[i*col+col2];
       }
   }
     void zero(int *&mat,int x,int y){
    for(int i=0;i<x;++i){
        for(int j=0;j<y;++j){
            mat[i*y+j]=0;
        }
    }
    }


    void zero(float *&mat,int x,int y){
    for(int i=0;i<x;++i){
        for(int j=0;j<y;++j){
            mat[i*y+j]=0;
        }
    }
    }
   void device(float *&dev,float *&J,float*&Ar,float*&Aj,int &active,int &passive,float*&A,int x,int y,int *&edgeOrder)
   {
         passive=0;
         active=0;

        edgeOrder=new int[y];
        Ar= new float [(x-1)*y];
        Aj= new float [(x-1)*y];
        dev=new float[x*y];
        J= new float[y*1];
        zero(dev,x,y);
        zero(edgeOrder,1,y);
        zero(Ar,x,y);
        zero(Aj,x,y);
        zero(J,1,y);
        cout<<"Enter type then value"<<endl;
        cout<<" Types can be : G (conductance) , R (resistance) ,J (current source)"<<endl;

        for(int i=0;i<y;++i){
            char type;
            float val;
            cout<<"Enter the characteristics for edge : "<<i<<endl;
            cin>>type>>val;
            type=tolower(type);

            switch(type){
                case 'g' :
                            dev[passive*y+passive]=val;
                            copycol(Ar,A,passive,i,x,y);
                            edgeOrder[passive]=i;

                            passive++;
                            break;
                case 'r':
                            dev[passive*y+passive]=1/val;
                            copycol(Ar,A,passive,i,x,y);

                            edgeOrder[passive]=i;
                            passive++;
                            break;
                case 'j' :
                            copycol(Aj,A,active,i,x,y);
                            J[active]=val;
                            for(int j=active;j>0;--j){
                                edgeOrder[y-1-j]=edgeOrder[y-j];
                            }
                            edgeOrder[y-1]=i;
                            active++;
                            break;
                default :  cout<<"Enter correct type! "<<endl;
                            i--;
                            continue;

                }

        }



   }


