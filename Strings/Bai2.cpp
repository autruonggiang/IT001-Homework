#include<stdio.h>
#include<string.h>

char DoiChuHoa(char s[]) 
{
    int i;

    for (i = 0; i < strlen(s); i++) {

        if (s[i] >= 'a' && s[i] <= 'z')

            s[i] = s[i] - 32;

    }
}

int main() {

    char xau[100];

    printf("Nhap xau: ");

    gets(xau);
    DoiChuHoa(xau);
    puts(xau);

    return 0;

}
