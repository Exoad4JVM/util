
#include <stdint.h>
#include "loongson_intrinsics.h"

void WelsI16x16LumaPredV_lsx (uint8_t* pPred, uint8_t* pRef, const int32_t kiStride) {
  const int8_t* kpSrc = (int8_t*)&pRef[-kiStride];
  const uint64_t kuiT1 = *(uint64_t*)kpSrc;
  const uint64_t kuiT2 = *(uint64_t*)(kpSrc + 8);
  uint8_t* pDst = pPred;
  __m128i kuiT_vec, kuiT1_vec, kuiT2_vec;

  kuiT1_vec = __lsx_vreplgr2vr_d(kuiT1);
  kuiT2_vec = __lsx_vreplgr2vr_d(kuiT2);
  kuiT_vec = __lsx_vpackev_d(kuiT2_vec, kuiT1_vec);

  __lsx_vst(kuiT_vec, pDst, 0);
  __lsx_vstx(kuiT_vec, pDst, 16);
  __lsx_vstx(kuiT_vec, pDst, 32);
  __lsx_vstx(kuiT_vec, pDst, 48);
  __lsx_vstx(kuiT_vec, pDst, 64);
  __lsx_vstx(kuiT_vec, pDst, 80);
  __lsx_vstx(kuiT_vec, pDst, 96);
  __lsx_vstx(kuiT_vec, pDst, 112);
  __lsx_vstx(kuiT_vec, pDst, 128);
  __lsx_vstx(kuiT_vec, pDst, 144);
  __lsx_vstx(kuiT_vec, pDst, 160);
  __lsx_vstx(kuiT_vec, pDst, 176);
  __lsx_vstx(kuiT_vec, pDst, 192);
  __lsx_vstx(kuiT_vec, pDst, 208);
  __lsx_vstx(kuiT_vec, pDst, 224);
  __lsx_vstx(kuiT_vec, pDst, 240);
}

void WelsI16x16LumaPredH_lsx (uint8_t* pPred, uint8_t* pRef, const int32_t kiStride) {
  int32_t iStridex15 = (kiStride << 4) - kiStride;
  int32_t iPredStride = 16;
  int32_t iPredStridex15 = 240; //(iPredStride<<4)-iPredStride;
  uint8_t i = 15;
  __m128i kuiV64_vec;

  do {
    const uint8_t kuiSrc8 = pRef[iStridex15 - 1];
    kuiV64_vec = __lsx_vreplgr2vr_b(kuiSrc8);
    __lsx_vstx(kuiV64_vec, pPred, iPredStridex15);

    iStridex15 -= kiStride;
    iPredStridex15 -= iPredStride;
  } while (i-- > 0);
}
