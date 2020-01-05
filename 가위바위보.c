#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main(void) {
    int mai;
    int enemy;
    int score=0;//기본점수
    int lcore=0;//최종점수
    int snow=5;//현재체력
    int smax=5;//최대체력
    int scom=0;//현재콤보
    int scax=0;//최대콤보
    int life=5;//생명 
    int cwin=0; // 이긴횟수 
    int flag; // 1=win, 0=lose 
   //시작
   srand(time(NULL));
   printf("=========================\n 회사 키우기  게임 \n 이제그의 게임이 시작되었다.\n\n");
    printf("도움말: 1(가위), 2(바위), 3(보)로게임을합니다.\n 연승시추가점수가주어지나그만큼 회사가 더커집니다.\n");
   printf("일반승리: 1점(-2), 3연속부터: 2점(-5), 5연속부터: 3점(-9)\n=========================\n\n");
   printf("\n\t\t시작하려면 아무 키나 누르세요!");
   while(_kbhit()==NULL); // 키값 입력 받을때 까지 기다림 
   while (kbhit()) getch(); // 키 버퍼값 지움
   Sleep(300);
   system("cls");
   while(life!=0){
      printf("=========================\n★현재레벨: %d★\n최대레벨: %d\n연속승리: %d\n남은생명: %d\n==========================\n\n",snow, smax, scom, life);
       printf("==========================\n시작합니다. [1, 2, 3] 중의 하나의 값을 입력해주세요.\n==========================\n\n");
       enemy=rand()%3+1;
       scanf("%d",&mai);
       
       if(mai>3||mai<1) { // 1,2,3외의 다른 값 입력시 다시 입력받음
         printf("바르게 입력하세요");
         Sleep(1000);
         system("cls");
         continue;
      }
      if(mai==enemy){   // 비겼을 경우 
          printf("회사가 그대로 입니다.\n=========================\n\n");
         Sleep(1000); // 1초간 멈춤 
         system("cls"); // 화면을 깨끗히 
         continue;
      }
      // 결과 추출 
      if(mai=1) flag=enemy==2?0:1;
      else if(mai=2) flag=enemy==3?0:1;
      else flag=enemy==1?0:1;
      
      // 결과 처리 
      if(flag){ //이겼을 경우
         scom++;
         cwin++; 
         if(scom<3){
            printf("회사가 성장했습니다.(+1)\n=========================\n\n");
            score+=1;
            snow+=1;
         }
         else if(scom<5){
            printf("회사가미쳐날뛰고있습니다.(+2)\n=========================\n\n");
            snow+=2;
            score+=1;
         } else {
            printf("회사를도저히막을수없습니다.(+3)\n=========================\n\n");
            snow+=3;
            score+=1;
         }
         if(snow>smax) smax=snow;
         if(scom>scax) scax=scom;
      } else { //졌을경우 
         if(scom<2){
            printf("LOSE.(-1)\n=========================\n\n");
            snow-=1;
         } else if(scom<5){
            printf("제압 당했습니다.(-2)\n=========================\n\n");
            snow-=5;
         } else{
            printf("적, 마무리.(-3)\n=========================\n\n");
            snow-=9;
         }
         scom=0;
         life--;
      }
      Sleep(1000);
      system("cls");
    }
   system("cls");
    lcore = score+smax+scax-5; 
   printf("=========================\n게임오버\n\n기본점수: %d\n추가점수: %d\n최다연속승리: %d\n이긴횟수: %d\n\n총점수:  %d\n=========================\n\n", 
   		   score, smax, scax, cwin, lcore );

    if(lcore<5) printf("중소기업 입니다.");
   else if(lcore<13) printf("공기업 입니다.");
    else printf("대기업 입니다.");
   return 0; 
}
