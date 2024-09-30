#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>

void myChAr_OuT(char c) {
    write(1, &c, 1);
    
}
int mySTRing_oUTSTd(const char *str) {
    int COUNtnumMM = 0;
    if (str == NULL) {
        str = "(null)";
    }
    while (*str) {
        myChAr_OuT(*str++);
        COUNtnumMM++;
    }
    return COUNtnumMM;
}


int writeNUM_stDOUt(uintptr_t nUM, int bASe, int UppERcAsE) {
    if (nUM == 0) {
        myChAr_OuT('0');
        return 1;
    }

    int COUNtnumMM = 0;
    char bUfF[32];
    char *ptr = &bUfF[31];
    *ptr = '\0';

    // Use lowercase or uppercase digits based on the 'uppercase' flag
    char *digits = UppERcAsE ? "0123456789ABCDEF" : "0123456789abcdef";

    do {
        *--ptr = digits[nUM % bASe];
        nUM /= bASe;
        COUNtnumMM++;
    } while (nUM != 0);

    return mySTRing_oUTSTd(ptr);
}




int my_printf(const char *pATtERn, ...) {
    va_list args;
    va_start(args, pATtERn);
    int COUNtnumMM = 0;

    while (*pATtERn) {
        if (*pATtERn == '%') {
            pATtERn++;
            switch (*pATtERn) {
                case 'd': {
                    int nUM = va_arg(args, int);
                    if (nUM < 0) {
                        myChAr_OuT('-');
                        nUM = -nUM;
                        COUNtnumMM++;
                    }
                    COUNtnumMM += writeNUM_stDOUt(nUM, 10, 0);
                    break;
                }
                case 'o': {
                    unsigned int nUM = va_arg(args, unsigned int);
                    COUNtnumMM += writeNUM_stDOUt(nUM, 8, 0);
                    break;
                }
                case 'u': {
                    unsigned int nUM = va_arg(args, unsigned int);
                    COUNtnumMM += writeNUM_stDOUt(nUM, 10, 0);
                    break;
                }
                case 'x': {
                    unsigned int nUM = va_arg(args, unsigned int);
                    COUNtnumMM += writeNUM_stDOUt(nUM, 16, 1);
                    break;
                }


                case 'X': {
                    unsigned int nUM = va_arg(args, unsigned int);
                    COUNtnumMM += writeNUM_stDOUt(nUM, 16, 1);
                    break;
                }

                
                case 'c': {
                    char ch = (char)va_arg(args, int);
                    myChAr_OuT(ch);
                    COUNtnumMM++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    COUNtnumMM += mySTRing_oUTSTd(str);
                    break;
                }
                case 'p': {
                    uintptr_t ptr = (uintptr_t)va_arg(args, void *);
                    mySTRing_oUTSTd("0x");
                    COUNtnumMM += 2;
                    COUNtnumMM += writeNUM_stDOUt((unsigned long)ptr, 16, 0);
                    break;
                }


                default:
                    myChAr_OuT(*pATtERn);
                    COUNtnumMM += 2;
            }
        } else {
            myChAr_OuT(*pATtERn);
            COUNtnumMM++;
        }
        pATtERn++;
    }

    va_end(args);
    return COUNtnumMM;
}





