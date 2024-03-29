

#include <stdint.h>
#include "loongson_intrinsics.h"

void WelsCopy8x8_lsx (uint8_t* pDst, int32_t iStrideD,
                      uint8_t* pSrc, int32_t iStrideS) {

  int32_t iStride0 = 0;
  int32_t iStride1 = iStrideS << 1;
  int32_t iStride2 = iStride1 << 1;

  __m128i src0, src1, src2, src3, src4 ,src5, src6, src7;

  DUP4_ARG2(__lsx_vldx,
            pSrc, iStride0,
            pSrc, iStrideS,
            pSrc, iStride1,
            pSrc, iStride1 + iStrideS,
            src0, src1, src2, src3);
  pSrc += iStride2;
  DUP4_ARG2(__lsx_vldx,
            pSrc, iStride0,
            pSrc, iStrideS,
            pSrc, iStride1,
            pSrc, iStride1 + iStrideS,
            src4, src5, src6, src7);

  iStride1 = iStrideD << 1;

  __lsx_vstelm_d(src0, pDst, 0, 0);
  __lsx_vstelm_d(src1, pDst + iStrideD, 0, 0);
  pDst += iStride1;
  __lsx_vstelm_d(src2, pDst, 0, 0);
  __lsx_vstelm_d(src3, pDst + iStrideD, 0, 0);
  pDst += iStride1;
  __lsx_vstelm_d(src4, pDst, 0, 0);
  __lsx_vstelm_d(src5, pDst + iStrideD, 0, 0);
  pDst += iStride1;
  __lsx_vstelm_d(src6, pDst, 0, 0);
  __lsx_vstelm_d(src7, pDst + iStrideD, 0, 0);
}

void WelsCopy16x16_lsx (uint8_t* pDst, int32_t iStrideD,
                        uint8_t* pSrc, int32_t iStrideS) {
  int32_t iStride0 = 0;
  int32_t iStride1 = iStrideS;
  int32_t iStride2 = iStrideS << 1;
  int32_t iStride3 = iStride2 + iStrideS;
  int32_t iStride4 = iStrideS << 2;

  __m128i src0, src1, src2, src3, src4, src5, src6, src7;
  __m128i src8, src9, src10, src11, src12, src13, src14, src15;

  DUP4_ARG2(__lsx_vldx,
            pSrc, iStride0, pSrc, iStride1,
            pSrc, iStride2, pSrc, iStride3,
            src0, src1, src2, src3);
  pSrc += iStride4;
  DUP4_ARG2(__lsx_vldx,
            pSrc, iStride0, pSrc, iStride1,
            pSrc, iStride2, pSrc, iStride3,
            src4, src5, src6, src7);
  pSrc += iStride4;
  DUP4_ARG2(__lsx_vldx,
            pSrc, iStride0, pSrc, iStride1,
            pSrc, iStride2, pSrc, iStride3,
            src8, src9, src10, src11);
  pSrc += iStride4;
  DUP4_ARG2(__lsx_vldx,
            pSrc, iStride0, pSrc, iStride1,
            pSrc, iStride2, pSrc, iStride3,
            src12, src13, src14, src15);

  iStride1 = iStrideD;
  iStride2 = iStrideD << 1;
  iStride3 = iStride2 + iStrideD;
  iStride4 = iStrideD << 2;

  __lsx_vstx(src0, pDst, iStride0);
  __lsx_vstx(src1, pDst, iStride1);
  __lsx_vstx(src2, pDst, iStride2);
  __lsx_vstx(src3, pDst, iStride3);
  pDst += iStride4;
  __lsx_vstx(src4, pDst, iStride0);
  __lsx_vstx(src5, pDst, iStride1);
  __lsx_vstx(src6, pDst, iStride2);
  __lsx_vstx(src7, pDst, iStride3);
  pDst += iStride4;
  __lsx_vstx(src8, pDst, iStride0);
  __lsx_vstx(src9, pDst, iStride1);
  __lsx_vstx(src10, pDst, iStride2);
  __lsx_vstx(src11, pDst, iStride3);
  pDst += iStride4;
  __lsx_vstx(src12, pDst, iStride0);
  __lsx_vstx(src13, pDst, iStride1);
  __lsx_vstx(src14, pDst, iStride2);
  __lsx_vstx(src15, pDst, iStride3);
}

void WelsCopy16x16NotAligned_lsx (uint8_t* pDst, int32_t iStrideD,
                                  uint8_t* pSrc, int32_t iStrideS) {
  int32_t iStride0 = 0;
  int32_t iStride1 = iStrideS;
  int32_t iStride2 = iStrideS << 1;
  int32_t iStride3 = iStride2 + iStrideS;
  int32_t iStride4 = iStrideS << 2;

  v16u8_b src0, src1, src2, src3, src4, src5, src6, src7;
  v16u8_b src8, src9, src10, src11, src12, src13, src14, src15;

  DUP4_ARG2((v16u8_b)__lsx_vldx,
            pSrc, iStride0, pSrc, iStride1,
            pSrc, iStride2, pSrc, iStride3,
            src0, src1, src2, src3);
  pSrc += iStride4;
  DUP4_ARG2((v16u8_b)__lsx_vldx,
            pSrc, iStride0, pSrc, iStride1,
            pSrc, iStride2, pSrc, iStride3,
            src4, src5, src6, src7);
  pSrc += iStride4;
  DUP4_ARG2((v16u8_b)__lsx_vldx,
            pSrc, iStride0, pSrc, iStride1,
            pSrc, iStride2, pSrc, iStride3,
            src8, src9, src10, src11);
  pSrc += iStride4;
  DUP4_ARG2((v16u8_b)__lsx_vldx,
            pSrc, iStride0, pSrc, iStride1,
            pSrc, iStride2, pSrc, iStride3,
            src12, src13, src14, src15);

  iStride1 = iStrideD;
  iStride2 = iStrideD << 1;
  iStride3 = iStride2 + iStrideD;
  iStride4 = iStrideD << 2;

  __lsx_vstx((__m128i)src0, pDst, iStride0);
  __lsx_vstx((__m128i)src1, pDst, iStride1);
  __lsx_vstx((__m128i)src2, pDst, iStride2);
  __lsx_vstx((__m128i)src3, pDst, iStride3);
  pDst += iStride4;
  __lsx_vstx((__m128i)src4, pDst, iStride0);
  __lsx_vstx((__m128i)src5, pDst, iStride1);
  __lsx_vstx((__m128i)src6, pDst, iStride2);
  __lsx_vstx((__m128i)src7, pDst, iStride3);
  pDst += iStride4;
  __lsx_vstx((__m128i)src8, pDst, iStride0);
  __lsx_vstx((__m128i)src9, pDst, iStride1);
  __lsx_vstx((__m128i)src10, pDst, iStride2);
  __lsx_vstx((__m128i)src11, pDst, iStride3);
  pDst += iStride4;
  __lsx_vstx((__m128i)src12, pDst, iStride0);
  __lsx_vstx((__m128i)src13, pDst, iStride1);
  __lsx_vstx((__m128i)src14, pDst, iStride2);
  __lsx_vstx((__m128i)src15, pDst, iStride3);
}
