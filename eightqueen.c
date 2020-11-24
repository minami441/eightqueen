//-----------------------------------------//
//-----------８クイーン----------------------//
//-----------------------------------------//
#include <stdio.h>
int kaisuu=1;                           //
int ban[10][10]={{7,7,7,7,7,7,7,7,7,7},
                 {7,0,0,0,0,0,0,0,0,7},
                 {7,0,0,0,0,0,0,0,0,7},
                 {7,0,0,0,0,0,0,0,0,7},
                 {7,0,0,0,0,0,0,0,0,7},
                 {7,0,0,0,0,0,0,0,0,7},
                 {7,0,0,0,0,0,0,0,0,7},
                 {7,0,0,0,0,0,0,0,0,7},
                 {7,0,0,0,0,0,0,0,0,7},
                 {7,7,7,7,7,7,7,7,7,7}};
void saiki(int,int,int);
int queen(int,int);                     //クイーンを置けるか判定する処理
void hyouji();                          //板を表示する処理

int main(void){
  int t=1;                              //番の縦軸
  int y=1;                              //板の横軸
  int ct=0;                             //クイーンを置いた数をカウント
    while(y<9)saiki(t,y++,ct);
    return 0;
}

void saiki(int t,int y,int ct){
if(queen(t,y)==0){ban[t][y]=8;ct=ct+1;}
if(ct==8){hyouji();}                       //クイーンを８個置いたら版を表示
if(t<8){int i=1;while(i<9)saiki(t+1,i++,ct);}
  ban[t][y]=0;                             //再帰処理が終わったら版の値を元に戻す
}


int queen(int t,int y){                  //縦,横,斜め_判定
  if(ban[t][y]!=0)return -1;             //置けなかったら-1を返す。置けたら0を返す。
  int i=1;while(i<9){if(ban[t][i]==8 || ban[i][y]==8)return -1;++i;}
      i=0;while(1){if(ban[t+i][y+i]==7)break;if(ban[t+i][y+i]==8)return -1;++i;}
      i=0;while(1){if(ban[t-i][y+i]==7)break;if(ban[t-i][y+i]==8)return -1;++i;}
      i=0;while(1){if(ban[t-i][y-i]==7)break;if(ban[t-i][y-i]==8)return -1;++i;}
      i=0;while(1){if(ban[t+i][y-i]==7)break;if(ban[t+i][y-i]==8)return -1;++i;}
    return 0;
}

void hyouji(){
  printf("%d",kaisuu);                    //何回目のパターンの8クイーンかを表示
    kaisuu=kaisuu+1;
  int t,y;
  for(t=1;t<9;t++){
      printf("\n");
    for(y=1;y<9;y++)
      printf("%d",ban[t][y]);
    }
    printf("\n");
}
