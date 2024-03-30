#include <stdio.h>
#include <stdlib.h>

void main(){
    int **x; //이중포인터로 *(*x)와 같고 이차원 배열을 나타내고 x[0][0]과 같습니다.

    //%lu 부호없는 long형 정수
    printf("sizeof(x) = %lu\n", sizeof(x)); //int **x;의 크기를 출력하고 64비트 시스템에서 8바이트가 출력됩니다.
    printf("sizeof(*x) = %lu\n", sizeof(*x)); //int **x;가 가리키는 크기를 출력하고 8바이트를 출력합니다.
    printf("sizeof(**x) = %lu\n", sizeof(**x)); //**x는 이차원배열의 첫 번째 요소를 참조하여 int형식을 기리키므로 4바이트를 출력합니다.

    printf("[----- [강태광] [2021041098] -----]");
}