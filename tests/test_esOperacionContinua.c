#include <stdio.h>
#include <assert.h>
#include "../calculadora-aux.h"

void test_esOperacionContinuada() {
    assert(esOperacionContinuada("*5") == 1);
    assert(esOperacionContinuada("/5") == 1);
    assert(esOperacionContinuada("+5") == 1);
    assert(esOperacionContinuada("-5") == 1);
    assert(esOperacionContinuada("1+2") == 0);
    assert(esOperacionContinuada("1-2") == 0);
    assert(esOperacionContinuada("1*2") == 0);
    assert(esOperacionContinuada("1/2") == 0);
    assert(esOperacionContinuada("-1*2") == 0);
    assert(esOperacionContinuada("-1/-2") == 0);
    assert(esOperacionContinuada("  -1 / -2  ") == 0);

    printf("All esOperacionContinua tests passed!\n");
}

int main() {
    test_esOperacionContinuada();
    return 0;
}
