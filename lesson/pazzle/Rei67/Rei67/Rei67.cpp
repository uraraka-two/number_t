// Rei67.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -------------------------------------------------------
 *   �_�C�i�~�b�N�E�v���O���~���O�i�i�b�v�E�T�b�N���j  *
 * -------------------------------------------------------
 */

#include <stdio.h>

#define limit 8         /* �i�b�v�T�b�N�̏d�ʐ����l */
#define n 5             /* �i���̎�� */
#define min    1        /* �d���̍ŏ��l */

void main(void)
{
    struct body {
        char name[20];         /* �i�� */
        int size;           /* �d�� */
        long price;         /* ���i */
    } a[]={{"plum",4,4500},{"apple",5,5700},{"orange",2,2250},
           {"strawberry",1,1100},{"melon",6,6700}};
    long newvalue,value[limit+1];
    int item[limit+1],
        i,s,p;

    for (s=0;s<=limit;s++){
        value[s]=0;         /* �����l */
    }
    for (i=0;i<n;i++){                      /* �i���̔ԍ� */
        for (s=a[i].size;s<=limit;s++){     /* �i�b�v�̃T�C�Y */
            p=s-a[i].size;                  /* �󂫃T�C�Y */
            newvalue=value[p]+a[i].price;
            if (newvalue>value[s]){
                value[s]=newvalue;item[s]=i;    /* �œK���̍X�V */
            }
        }
    }

    printf("    �i  �ځ@���i\n");
    for (s=limit;s>=min;s=s-a[item[s]].size)
        printf("%10s %5ld\n",a[item[s]].name,a[item[s]].price);
    printf("    ��  �v %5ld\n",value[limit]);
	getchar();
}


