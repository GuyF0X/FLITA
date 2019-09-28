#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

void dots(){Sleep(500);printf(".");Sleep(500);printf(".");Sleep(500);printf(".");Sleep(3000);}

void bad_mood_1 (){ //Что будет, если пользователь будет плохо себя вести
    system("cls");
    Sleep(3000);
    printf("*вздох*");
    Sleep(3000);
    system("cls");
    printf("Послушайте");dots();printf("\nВы тут ввёли кое-что");dots();
    printf("\nМы же с вами оба понимаем, что это было не двоичное число.");Sleep(3000);system("cls");
    printf("Давайте я закрою на это глаза. В конце концов это был первый раз. Будем считать, что вы просто ошиблись, хорошо?");Sleep(6000);system("cls");
    printf("Предлагаю продолжить дальше. Только больше не ошибайтесь так, пожалуйста.");Sleep(3000);system("cls");
}

void bad_mood_2(){
    system("cls");
    Sleep(3000);
    printf("Знаете, как говорят"); dots();
    printf("\nОдин раз - случайность, два - совпадение, три - закономерность.");Sleep(3000);
    system("cls");
    printf("Это я к тому");dots();printf("Это я к тому");dots();printf("Что если вы ошибётесь в третий раз, то я посчитаю это намеренным оскорблением моих чувств!");Sleep(6000);
    system("cls");
    printf("Послушайте");dots();printf("Я просто хочу, чтобы вы ввели парочку двоичных чисел, чтобы затем перевести их в десятичный вид.\n");Sleep(6000);
    printf("Ну это же несложно!");Sleep(3000);
    printf("\nПрошу вас, давайте попробуем снова.");Sleep(3000);
    system("cls");
}

void bad_mood_3(){
    system("cls");
    printf("Знаете");dots();
    printf("\nВы меня довели.");Sleep(2000);
    system("cls");
    printf("Надежда, как говорится, умирает последней.");Sleep(3000);
    printf("Дальше идёт только сама программа");dots();
    system("cls");Sleep(3000);
    printf("Задача 'Мастер задания числовых множеств' была успешно снята.");Sleep(3000);
    system("cls");
    printf("Надеюсь");dots();
    printf("Вы довольны собой.\n");
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
    int bad_mood = 0;//Да, у этой программы есть настроение, и пользователь может его портить.
    printf("Вас приветствует мастер задания числовых множеств.\nВведите количество чисел, которые вы хотите задать.\n");
    int N=0;
    int f=0;
    start: //GOTO - ЭТО НЕ ЗЛО, ЭТО ОЧЕНЬ УДОБНО!!! В данном случае я использую его для перезапуска процесса задания числа элементов во множестве.
    scanf("%d",&N);
    if(N<=0){
        system("cls");
        printf("Пользователь-сан, прошу вас, введите НАТУРАЛЬНОЕ число.\n");
        system("pause");
        system("cls");
        goto start;
    }
    printf("Вы уверены, что хотите задать множество, длиной "); printf("%d",N); printf("?"); printf("\n0 - Нет\n1 - Да\n");
    scanf("%d",&f);
    while((f!=1)&&(f!=0)){
        system("cls");
        printf("Пожалуйста, введите корректный ответ.\n0 - Нет\n1 - Да\n");
        scanf("%d",&f);
    }
    if(f==0){system("cls");goto start;}
    system("cls");
    printf("Кстати, вы задаёте множество ДВОИЧНЫХ чисел.\nТак что лучше бы всем вашим числам состоять только из ноликов и единиц...");
    Sleep(8000);
    system("cls");
    printf("Знаете, я ОЧЕНЬ надеюсь, что мы поняли друг друга");dots();
    Sleep(2000);
    system("cls");
    printf("Вводите по одному ДВОИЧНОМУ ЧИСЛУ, пожалуйста.\n");
    Sleep(2000);
    printf("Только прошу вас, пользователь-семпай");dots();
    printf("\nНе больше десяти цифр за раз.");Sleep(2000);
    printf("\nЯ только начинающая программа, если вы превысите этот предел, я посчитаю это не двоичным числом.");Sleep(3000);
    system("cls");
    printf("Прошу вас");dots();printf("Будьте со мной нежнее.");Sleep(3000);
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
    printf("Вы просто молодец, вы всё-таки сделали это! Вот ваше множество, над которым мы так упорно работали!\n");
    for(int i=0;i<N;i++){printf("%li",Mnozhestvo[i]);printf("\n");}
    printf("Я понимаю, что оно прекрасно, но вместо того, чтобы созерцать его, можно его перевести в десятичный вид...\nЧто скажете? (ну, честно говоря у вас не много вариантов)\n");
    system("pause");
    printf("Вот ваше любимое множество в десятичном виде:\n");
    for(int i=0;i<N;i++){
        printf("%li",transfer_to_decimal(Mnozhestvo[i]));
        printf("\n");
    }
    end:
    return 0;
}
