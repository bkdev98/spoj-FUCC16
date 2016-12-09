#include <stdio.h>
#include <string.h>

typedef struct str {
    char mssv[8];
    char name[30];
    int tuoi;
    float gpa;
} Stu;

int main(int argc, char** argv) {
    Stu hs[30];
    int n;
    scanf("%d",&n);
    fpurge(stdin);
    for(int i = 0; i < n; i++){
        printf("MSSV: ");
        gets(hs[i].mssv);
        fpurge(stdin);
        printf("Ten: ");
        gets(hs[i].name);
        fpurge(stdin);
        printf("Tuoi: ");
        scanf("%d", &hs[i].tuoi);
        printf("GPA: ");
        scanf("%f", &hs[i].gpa);
        fpurge(stdin);
    }
    for(int i = 0; i < n; i++)
    {
        printf("MSSV:%s\nTen:%s\nTuoi:%d\nGPA:%0.2f\n", hs[i].mssv, hs[i].name, hs[i].tuoi, hs[i].gpa );
    }
    return (0);
}
