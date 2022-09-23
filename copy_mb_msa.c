#include <stdint.h>
#include "msa_macros.h"

void WelsCopy8x8_msa(uint8_t* pDst, int32_t iStrideD, uint8_t* pSrc,
                     int32_t  iStrideS ) {
    v16u8 src0, src1;
    for (int i = 0; i < 4; i++) {
        MSA_LD_V2(v16u8, pSrc, iStrideS, src0, src1);
        MSA_ST_D(src0, 0, pDst);
        MSA_ST_D(src1, 0, pDst + iStrideD);
        pSrc += 2 * iStrideS;
        pDst += 2 * iStrideD;
    }
}

void WelsCopy8x16_msa(uint8_t* pDst, int32_t iStrideD, uint8_t* pSrc,
                      int32_t iStrideS) {
    WelsCopy8x8_msa(pDst, iStrideD, pSrc, iStrideS);
    WelsCopy8x8_msa(pDst + 8 * iStrideD, iStrideD,
                    pSrc + 8 * iStrideS, iStrideS);
}

void WelsCopy16x8_msa(uint8_t* pDst, int32_t iStrideD, uint8_t* pSrc,
                      int32_t iStrideS) {
    v16u8 src0, src1;
    for (int i = 0; i < 4; i++) {
        MSA_LD_V2(v16u8, pSrc, iStrideS, src0, src1);
        MSA_ST_V2(v16u8, src0, src1, pDst, iStrideD);
        pSrc += 2 * iStrideS;
        pDst += 2 * iStrideD;
    }
}

void WelsCopy16x16_msa(uint8_t* pDst, int32_t iStrideD, uint8_t* pSrc,
                       int32_t iStrideS) {
    WelsCopy16x8_msa(pDst, iStrideD, pSrc, iStrideS);
    WelsCopy16x8_msa(pDst + 8 * iStrideD, iStrideD,
                     pSrc + 8 * iStrideS, iStrideS);
};
