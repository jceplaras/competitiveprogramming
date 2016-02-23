#include<stdio.h>
int main() {
int M[102][102];

int T, N;
double K;
int i,j;
int top, left;
scanf("%d", &T);
while(T--) {
  scanf("%d", &N);
  K = 2*N - 3;
  for(i=0;i<=N;i++)
    for(j=0;j<=N;j++)
      M[i][j] = 0;
      
  for(i=1;i<=N;i++)
    for(j=1;j<=N;j++) {
      scanf("%d", &M[i][j]);
    }
  
  for(i=2;i<=N;i++) {
    M[1][i] += M[1][i-1];
    M[i][1] += M[i-1][1];
  }
  for(i=2;i<=N;i++)
    for(j=2;j<=N;j++) {
      top = M[i-1][j];
      left = M[i][j-1];
      if(top > left ) { //top > left
        M[i][j] += M[i-1][j];
      }
      else {
        M[i][j] += M[i][j-1];
      }
      
    }/*
    for(i=1;i<=N;i++) {
    for(j=1;j<=N;j++)
    printf("%d/%d ",M[i][j],C[i][j]);
    printf("\n");
    }*/
  
  if(M[N][N] < 0)
    printf("Bad Judges\n");
  else if(M[N][N] == 0)
    printf("0.000000\n");
  else
    printf("%f\n",M[N][N]/K);
}


return 0;
}
