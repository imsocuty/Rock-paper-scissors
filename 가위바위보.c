#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main(void) {
    int mai;
    int enemy;
    int score=0;//�⺻����
    int lcore=0;//��������
    int snow=5;//����ü��
    int smax=5;//�ִ�ü��
    int scom=0;//�����޺�
    int scax=0;//�ִ��޺�
    int life=5;//���� 
    int cwin=0; // �̱�Ƚ�� 
    int flag; // 1=win, 0=lose 
   //����
   srand(time(NULL));
   printf("=========================\n ȸ�� Ű���  ���� \n �������� ������ ���۵Ǿ���.\n\n");
    printf("����: 1(����), 2(����), 3(��)�ΰ������մϴ�.\n ���½��߰��������־������׸�ŭ ȸ�簡 ��Ŀ���ϴ�.\n");
   printf("�Ϲݽ¸�: 1��(-2), 3���Ӻ���: 2��(-5), 5���Ӻ���: 3��(-9)\n=========================\n\n");
   printf("\n\t\t�����Ϸ��� �ƹ� Ű�� ��������!");
   while(_kbhit()==NULL); // Ű�� �Է� ������ ���� ��ٸ� 
   while (kbhit()) getch(); // Ű ���۰� ����
   Sleep(300);
   system("cls");
   while(life!=0){
      printf("=========================\n�����緹��: %d��\n�ִ뷹��: %d\n���ӽ¸�: %d\n��������: %d\n==========================\n\n",snow, smax, scom, life);
       printf("==========================\n�����մϴ�. [1, 2, 3] ���� �ϳ��� ���� �Է����ּ���.\n==========================\n\n");
       enemy=rand()%3+1;
       scanf("%d",&mai);
       
       if(mai>3||mai<1) { // 1,2,3���� �ٸ� �� �Է½� �ٽ� �Է¹���
         printf("�ٸ��� �Է��ϼ���");
         Sleep(1000);
         system("cls");
         continue;
      }
      if(mai==enemy){   // ����� ��� 
          printf("ȸ�簡 �״�� �Դϴ�.\n=========================\n\n");
         Sleep(1000); // 1�ʰ� ���� 
         system("cls"); // ȭ���� ������ 
         continue;
      }
      // ��� ���� 
      if(mai=1) flag=enemy==2?0:1;
      else if(mai=2) flag=enemy==3?0:1;
      else flag=enemy==1?0:1;
      
      // ��� ó�� 
      if(flag){ //�̰��� ���
         scom++;
         cwin++; 
         if(scom<3){
            printf("ȸ�簡 �����߽��ϴ�.(+1)\n=========================\n\n");
            score+=1;
            snow+=1;
         }
         else if(scom<5){
            printf("ȸ�簡���ĳ��ٰ��ֽ��ϴ�.(+2)\n=========================\n\n");
            snow+=2;
            score+=1;
         } else {
            printf("ȸ�縦�����������������ϴ�.(+3)\n=========================\n\n");
            snow+=3;
            score+=1;
         }
         if(snow>smax) smax=snow;
         if(scom>scax) scax=scom;
      } else { //������� 
         if(scom<2){
            printf("LOSE.(-1)\n=========================\n\n");
            snow-=1;
         } else if(scom<5){
            printf("���� ���߽��ϴ�.(-2)\n=========================\n\n");
            snow-=5;
         } else{
            printf("��, ������.(-3)\n=========================\n\n");
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
   printf("=========================\n���ӿ���\n\n�⺻����: %d\n�߰�����: %d\n�ִٿ��ӽ¸�: %d\n�̱�Ƚ��: %d\n\n������:  %d\n=========================\n\n", 
   		   score, smax, scax, cwin, lcore );

    if(lcore<5) printf("�߼ұ�� �Դϴ�.");
   else if(lcore<13) printf("����� �Դϴ�.");
    else printf("���� �Դϴ�.");
   return 0; 
}
