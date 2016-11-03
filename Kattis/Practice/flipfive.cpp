#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int getSwitcher(int i) {
    if(i == 1) return 11;
    if(i == 2) return 23;
    if(i == 3) return 38;
    if(i == 4) return 89;
    if(i == 5) return 186;
    if(i == 6) return 308;
    if(i == 7) return 200;
    if(i == 8) return 464;
    if(i == 9) return 416;
    
} 
int main()
{
   int storage[600];
   char s[100];
  
   
   
   
   
    for(int i=0;i<600;i++)
    storage[i] = -1;
    //s[b] = m
  storage[0] = 0;
   queue<int> countMove;
   queue<int> board;
   countMove.push(0);
   board.push(0);
   
   while(!board.empty()) {
       int currentCountMove = countMove.front(); countMove.pop();
       int currentBoard = board.front(); board.pop();
       for(int i=1;i<10;i++) {
        int nextBoard = currentBoard ^ getSwitcher(i);
        
        if(storage[nextBoard] == -1) {
            board.push(nextBoard);
            countMove.push(currentCountMove+1);
            storage[nextBoard] = currentCountMove+1;
            
        }
           
       } 
   }
   
   int T;
   scanf("%d",&T);
   while(T--) {
   int trueBoard = 0;   
   int ctr = 0;
   for(int i=0;i<3;i++) {
       scanf("%s",s);
       for(int j = 0; j<3;j++) {
            if(s[j]=='*') {
            int tick = 1;
            tick = tick << ctr;  
            trueBoard+=tick;
            }
            ctr++;
       }
   }
   printf("%d\n",storage[trueBoard]);
   }
   return 0;
}
