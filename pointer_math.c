#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    
    struct_copy();
    
    int tenInts[5][2];
    int *sorted[5];
    
    int indexes_to_sorted[5];
    
    tenInts[0][0] = 10;
    tenInts[0][1] = 15;
    
    tenInts[1][0] = 40;
    tenInts[1][1] = 45;
    
    tenInts[2][0] = 30;
    tenInts[2][1] = 35;
    
    tenInts[3][0] = 50;
    tenInts[3][1] = 55;
    
    tenInts[4][0] = 20;
    tenInts[4][1] = 25;
    
    sorted[0] = &tenInts[0][0];
    sorted[1] = &tenInts[4][0];
    sorted[2] = &tenInts[2][0];
    sorted[3] = &tenInts[1][0];
    sorted[4] = &tenInts[3][0];
    
    for(int a=0; a < 5; a++) {
        int *n = sorted[a];
        int c = (sorted[a] - &tenInts[0][0]) / 2;
        indexes_to_sorted[a] = c;
        printf("Position: %d {%d, %d}\n",a, *n++, *n );
        printf("By Index: %d {%d, %d}\n\n", c, tenInts[c][0], tenInts[c][1]);
    }
    
    int* reconstructed[5];
    
    printf("----------\n");
    
    for(int b = 0; b < 5; b++) {
        int currentOffset = indexes_to_sorted[b];
        int *m = &tenInts[0][0] + (2 * currentOffset);
        reconstructed[b] = m;
    }
    printf("\n----------\n");
    
    for(int b = 0; b < 5; b++) {
        int *n = reconstructed[b];
        printf("Position: %d {%d, %d}\n",b, *n++, *n );
    }
    
    return 0;
}

// ***** Struct copy ******

typedef struct val_test_struct {
    int moocows[3];
} val_test_struct_t;

typedef struct containing_struct {
    val_test_struct_t* valtest;
} containing_struct_t;

typedef struct simple_struct {
    int a;
} simple_struct_t;


int struct_copy() {
    val_test_struct_t* rofl = malloc(sizeof(val_test_struct_t));
    containing_struct_t* containing = malloc(sizeof(containing_struct_t));
    
    rofl->moocows[0] = 1;
    rofl->moocows[1] = 2;
    rofl->moocows[2] = 3;
    
    val_test_struct_t* lol = malloc(sizeof(val_test_struct_t));
    memcpy(lol, rofl,sizeof(val_test_struct_t));
    //memcpy(containing->valtest, rofl,sizeof(val_test_struct_t));
    containing->valtest = lol;
    
    int *original_rofl_first = &(rofl->moocows[0]);
    int *contained_rofl_first = &(containing->valtest->moocows[0]);
    int *another_original_rofl_first = &(rofl->moocows[0]);
    int *what_does_this_say = &(lol->moocows[0]);
    
    rofl->moocows[0] = 99;
    
    int what = containing->valtest->moocows[0];
    *what_does_this_say = 76;
    
    printf("ROFL: First: %d, Second: %d, Third: %d.\n", 
            rofl->moocows[0], rofl->moocows[1], rofl->moocows[2]);
    
    printf("Contained roffle first: %d\n", containing->valtest->moocows[0]);
    
    simple_struct_t *a = malloc(sizeof(simple_struct_t));
    a->a = 4;
    
    simple_struct_t *b = a;
    simple_struct_t *c = malloc(sizeof(simple_struct_t));
    
    int *original_a = &(a->a);
    int *copy_a = &(b->a);
    
    a->a = 5; 
    
    simple_struct_t x = { 1 };
    simple_struct_t y = x;
    
    x.a = 4;
    
    printf("X has: %d, Y has: %d\n", x.a, y.a);
}