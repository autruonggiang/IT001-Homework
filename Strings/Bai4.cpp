#include <stdio.h>
#include <string.h>

char* vietHoaKyTuDau (char *S)
{
    char *KetQua = new char [strlen(S)];

    if (S[0] != ' ' && S[0] >= 97)
        KetQua[0] = S[0] - 32;
        
    else
        KetQua[0] = S[0];

    for (int i = 1; i < strlen(S); i++)
	{
        KetQua[i] = S[i];
        
        if (S[i] == ' ' && S[i+1] != ' ' && S[i+1] >= 97){
            KetQua[i+1] = S[i+1] - 32;
            i++;
        }
    }

    KetQua[strlen(S)] = '\0';

    return KetQua;
}

int main()
{
    char S[300];

    printf ("Nhap vao chuoi: ");
    fflush (stdin);
    fgets (S, 300, stdin);

    printf ("Ket qua chuoi: ");
    char* ketQua = vietHoaKyTuDau(S);

    puts (ketQua);
}
