#ifndef matrix.h
#define matrix.h

    void add(float *&sum,float *&mat1,float *&mat2,int x,int y);
    void scalar_multiply(float *&A,float fac,int x,int y);
    void mat_multiply(float *&pro,float *&mat1,float *&mat2,int x1,int y1,int x2,int y2);
    float * transpose(float *&mat,int  x,int y);
    float* incedence(int n);
    float determinant(float *&a,int n);
    int   solve(float *&A,float *&B,float *&C,int n);
    void normalise(float *&A,int x,int n,int m);
#endif // matrix
