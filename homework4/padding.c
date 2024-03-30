#include <stdio.h>


struct student{
    char lastName[13]; /*13 bytes*/
    int studentId; /*4 bytes*/
    short grade; /*2 bytes*/
};


int main(){
    struct student pst;

    //%ld - 부호있는 10진정수 long형

    // 배열은 padding 바이트에 의해 정렬되고 다음 int studentId를 출력 전 padding바이트가 추가되었습니다, 
    // 4바이트로 정렬되는데 구조체들이 int형이 4바이트 단위로 정렬되니까 메모리배열에 맞추기위해 padding바이트가 추가되었습니다.
    printf("size of student = %ld\n", sizeof(struct student)); 
    printf("size of int = %ld\n", sizeof(int)); //int형 4바이트가 출력됩니다.
    printf("size of short = %ld\n", sizeof(short)); //short는 2바이트가 출력됩니다.

    printf("[----- [강태광] [2021041098] -----]");

    return 0;
}