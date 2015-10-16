#ifndef incidence.h
#define incidence.h

    float* input(int& x,int&y);
    void display(float *mat,int rows,int cols,int tot_cols);
    void continous(float *a,int x,int y,int start,bool *check);
    bool checkcontinous(float *a,int x,int y);
    bool isTree(float *a,int x,int y,int *edges,int no_of_edges);
    void combinationGen(float *&mat,float arr[], int data[], int start, int end, int index, int r);
    void printTree(float *&mat,int no_of_edges, int no_of_nodes);
    void copycol(float *&Ar,float *&A,int col1,int col2,int rows,int col);
     void zero(int *&mat,int x,int y);
    void zero(float *&mat,int x,int y);
    void device(float *&dev,float *&J,float*&Ar,float*&Aj,int &active,int &passive,float*&A,int x,int y,int *&edgeOrder);



#endif
