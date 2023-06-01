#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <string.h>
#include <mm_malloc.h>
#include <stdlib.h>
#include <algorithm>

struct student{
    char name[20];
    int language;
    int english;
    int math;
    int total;
    int mean;
    char *grade;
};

struct student tot_mean(struct student human){
    double tmp;

    tmp = (human.language + human.english + human.math);
    human.total = tmp;
    human.mean = tmp/3;
    return human;
}

int main(void){
    struct student human[5];

    ///학생 이름 및 점수 받기
    for(int i=0; i<5; i++){
        printf("\n학생 이름: ");
        scanf("%s", human[i].name);
        printf("\n국어 점수: ");
        scanf("%d", &human[i].language);
        printf("\n영어 점수: ");
        scanf("%d", &human[i].english);
        printf("\n수학 점수: ");
        scanf("%d", &human[i].math);

        human[i] = tot_mean(human[i]);

        if(human[i].mean >= 90)
            human[i].grade = "A";
        else if(human[i].mean >= 80)
            human[i].grade = "B";
        else if(human[i].mean >= 70)
            human[i].grade = "C";
        else if(human[i].mean >= 60)
            human[i].grade = "D";
        else
            human[i].grade = "F";
    }

    ///정렬 및 결과
    int tmp[5],temp;

    for(int u = 0; u<5; u++){
        tmp[u] = human[u].total;
    }

    for(int i=0; i<4; i++){
        for(int k =i+1; k<5;k++){
            if(tmp[i]<tmp[k]){
                temp = tmp[k];
                tmp[k] = tmp[i];
                tmp[i] = temp;
            }
        }
    }

    while(1){
        int n =0;
        for(int i =0; i<5; i++){
            for(int j =0; j<5; j++)
                if(tmp[i] == human[j].total){
                    n++;
                    printf("이름: %s, 총점: %d, 평균: %d, 학점: %s \n",human[j].name,human[j].total,human[j].mean,human[j].grade);
                }
                else
                    continue;
        }
        if(n==5)
            break;
    }
}