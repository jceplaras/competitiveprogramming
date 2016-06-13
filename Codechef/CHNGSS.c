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
      printf("1 %d %d %d %d %d %d\n",i+1,i+1,j+1,j+1,mat[i][j]+1,50);
      fflush(stdout);
      scanf("%d",&count); 
      if(count == 1) {
        printf("1 %d %d %d %d %d %d\n",i+1,i+1,j+1,j+1,38,50);
        fflush(stdout);
        scanf("%d",&count); 

        if(count) mat[i][j] = 44;
        else mat[i][j] = 32;
      }
      else {
        printf("1 %d %d %d %d %d %d\n",i+1,i+1,j+1,j+1,13,25);
        fflush(stdout);
        scanf("%d",&count); 

        if(count == 1) mat[i][j] = 19; 
        else mat[i][j] = 7;
      }
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
