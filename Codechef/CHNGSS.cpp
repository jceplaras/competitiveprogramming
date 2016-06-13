#include<stdio.h>
#define FORN(i,N) for (i = 0; i < N; i++)



int mat[501][25001];

int main() {

  int N,M,C;
  int i,j;
  int count;
  scanf("%d %d %d",&N,&M,&C);

  FORN(i,N)
    FORN(j,M)
      mat[i][j] = 25;
  
  FORN(i,N) {
    FORN(j,M) {
      printf("1 %d %d %d %d %d %d\n",i+1,j+1,i+1,j+1,mat[i][j]+1,50);
      fflush(stdout);
      scanf("%d",&count); 
      if(count == 1) 
        mat[i][j]=37;
      else
        mat[i][j]=13;
    }
  }
  printf("3\n");
  fflush(stdout);

  FORN(i,N) {
    FORN(j,M)
      printf("%d ",mat[i][j]);
    printf("\n");
    fflush(stdout);
  }
  
  return 0;
}
