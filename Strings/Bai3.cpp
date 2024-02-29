#include<stdio.h>
#include<string.h>

#define max 100

char DoiThanhThuong (char s[])

{
    int i;

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {

            s[i] = s[i] + 32;
        }
    }

    printf("%s", s);
}

int main()

{
    char s[max];

    printf("Nhap chuoi: ");

    gets(s);

    DoiThanhThuong (s);
	
	return 0;
}

