#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

void dots(){Sleep(500);printf(".");Sleep(500);printf(".");Sleep(500);printf(".");Sleep(3000);}

void bad_mood_1 (){ //��� �����, ���� ������������ ����� ����� ���� �����
    system("cls");
    Sleep(3000);
    printf("*�����*");
    Sleep(3000);
    system("cls");
    printf("����������");dots();printf("\n�� ��� ���� ���-���");dots();
    printf("\n�� �� � ���� ��� ��������, ��� ��� ���� �� �������� �����.");Sleep(3000);system("cls");
    printf("������� � ������ �� ��� �����. � ����� ������ ��� ��� ������ ���. ����� �������, ��� �� ������ ��������, ������?");Sleep(6000);system("cls");
    printf("��������� ���������� ������. ������ ������ �� ���������� ���, ����������.");Sleep(3000);system("cls");
}

void bad_mood_2(){
    system("cls");
    Sleep(3000);
    printf("������, ��� �������"); dots();
    printf("\n���� ��� - �����������, ��� - ����������, ��� - ��������������.");Sleep(3000);
    system("cls");
    printf("��� � � ����");dots();printf("��� � � ����");dots();printf("��� ���� �� �������� � ������ ���, �� � �������� ��� ���������� ������������ ���� ������!");Sleep(6000);
    system("cls");
    printf("����������");dots();printf("� ������ ����, ����� �� ����� ������� �������� �����, ����� ����� ��������� �� � ���������� ���.\n");Sleep(6000);
    printf("�� ��� �� ��������!");Sleep(3000);
    printf("\n����� ���, ������� ��������� �����.");Sleep(3000);
    system("cls");
}

void bad_mood_3(){
    system("cls");
    printf("������");dots();
    printf("\n�� ���� ������.");Sleep(2000);
    system("cls");
    printf("�������, ��� ���������, ������� ���������.");Sleep(3000);
    printf("������ ��� ������ ���� ���������");dots();
    system("cls");Sleep(3000);
    printf("������ '������ ������� �������� ��������' ���� ������� �����.");Sleep(3000);
    system("cls");
    printf("�������");dots();
    printf("�� �������� �����.\n");
    system("pause");
}

long check_if_binary(long num){
    int count = 0;
    while(num != 0){
        int val = num % 10;
        if((val != 1) && (val != 0)){count++;break;}
    num = num / 10;
    }
    if(count > 0){return 0;}
    else{return 1;}
}

long transfer_to_decimal(long Value){
    long result = 0;
    for (long i = 1; Value; Value/=10, i*=2){
        result += i*(Value%10);
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int bad_mood = 0;//��, � ���� ��������� ���� ����������, � ������������ ����� ��� �������.
    printf("��� ������������ ������ ������� �������� ��������.\n������� ���������� �����, ������� �� ������ ������.\n");
    int N=0;
    int f=0;
    start: //GOTO - ��� �� ���, ��� ����� ������!!! � ������ ������ � ��������� ��� ��� ����������� �������� ������� ����� ��������� �� ���������.
    scanf("%d",&N);
    if(N<=0){
        system("cls");
        printf("������������-���, ����� ���, ������� ����������� �����.\n");
        system("pause");
        system("cls");
        goto start;
    }
    printf("�� �������, ��� ������ ������ ���������, ������ "); printf("%d",N); printf("?"); printf("\n0 - ���\n1 - ��\n");
    scanf("%d",&f);
    while((f!=1)&&(f!=0)){
        system("cls");
        printf("����������, ������� ���������� �����.\n0 - ���\n1 - ��\n");
        scanf("%d",&f);
    }
    if(f==0){system("cls");goto start;}
    system("cls");
    printf("������, �� ������ ��������� �������� �����.\n��� ��� ����� �� ���� ����� ������ �������� ������ �� ������� � ������...");
    Sleep(8000);
    system("cls");
    printf("������, � ����� �������, ��� �� ������ ���� �����");dots();
    Sleep(2000);
    system("cls");
    printf("������� �� ������ ��������� �����, ����������.\n");
    Sleep(2000);
    printf("������ ����� ���, ������������-������");dots();
    printf("\n�� ������ ������ ���� �� ���.");Sleep(2000);
    printf("\n� ������ ���������� ���������, ���� �� ��������� ���� ������, � �������� ��� �� �������� ������.");Sleep(3000);
    system("cls");
    printf("����� ���");dots();printf("������ �� ���� ������.");Sleep(3000);
    system("cls");
    long Mnozhestvo[N];
    for(int i=0;i<N;i++){Mnozhestvo[i]=0;}
    long tmp=0;
    for(int i=0;i<N;i++){
        new_num:
        scanf("%li",&tmp);
        if(check_if_binary(tmp)==0){
            bad_mood++;
            if(bad_mood==1){bad_mood_1();goto new_num;}
            if(bad_mood==2){bad_mood_2();goto new_num;}
            if(bad_mood==3){bad_mood_3();goto end;}
        }
        Mnozhestvo[i]=tmp;
    }
    system("cls");
    printf("�� ������ �������, �� ��-���� ������� ���! ��� ���� ���������, ��� ������� �� ��� ������ ��������!\n");
    for(int i=0;i<N;i++){printf("%li",Mnozhestvo[i]);printf("\n");}
    printf("� �������, ��� ��� ���������, �� ������ ����, ����� ��������� ���, ����� ��� ��������� � ���������� ���...\n��� �������? (��, ������ ������ � ��� �� ����� ���������)\n");
    system("pause");
    printf("��� ���� ������� ��������� � ���������� ����:\n");
    for(int i=0;i<N;i++){
        printf("%li",transfer_to_decimal(Mnozhestvo[i]));
        printf("\n");
    }
    end:
    return 0;
}
