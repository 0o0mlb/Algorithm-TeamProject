#include <stdio.h>
#include <stdlib.h>

//Report 3

/* ���� �̸� */
#define filename "trace1.din"

struct i_cache {	/* �ν�Ʈ���� ĳ�� ����ü */
    int tag;
    int valid;
    int time;
};

struct d_cache { /* ������ ĳ�� ����ü */
    int tag;	/* �±� */
    int valid;	/* valid bit */
    int time;	/* LRU�� �����ϱ� ���� ������ ���� �ð�*/
    int dirty;	/* write back �� dirty bit */
};

/* �Լ� ��� */
void simulation(int c_size, int b_size, int assoc);
void read_data(int addr, int c_size, int b_size, int assoc);
void write_data(int addr, int c_size, int b_size, int assoc);
void fetch_inst(int addr, int c_size, int b_size, int assoc);
int evict(int set, int assoc, char mode);

int main() {
    int cache[5] = { 1024, 2048, 4096, 8192, 16384 }; /* ĳ�� ������ */
    int block[2] = { 16, 64 };    /* �� ������ */
    int associative[4] = { 1, 2, 4, 8 };  /* associative */
    int i, j, k;  /* �ݺ��� �ε��� */
    int input = 0;

    while (input != 3) {
        printf("1. print all\n2. select\n3. exit\n: ");
        scanf("%d", &input);
        /* ��ü �ùķ��̼� */
        if (input == 1) {
            printf("cache size | block size | associative | d-miss rate | i-miss rate | mem write\n");
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 5; j++) {
                    for (k = 0; k < 4; k++) {
                        simulation(cache[j], block[i], associative[k]);

                    }
                }
            }
        }
        /* ���� �ùķ��̼� */
        else if (input == 2) {
            printf("cache size | block size | associative | d-miss rate | i-miss rate | mem write\n");
            printf("cache size : ");
            scanf("%d", &i);
            printf("block size : ");
            scanf("%d", &j);
            printf("associative : ");
            scanf("%d", &k);

            simulation(i, j, k);
        }
    }
    return 0;
}

//report3 ��ǻ�ͱ���