#ifndef __INTEL_GPUCHIPS__
#define __INTEL_GPUCHIPS__

#include <stdint.h>

typedef uint32_t GPUCHIP;

enum {
  CHIP_UNKNOWN_INTEL,
  // Gen6
  CHIP_HD_2000,
  CHIP_HD_3000,
  // Gen7
  CHIP_HD_2500,
  CHIP_HD_4000,
  CHIP_HD_P4000,
  // Gen7.5
  CHIP_HD_4200,
  CHIP_HD_4400,
  CHIP_HD_4600,
  CHIP_HD_P4600,
  CHIP_IRIS_5100,
  CHIP_IRISP_5200,
  CHIP_IRISP_P5200,
  // Gen8
  CHIP_HD_5300,
  CHIP_HD_5500,
  CHIP_HD_5600,
  CHIP_HD_P5700,
  CHIP_HD_6000,
  CHIP_IRIS_6100,
  CHIP_IRISP_6200,
  CHIP_IRISP_P6300,
  // Gen9
  CHIP_HD_510,
  CHIP_HD_515,
  CHIP_HD_520,
  CHIP_HD_530,
  CHIP_HD_P530,
  CHIP_HD_540,
  CHIP_HD_550,
  CHIP_IRIS_P555,
  CHIP_IRIS_580,
  CHIP_IRIS_P580,
  // Gen9.5
  CHIP_UHD_600,
  CHIP_UHD_605,
  CHIP_UHD_620,
  CHIP_UHD_630,
  CHIP_HD_610,
  CHIP_HD_615,
  CHIP_HD_620,
  CHIP_HD_630,
  CHIP_HD_P630,
  CHIP_IRISP_640,
  CHIP_IRISP_650,
};

#endif
