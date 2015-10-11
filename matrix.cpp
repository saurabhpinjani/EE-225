//file to define matrix operations like multiplication addition and inverse
#include<iostream>
#include<math.h>

using namespace std;
void add(float *&sum,float *&mat1,float *&mat2,int x,int y)
{
    sum=new float [x*y];
    for(int i=0;i<x;++i){
        for(int j=0;j<y;++j){
            sum[i*y+j]=mat1[i*y+j]+mat1[i*y+j];
        }
    }
}
void scalar_multiply(float *&A,float fac,int x,int y){

    for(int i=0;i<x;++i){
        for(int j=0;j<y;++j){
            A[i*y+j]=fac*A[i*y+j];
        }
    }

}
void mat_multiply(float *&pro,float *&mat1,float *&mat2,int x1,int y1,int x2,int y2)
{
    if(y1!=x2){
        cout<<"incompatible matrices";
        return;
    }

    pro=new float [x1*y2];
    for(int i=0;i<x1;++i){
        for(int j=0;j<y2;++j){
                pro[i*y2+j]=0;
            for(int k=0;k<y1;++k){
                pro[i*y2+j]+=mat1[i*y1+k]*mat2[k*y2+j];
            }
        }
    }
}

float * transpose(float *&mat,int  x,int y)
{
    float *temp=new float [y*x];
    for(int i=0;i<x;++i){
        for(int j=0;j<y;++j){
            temp[j*x+i]=mat[i*y+j];
        }
    }

    return temp;



}

float* incedence(int n){
    float *I=new float(n*n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            I[i*n+j]=(i==j?1:0);
        }
    }
    return I;
}


float determinant(float *&a,int n){

    if(n==1){
        return a[0];

    }

    float sum=0;
    float *submat=new float[(n-1)*(n-1)];
    for(int i=0;i<n;++i){

        for(int j=1;j<n;++j){
            int ctr=0;
            for(int k=0;k<n;++k){
                if(i==k){
                    continue;
                }
                submat[(j-1)*(n-1)+ctr]=a[j*n+k];
                ctr++;

            }

        }
       // cout<<n<<"\t"<<i<<determinant(submat,n-1)<<endl;
        sum=sum +a[i]*(pow(-1,i)*determinant(submat,n-1));
    }
    delete submat;
    return sum;



}

int   solve(float *&A,float *&B,float *&C,int n)
{
        float *temp =new float[n*n];
        float detA=determinant(A,n);

        float *detB=new float[n];
        for(int k=0;k<n;++k){
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j){
                if(j!=k){
                temp[i*n+j]=A[i*n+j];
                }
                else{
                    temp[i*n+j]=C[i];
                }
            }
        }
        detB[k]=determinant(temp,n);
        }
        bool flag=false;
        if(detA==0){
            for(int i=0;i<n;++i){
                if(detB[i]!=0)
                {flag=true;
                 break;
                }
            }
            if(flag==false){
                return 1;//infinite solutions
            }

            if(flag==true)//no solutions
            {
                return -1;
            }
        }

        else{
            for(int i=0;i<n;++i){
                B[i]=detB[i]/detA;
            }
            return 0;
        }



    return 0;


}


/*int main(){
    float *a;
    a=new float[9];
    a[0]=1;
    a[1]=2;
    a[2]=3;
    a[3]=6;
    a[4]=1;
    a[5]=2;
    a[6]=4;
    a[7]=7;
    a[8]=1;
    cout<<determinant(a,3);
    return 0;
}*/



