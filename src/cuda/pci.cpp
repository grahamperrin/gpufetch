#include <stdio.h>

#include "pci.hpp"
#include "chips.hpp"
#include "../common/global.hpp"
#include "../common/pci.hpp"

#define CHECK_PCI_START if (false) {}
#define CHECK_PCI(pci, id, chip) \
   else if (pci->device_id == id) return chip;
#define CHECK_PCI_END else { printBug("Unkown CUDA device id: 0x%.4X", pci->device_id); return CHIP_UNKNOWN_CUDA; }

/*
 * pci ids were retrieved using https://github.com/pciutils/pciids
 * and parsed using a custom script to take only the relevant
 * NVIDIA ids. GPUCHIPS (CHIP_XXXX) were retrieved with the same
 * methodology. Both should be updated each time NVIDIA releases
 * new GPUs (or if there is some missing id, either in gpufetch
 * or in pci.ids itself)
 */

GPUCHIP get_chip_from_pci_cuda(struct pci* pci) {
  CHECK_PCI_START
  CHECK_PCI(pci, 0x25e5, CHIP_GA107BM)
  CHECK_PCI(pci, 0x25e2, CHIP_GA107BM)
  CHECK_PCI(pci, 0x25e0, CHIP_GA107BM)
  CHECK_PCI(pci, 0x25b8, CHIP_GA107GLM)
  CHECK_PCI(pci, 0x25b5, CHIP_GA107GLM)
  CHECK_PCI(pci, 0x25af, CHIP_GA107)
  CHECK_PCI(pci, 0x25a5, CHIP_GA107M)
  CHECK_PCI(pci, 0x25a4, CHIP_GA107)
  CHECK_PCI(pci, 0x25a2, CHIP_GA107M)
  CHECK_PCI(pci, 0x25a0, CHIP_GA107M)
  CHECK_PCI(pci, 0x2583, CHIP_GA107)
  CHECK_PCI(pci, 0x2563, CHIP_GA106M)
  CHECK_PCI(pci, 0x2560, CHIP_GA106M)
  CHECK_PCI(pci, 0x252f, CHIP_GA106)
  CHECK_PCI(pci, 0x2523, CHIP_GA106M)
  CHECK_PCI(pci, 0x2520, CHIP_GA106M)
  CHECK_PCI(pci, 0x2505, CHIP_GA106)
  CHECK_PCI(pci, 0x2504, CHIP_GA106)
  CHECK_PCI(pci, 0x2503, CHIP_GA106)
  CHECK_PCI(pci, 0x2501, CHIP_GA106)
  CHECK_PCI(pci, 0x24dd, CHIP_GA104M)
  CHECK_PCI(pci, 0x24dc, CHIP_GA104M)
  CHECK_PCI(pci, 0x24bf, CHIP_GA104)
  CHECK_PCI(pci, 0x24b8, CHIP_GA104GLM)
  CHECK_PCI(pci, 0x24b7, CHIP_GA104GLM)
  CHECK_PCI(pci, 0x24b6, CHIP_GA104GLM)
  CHECK_PCI(pci, 0x24b0, CHIP_GA104GL)
  CHECK_PCI(pci, 0x24af, CHIP_GA104)
  CHECK_PCI(pci, 0x24ad, CHIP_GA104)
  CHECK_PCI(pci, 0x24ac, CHIP_GA104)
  CHECK_PCI(pci, 0x249f, CHIP_GA104M)
  CHECK_PCI(pci, 0x249d, CHIP_GA104M)
  CHECK_PCI(pci, 0x249c, CHIP_GA104M)
  CHECK_PCI(pci, 0x248a, CHIP_GA104)
  CHECK_PCI(pci, 0x2489, CHIP_GA104)
  CHECK_PCI(pci, 0x2488, CHIP_GA104)
  CHECK_PCI(pci, 0x2486, CHIP_GA104)
  CHECK_PCI(pci, 0x2484, CHIP_GA104)
  CHECK_PCI(pci, 0x2483, CHIP_GA104)
  CHECK_PCI(pci, 0x2482, CHIP_GA104)
  CHECK_PCI(pci, 0x228b, CHIP_GA104)
  CHECK_PCI(pci, 0x223f, CHIP_GA102GL)
  CHECK_PCI(pci, 0x2237, CHIP_GA102GL)
  CHECK_PCI(pci, 0x2236, CHIP_GA102GL)
  CHECK_PCI(pci, 0x2235, CHIP_GA102GL)
  CHECK_PCI(pci, 0x2231, CHIP_GA102GL)
  CHECK_PCI(pci, 0x2230, CHIP_GA102GL)
  CHECK_PCI(pci, 0x222f, CHIP_GA102)
  CHECK_PCI(pci, 0x222b, CHIP_GA102)
  CHECK_PCI(pci, 0x2216, CHIP_GA102)
  CHECK_PCI(pci, 0x220d, CHIP_GA102)
  CHECK_PCI(pci, 0x2208, CHIP_GA102)
  CHECK_PCI(pci, 0x2206, CHIP_GA102)
  CHECK_PCI(pci, 0x2205, CHIP_GA102)
  CHECK_PCI(pci, 0x2204, CHIP_GA102)
  CHECK_PCI(pci, 0x2200, CHIP_GA102)
  CHECK_PCI(pci, 0x21d1, CHIP_TU116BM)
  CHECK_PCI(pci, 0x21c4, CHIP_TU116)
  CHECK_PCI(pci, 0x21c2, CHIP_TU116)
  CHECK_PCI(pci, 0x21bf, CHIP_TU116GL)
  CHECK_PCI(pci, 0x21ae, CHIP_TU116GL)
  CHECK_PCI(pci, 0x2192, CHIP_TU116M)
  CHECK_PCI(pci, 0x2191, CHIP_TU116M)
  CHECK_PCI(pci, 0x2189, CHIP_TU116)
  CHECK_PCI(pci, 0x2188, CHIP_TU116)
  CHECK_PCI(pci, 0x2187, CHIP_TU116)
  CHECK_PCI(pci, 0x2184, CHIP_TU116)
  CHECK_PCI(pci, 0x2183, CHIP_TU116)
  CHECK_PCI(pci, 0x2182, CHIP_TU116)
  CHECK_PCI(pci, 0x20f1, CHIP_GA100)
  CHECK_PCI(pci, 0x20bf, CHIP_GA100)
  CHECK_PCI(pci, 0x20be, CHIP_GA100)
  CHECK_PCI(pci, 0x20b7, CHIP_GA100GL)
  CHECK_PCI(pci, 0x20b6, CHIP_GA100GL)
  CHECK_PCI(pci, 0x20b5, CHIP_GA100)
  CHECK_PCI(pci, 0x20b2, CHIP_GA100)
  CHECK_PCI(pci, 0x20b1, CHIP_GA100)
  CHECK_PCI(pci, 0x20b0, CHIP_GA100)
  CHECK_PCI(pci, 0x1ff9, CHIP_TU117GLM)
  CHECK_PCI(pci, 0x1fdd, CHIP_TU117BM)
  CHECK_PCI(pci, 0x1fd9, CHIP_TU117BM)
  CHECK_PCI(pci, 0x1fbf, CHIP_TU117GL)
  CHECK_PCI(pci, 0x1fbb, CHIP_TU117GLM)
  CHECK_PCI(pci, 0x1fba, CHIP_TU117GLM)
  CHECK_PCI(pci, 0x1fb9, CHIP_TU117GLM)
  CHECK_PCI(pci, 0x1fb8, CHIP_TU117GLM)
  CHECK_PCI(pci, 0x1fb2, CHIP_TU117GLM)
  CHECK_PCI(pci, 0x1fb1, CHIP_TU117GL)
  CHECK_PCI(pci, 0x1fb0, CHIP_TU117GLM)
  CHECK_PCI(pci, 0x1fae, CHIP_TU117GL)
  CHECK_PCI(pci, 0x1f9d, CHIP_TU117M)
  CHECK_PCI(pci, 0x1f9c, CHIP_TU117M)
  CHECK_PCI(pci, 0x1f99, CHIP_TU117M)
  CHECK_PCI(pci, 0x1f98, CHIP_TU117M)
  CHECK_PCI(pci, 0x1f97, CHIP_TU117M)
  CHECK_PCI(pci, 0x1f96, CHIP_TU117M)
  CHECK_PCI(pci, 0x1f95, CHIP_TU117M)
  CHECK_PCI(pci, 0x1f94, CHIP_TU117M)
  CHECK_PCI(pci, 0x1f92, CHIP_TU117M)
  CHECK_PCI(pci, 0x1f91, CHIP_TU117M)
  CHECK_PCI(pci, 0x1f82, CHIP_TU117)
  CHECK_PCI(pci, 0x1f81, CHIP_TU117)
  CHECK_PCI(pci, 0x1f76, CHIP_TU106GLM)
  CHECK_PCI(pci, 0x1f55, CHIP_TU106BM)
  CHECK_PCI(pci, 0x1f54, CHIP_TU106BM)
  CHECK_PCI(pci, 0x1f51, CHIP_TU106BM)
  CHECK_PCI(pci, 0x1f50, CHIP_TU106BM)
  CHECK_PCI(pci, 0x1f47, CHIP_TU106)
  CHECK_PCI(pci, 0x1f42, CHIP_TU106)
  CHECK_PCI(pci, 0x1f36, CHIP_TU106GLM)
  CHECK_PCI(pci, 0x1f2e, CHIP_TU106M)
  CHECK_PCI(pci, 0x1f15, CHIP_TU106M)
  CHECK_PCI(pci, 0x1f14, CHIP_TU106M)
  CHECK_PCI(pci, 0x1f12, CHIP_TU106M)
  CHECK_PCI(pci, 0x1f11, CHIP_TU106M)
  CHECK_PCI(pci, 0x1f10, CHIP_TU106M)
  CHECK_PCI(pci, 0x1f0b, CHIP_TU106)
  CHECK_PCI(pci, 0x1f0a, CHIP_TU106)
  CHECK_PCI(pci, 0x1f09, CHIP_TU106)
  CHECK_PCI(pci, 0x1f08, CHIP_TU106)
  CHECK_PCI(pci, 0x1f07, CHIP_TU106)
  CHECK_PCI(pci, 0x1f06, CHIP_TU106)
  CHECK_PCI(pci, 0x1f04, CHIP_TU106)
  CHECK_PCI(pci, 0x1f02, CHIP_TU106)
  CHECK_PCI(pci, 0x1ef5, CHIP_TU104GLM)
  CHECK_PCI(pci, 0x1ed3, CHIP_TU104BM)
  CHECK_PCI(pci, 0x1ed1, CHIP_TU104BM)
  CHECK_PCI(pci, 0x1ed0, CHIP_TU104BM)
  CHECK_PCI(pci, 0x1ec7, CHIP_TU104)
  CHECK_PCI(pci, 0x1ec2, CHIP_TU104)
  CHECK_PCI(pci, 0x1ebe, CHIP_TU104GL)
  CHECK_PCI(pci, 0x1eb9, CHIP_TU104GL)
  CHECK_PCI(pci, 0x1eb8, CHIP_TU104GL)
  CHECK_PCI(pci, 0x1eb6, CHIP_TU104GLM)
  CHECK_PCI(pci, 0x1eb5, CHIP_TU104GLM)
  CHECK_PCI(pci, 0x1eb1, CHIP_TU104GL)
  CHECK_PCI(pci, 0x1eb0, CHIP_TU104GL)
  CHECK_PCI(pci, 0x1eae, CHIP_TU104M)
  CHECK_PCI(pci, 0x1eab, CHIP_TU104M)
  CHECK_PCI(pci, 0x1e93, CHIP_TU104M)
  CHECK_PCI(pci, 0x1e91, CHIP_TU104M)
  CHECK_PCI(pci, 0x1e90, CHIP_TU104M)
  CHECK_PCI(pci, 0x1e89, CHIP_TU104)
  CHECK_PCI(pci, 0x1e87, CHIP_TU104)
  CHECK_PCI(pci, 0x1e84, CHIP_TU104)
  CHECK_PCI(pci, 0x1e82, CHIP_TU104)
  CHECK_PCI(pci, 0x1e81, CHIP_TU104)
  CHECK_PCI(pci, 0x1e78, CHIP_TU102GL)
  CHECK_PCI(pci, 0x1e3e, CHIP_TU102GL)
  CHECK_PCI(pci, 0x1e3d, CHIP_TU102GL)
  CHECK_PCI(pci, 0x1e3c, CHIP_TU102GL)
  CHECK_PCI(pci, 0x1e38, CHIP_TU102GL)
  CHECK_PCI(pci, 0x1e37, CHIP_TU102GL)
  CHECK_PCI(pci, 0x1e36, CHIP_TU102GL)
  CHECK_PCI(pci, 0x1e30, CHIP_TU102GL)
  CHECK_PCI(pci, 0x1e2e, CHIP_TU102)
  CHECK_PCI(pci, 0x1e2d, CHIP_TU102)
  CHECK_PCI(pci, 0x1e09, CHIP_TU102)
  CHECK_PCI(pci, 0x1e07, CHIP_TU102)
  CHECK_PCI(pci, 0x1e04, CHIP_TU102)
  CHECK_PCI(pci, 0x1e02, CHIP_TU102)
  CHECK_PCI(pci, 0x1df6, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1df5, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1df2, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1df0, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1dba, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1db8, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1db7, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1db6, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1db5, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1db4, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1db3, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1db2, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1db1, CHIP_GV100GL)
  CHECK_PCI(pci, 0x1d81, CHIP_GV100)
  CHECK_PCI(pci, 0x1d56, CHIP_GP108BM)
  CHECK_PCI(pci, 0x1d52, CHIP_GP108BM)
  CHECK_PCI(pci, 0x1d34, CHIP_GP108GLM)
  CHECK_PCI(pci, 0x1d33, CHIP_GP108GLM)
  CHECK_PCI(pci, 0x1d16, CHIP_GP108M)
  CHECK_PCI(pci, 0x1d13, CHIP_GP108M)
  CHECK_PCI(pci, 0x1d12, CHIP_GP108M)
  CHECK_PCI(pci, 0x1d11, CHIP_GP108M)
  CHECK_PCI(pci, 0x1d10, CHIP_GP108M)
  CHECK_PCI(pci, 0x1d01, CHIP_GP108)
  CHECK_PCI(pci, 0x1cfb, CHIP_GP107GL)
  CHECK_PCI(pci, 0x1cfa, CHIP_GP107GL)
  CHECK_PCI(pci, 0x1ccd, CHIP_GP107BM)
  CHECK_PCI(pci, 0x1ccc, CHIP_GP107BM)
  CHECK_PCI(pci, 0x1cbd, CHIP_GP107GLM)
  CHECK_PCI(pci, 0x1cbc, CHIP_GP107GLM)
  CHECK_PCI(pci, 0x1cbb, CHIP_GP107GLM)
  CHECK_PCI(pci, 0x1cba, CHIP_GP107GLM)
  CHECK_PCI(pci, 0x1cb6, CHIP_GP107GL)
  CHECK_PCI(pci, 0x1cb3, CHIP_GP107GL)
  CHECK_PCI(pci, 0x1cb2, CHIP_GP107GL)
  CHECK_PCI(pci, 0x1cb1, CHIP_GP107GL)
  CHECK_PCI(pci, 0x1caa, CHIP_GP107GL)
  CHECK_PCI(pci, 0x1ca8, CHIP_GP107GL)
  CHECK_PCI(pci, 0x1ca7, CHIP_GP107GL)
  CHECK_PCI(pci, 0x1c96, CHIP_GP107M)
  CHECK_PCI(pci, 0x1c94, CHIP_GP107M)
  CHECK_PCI(pci, 0x1c92, CHIP_GP107M)
  CHECK_PCI(pci, 0x1c91, CHIP_GP107M)
  CHECK_PCI(pci, 0x1c90, CHIP_GP107M)
  CHECK_PCI(pci, 0x1c8f, CHIP_GP107M)
  CHECK_PCI(pci, 0x1c8e, CHIP_GP107M)
  CHECK_PCI(pci, 0x1c8d, CHIP_GP107M)
  CHECK_PCI(pci, 0x1c8c, CHIP_GP107M)
  CHECK_PCI(pci, 0x1c83, CHIP_GP107)
  CHECK_PCI(pci, 0x1c82, CHIP_GP107)
  CHECK_PCI(pci, 0x1c81, CHIP_GP107)
  CHECK_PCI(pci, 0x1c70, CHIP_GP106GL)
  CHECK_PCI(pci, 0x1c62, CHIP_GP106BM)
  CHECK_PCI(pci, 0x1c61, CHIP_GP106BM)
  CHECK_PCI(pci, 0x1c60, CHIP_GP106BM)
  CHECK_PCI(pci, 0x1c36, CHIP_GP106)
  CHECK_PCI(pci, 0x1c35, CHIP_GP106M)
  CHECK_PCI(pci, 0x1c31, CHIP_GP106GL)
  CHECK_PCI(pci, 0x1c30, CHIP_GP106GL)
  CHECK_PCI(pci, 0x1c2d, CHIP_GP106M)
  CHECK_PCI(pci, 0x1c23, CHIP_GP106M)
  CHECK_PCI(pci, 0x1c22, CHIP_GP106M)
  CHECK_PCI(pci, 0x1c21, CHIP_GP106M)
  CHECK_PCI(pci, 0x1c20, CHIP_GP106M)
  CHECK_PCI(pci, 0x1c09, CHIP_GP106)
  CHECK_PCI(pci, 0x1c07, CHIP_GP106)
  CHECK_PCI(pci, 0x1c06, CHIP_GP106)
  CHECK_PCI(pci, 0x1c04, CHIP_GP106)
  CHECK_PCI(pci, 0x1c03, CHIP_GP106)
  CHECK_PCI(pci, 0x1c02, CHIP_GP106)
  CHECK_PCI(pci, 0x1c01, CHIP_GP106)
  CHECK_PCI(pci, 0x1c00, CHIP_GP106)
  CHECK_PCI(pci, 0x1be1, CHIP_GP104BM)
  CHECK_PCI(pci, 0x1be0, CHIP_GP104BM)
  CHECK_PCI(pci, 0x1bc7, CHIP_GP104)
  CHECK_PCI(pci, 0x1bbb, CHIP_GP104GLM)
  CHECK_PCI(pci, 0x1bb9, CHIP_GP104GLM)
  CHECK_PCI(pci, 0x1bb8, CHIP_GP104GLM)
  CHECK_PCI(pci, 0x1bb7, CHIP_GP104GLM)
  CHECK_PCI(pci, 0x1bb6, CHIP_GP104GLM)
  CHECK_PCI(pci, 0x1bb5, CHIP_GP104GLM)
  CHECK_PCI(pci, 0x1bb4, CHIP_GP104GL)
  CHECK_PCI(pci, 0x1bb3, CHIP_GP104GL)
  CHECK_PCI(pci, 0x1bb1, CHIP_GP104GL)
  CHECK_PCI(pci, 0x1bb0, CHIP_GP104GL)
  CHECK_PCI(pci, 0x1bad, CHIP_GP104)
  CHECK_PCI(pci, 0x1baa, CHIP_GP104M)
  CHECK_PCI(pci, 0x1ba9, CHIP_GP104M)
  CHECK_PCI(pci, 0x1ba2, CHIP_GP104M)
  CHECK_PCI(pci, 0x1ba1, CHIP_GP104M)
  CHECK_PCI(pci, 0x1ba0, CHIP_GP104M)
  CHECK_PCI(pci, 0x1b87, CHIP_GP104)
  CHECK_PCI(pci, 0x1b84, CHIP_GP104)
  CHECK_PCI(pci, 0x1b83, CHIP_GP104)
  CHECK_PCI(pci, 0x1b82, CHIP_GP104)
  CHECK_PCI(pci, 0x1b81, CHIP_GP104)
  CHECK_PCI(pci, 0x1b80, CHIP_GP104)
  CHECK_PCI(pci, 0x1b78, CHIP_GP102GL)
  CHECK_PCI(pci, 0x1b70, CHIP_GP102GL)
  CHECK_PCI(pci, 0x1b39, CHIP_GP102GL)
  CHECK_PCI(pci, 0x1b38, CHIP_GP102GL)
  CHECK_PCI(pci, 0x1b30, CHIP_GP102GL)
  CHECK_PCI(pci, 0x1b07, CHIP_GP102)
  CHECK_PCI(pci, 0x1b06, CHIP_GP102)
  CHECK_PCI(pci, 0x1b04, CHIP_GP102)
  CHECK_PCI(pci, 0x1b02, CHIP_GP102)
  CHECK_PCI(pci, 0x1b01, CHIP_GP102)
  CHECK_PCI(pci, 0x1b00, CHIP_GP102)
  CHECK_PCI(pci, 0x1aef, CHIP_GA102)
  CHECK_PCI(pci, 0x1aed, CHIP_TU116)
  CHECK_PCI(pci, 0x1aec, CHIP_TU116)
  CHECK_PCI(pci, 0x1aeb, CHIP_TU116)
  CHECK_PCI(pci, 0x1adb, CHIP_TU106)
  CHECK_PCI(pci, 0x1ada, CHIP_TU106)
  CHECK_PCI(pci, 0x1ad9, CHIP_TU104)
  CHECK_PCI(pci, 0x1ad8, CHIP_TU104)
  CHECK_PCI(pci, 0x1ad7, CHIP_TU102)
  CHECK_PCI(pci, 0x1ad6, CHIP_TU102)
  CHECK_PCI(pci, 0x17fd, CHIP_GM200GL)
  CHECK_PCI(pci, 0x17f1, CHIP_GM200GL)
  CHECK_PCI(pci, 0x17f0, CHIP_GM200GL)
  CHECK_PCI(pci, 0x17c8, CHIP_GM200)
  CHECK_PCI(pci, 0x17c2, CHIP_GM200)
  CHECK_PCI(pci, 0x179c, CHIP_GM107)
  CHECK_PCI(pci, 0x1789, CHIP_GM107GL)
  CHECK_PCI(pci, 0x174e, CHIP_GM108M)
  CHECK_PCI(pci, 0x174d, CHIP_GM108M)
  CHECK_PCI(pci, 0x172f, CHIP_GP100)
  CHECK_PCI(pci, 0x172e, CHIP_GP100)
  CHECK_PCI(pci, 0x1725, CHIP_GP100)
  CHECK_PCI(pci, 0x1667, CHIP_GM204M)
  CHECK_PCI(pci, 0x161a, CHIP_GM204M)
  CHECK_PCI(pci, 0x1619, CHIP_GM204M)
  CHECK_PCI(pci, 0x1618, CHIP_GM204M)
  CHECK_PCI(pci, 0x1617, CHIP_GM204M)
  CHECK_PCI(pci, 0x15f9, CHIP_GP100GL)
  CHECK_PCI(pci, 0x15f8, CHIP_GP100GL)
  CHECK_PCI(pci, 0x15f7, CHIP_GP100GL)
  CHECK_PCI(pci, 0x15f1, CHIP_GP100GL)
  CHECK_PCI(pci, 0x15f0, CHIP_GP100GL)
  CHECK_PCI(pci, 0x1436, CHIP_GM206GLM)
  CHECK_PCI(pci, 0x1431, CHIP_GM206GL)
  CHECK_PCI(pci, 0x1430, CHIP_GM206GL)
  CHECK_PCI(pci, 0x1427, CHIP_GM206M)
  CHECK_PCI(pci, 0x1407, CHIP_GM206)
  CHECK_PCI(pci, 0x1406, CHIP_GM206)
  CHECK_PCI(pci, 0x1404, CHIP_GM206)
  CHECK_PCI(pci, 0x1402, CHIP_GM206)
  CHECK_PCI(pci, 0x1401, CHIP_GM206)
  CHECK_PCI(pci, 0x13fb, CHIP_GM204GLM)
  CHECK_PCI(pci, 0x13fa, CHIP_GM204GLM)
  CHECK_PCI(pci, 0x13f9, CHIP_GM204GLM)
  CHECK_PCI(pci, 0x13f8, CHIP_GM204GLM)
  CHECK_PCI(pci, 0x13f3, CHIP_GM204GL)
  CHECK_PCI(pci, 0x13f2, CHIP_GM204GL)
  CHECK_PCI(pci, 0x13f1, CHIP_GM204GL)
  CHECK_PCI(pci, 0x13f0, CHIP_GM204GL)
  CHECK_PCI(pci, 0x13e7, CHIP_GM204GL)
  CHECK_PCI(pci, 0x13da, CHIP_GM204M)
  CHECK_PCI(pci, 0x13d9, CHIP_GM204M)
  CHECK_PCI(pci, 0x13d8, CHIP_GM204M)
  CHECK_PCI(pci, 0x13d7, CHIP_GM204M)
  CHECK_PCI(pci, 0x13c3, CHIP_GM204)
  CHECK_PCI(pci, 0x13c2, CHIP_GM204)
  CHECK_PCI(pci, 0x13c1, CHIP_GM204)
  CHECK_PCI(pci, 0x13c0, CHIP_GM204)
  CHECK_PCI(pci, 0x13bd, CHIP_GM107GL)
  CHECK_PCI(pci, 0x13bc, CHIP_GM107GL)
  CHECK_PCI(pci, 0x13bb, CHIP_GM107GL)
  CHECK_PCI(pci, 0x13ba, CHIP_GM107GL)
  CHECK_PCI(pci, 0x13b9, CHIP_GM107GL)
  CHECK_PCI(pci, 0x13b6, CHIP_GM107GLM)
  CHECK_PCI(pci, 0x13b4, CHIP_GM107GLM)
  CHECK_PCI(pci, 0x13b3, CHIP_GM107GLM)
  CHECK_PCI(pci, 0x13b2, CHIP_GM107GLM)
  CHECK_PCI(pci, 0x13b1, CHIP_GM107GLM)
  CHECK_PCI(pci, 0x13b0, CHIP_GM107GLM)
  CHECK_PCI(pci, 0x139d, CHIP_GM107M)
  CHECK_PCI(pci, 0x139c, CHIP_GM107M)
  CHECK_PCI(pci, 0x139b, CHIP_GM107M)
  CHECK_PCI(pci, 0x139a, CHIP_GM107M)
  CHECK_PCI(pci, 0x1399, CHIP_GM107M)
  CHECK_PCI(pci, 0x1398, CHIP_GM107M)
  CHECK_PCI(pci, 0x1393, CHIP_GM107M)
  CHECK_PCI(pci, 0x1392, CHIP_GM107M)
  CHECK_PCI(pci, 0x1391, CHIP_GM107M)
  CHECK_PCI(pci, 0x1390, CHIP_GM107M)
  CHECK_PCI(pci, 0x1389, CHIP_GM107GL)
  CHECK_PCI(pci, 0x1382, CHIP_GM107)
  CHECK_PCI(pci, 0x1381, CHIP_GM107)
  CHECK_PCI(pci, 0x1380, CHIP_GM107)
  CHECK_PCI(pci, 0x137d, CHIP_GM108M)
  CHECK_PCI(pci, 0x137b, CHIP_GM108GLM)
  CHECK_PCI(pci, 0x137a, CHIP_GM108GLM)
  CHECK_PCI(pci, 0x134f, CHIP_GM108M)
  CHECK_PCI(pci, 0x134e, CHIP_GM108M)
  CHECK_PCI(pci, 0x134d, CHIP_GM108M)
  CHECK_PCI(pci, 0x134b, CHIP_GM108M)
  CHECK_PCI(pci, 0x1349, CHIP_GM108M)
  CHECK_PCI(pci, 0x1348, CHIP_GM108M)
  CHECK_PCI(pci, 0x1347, CHIP_GM108M)
  CHECK_PCI(pci, 0x1346, CHIP_GM108M)
  CHECK_PCI(pci, 0x1344, CHIP_GM108M)
  CHECK_PCI(pci, 0x1341, CHIP_GM108M)
  CHECK_PCI(pci, 0x1340, CHIP_GM108M)
  CHECK_PCI(pci, 0x12ba, CHIP_GK208GLM)
  CHECK_PCI(pci, 0x12b9, CHIP_GK208GLM)
  CHECK_PCI(pci, 0x12a0, CHIP_GK208)
  CHECK_PCI(pci, 0x129a, CHIP_GK208BM)
  CHECK_PCI(pci, 0x1299, CHIP_GK208BM)
  CHECK_PCI(pci, 0x1298, CHIP_GK208M)
  CHECK_PCI(pci, 0x1296, CHIP_GK208M)
  CHECK_PCI(pci, 0x1295, CHIP_GK208M)
  CHECK_PCI(pci, 0x1294, CHIP_GK208M)
  CHECK_PCI(pci, 0x1293, CHIP_GK208M)
  CHECK_PCI(pci, 0x1292, CHIP_GK208M)
  CHECK_PCI(pci, 0x1291, CHIP_GK208M)
  CHECK_PCI(pci, 0x1290, CHIP_GK208M)
  CHECK_PCI(pci, 0x128c, CHIP_GK208B)
  CHECK_PCI(pci, 0x128b, CHIP_GK208B)
  CHECK_PCI(pci, 0x128a, CHIP_GK208B)
  CHECK_PCI(pci, 0x1289, CHIP_GK208)
  CHECK_PCI(pci, 0x1288, CHIP_GK208B)
  CHECK_PCI(pci, 0x1287, CHIP_GK208B)
  CHECK_PCI(pci, 0x1286, CHIP_GK208)
  CHECK_PCI(pci, 0x1284, CHIP_GK208)
  CHECK_PCI(pci, 0x1282, CHIP_GK208)
  CHECK_PCI(pci, 0x1281, CHIP_GK208)
  CHECK_PCI(pci, 0x1280, CHIP_GK208)
  CHECK_PCI(pci, 0x1251, CHIP_GF116M)
  CHECK_PCI(pci, 0x124d, CHIP_GF116M)
  CHECK_PCI(pci, 0x124b, CHIP_GF116)
  CHECK_PCI(pci, 0x1249, CHIP_GF116)
  CHECK_PCI(pci, 0x1248, CHIP_GF116M)
  CHECK_PCI(pci, 0x1247, CHIP_GF116M)
  CHECK_PCI(pci, 0x1246, CHIP_GF116M)
  CHECK_PCI(pci, 0x1245, CHIP_GF116)
  CHECK_PCI(pci, 0x1244, CHIP_GF116)
  CHECK_PCI(pci, 0x1243, CHIP_GF116)
  CHECK_PCI(pci, 0x1241, CHIP_GF116)
  CHECK_PCI(pci, 0x1213, CHIP_GF114M)
  CHECK_PCI(pci, 0x1212, CHIP_GF114M)
  CHECK_PCI(pci, 0x1211, CHIP_GF114M)
  CHECK_PCI(pci, 0x1210, CHIP_GF114M)
  CHECK_PCI(pci, 0x1208, CHIP_GF114)
  CHECK_PCI(pci, 0x1207, CHIP_GF114)
  CHECK_PCI(pci, 0x1206, CHIP_GF114)
  CHECK_PCI(pci, 0x1205, CHIP_GF114)
  CHECK_PCI(pci, 0x1203, CHIP_GF114)
  CHECK_PCI(pci, 0x1202, CHIP_GF114)
  CHECK_PCI(pci, 0x1201, CHIP_GF114)
  CHECK_PCI(pci, 0x1200, CHIP_GF114)
  CHECK_PCI(pci, 0x11fc, CHIP_GK106GLM)
  CHECK_PCI(pci, 0x11fa, CHIP_GK106GL)
  CHECK_PCI(pci, 0x11e7, CHIP_GK106M)
  CHECK_PCI(pci, 0x11e3, CHIP_GK106M)
  CHECK_PCI(pci, 0x11e2, CHIP_GK106M)
  CHECK_PCI(pci, 0x11e1, CHIP_GK106M)
  CHECK_PCI(pci, 0x11e0, CHIP_GK106M)
  CHECK_PCI(pci, 0x11cb, CHIP_GK106)
  CHECK_PCI(pci, 0x11c8, CHIP_GK106)
  CHECK_PCI(pci, 0x11c7, CHIP_GK106)
  CHECK_PCI(pci, 0x11c6, CHIP_GK106)
  CHECK_PCI(pci, 0x11c5, CHIP_GK106)
  CHECK_PCI(pci, 0x11c4, CHIP_GK106)
  CHECK_PCI(pci, 0x11c3, CHIP_GK106)
  CHECK_PCI(pci, 0x11c2, CHIP_GK106)
  CHECK_PCI(pci, 0x11c0, CHIP_GK106)
  CHECK_PCI(pci, 0x11bf, CHIP_GK104GL)
  CHECK_PCI(pci, 0x11be, CHIP_GK104GLM)
  CHECK_PCI(pci, 0x11bd, CHIP_GK104GLM)
  CHECK_PCI(pci, 0x11bc, CHIP_GK104GLM)
  CHECK_PCI(pci, 0x11bb, CHIP_GK104GL)
  CHECK_PCI(pci, 0x11ba, CHIP_GK104GL)
  CHECK_PCI(pci, 0x11b9, CHIP_GK104GLM)
  CHECK_PCI(pci, 0x11b8, CHIP_GK104GLM)
  CHECK_PCI(pci, 0x11b7, CHIP_GK104GLM)
  CHECK_PCI(pci, 0x11b6, CHIP_GK104GLM)
  CHECK_PCI(pci, 0x11b4, CHIP_GK104GL)
  CHECK_PCI(pci, 0x11b1, CHIP_GK104GL)
  CHECK_PCI(pci, 0x11b0, CHIP_GK104GL)
  CHECK_PCI(pci, 0x11af, CHIP_GK104GLM)
  CHECK_PCI(pci, 0x11a9, CHIP_GK104M)
  CHECK_PCI(pci, 0x11a7, CHIP_GK104M)
  CHECK_PCI(pci, 0x11a3, CHIP_GK104M)
  CHECK_PCI(pci, 0x11a2, CHIP_GK104M)
  CHECK_PCI(pci, 0x11a1, CHIP_GK104M)
  CHECK_PCI(pci, 0x11a0, CHIP_GK104M)
  CHECK_PCI(pci, 0x119f, CHIP_GK104M)
  CHECK_PCI(pci, 0x119e, CHIP_GK104M)
  CHECK_PCI(pci, 0x119d, CHIP_GK104M)
  CHECK_PCI(pci, 0x119a, CHIP_GK104M)
  CHECK_PCI(pci, 0x1199, CHIP_GK104M)
  CHECK_PCI(pci, 0x1198, CHIP_GK104M)
  CHECK_PCI(pci, 0x1195, CHIP_GK104)
  CHECK_PCI(pci, 0x1194, CHIP_GK104GL)
  CHECK_PCI(pci, 0x1193, CHIP_GK104)
  CHECK_PCI(pci, 0x1191, CHIP_GK104)
  CHECK_PCI(pci, 0x118f, CHIP_GK104GL)
  CHECK_PCI(pci, 0x118e, CHIP_GK104)
  CHECK_PCI(pci, 0x118d, CHIP_GK104GL)
  CHECK_PCI(pci, 0x118c, CHIP_GK104)
  CHECK_PCI(pci, 0x118b, CHIP_GK104GL)
  CHECK_PCI(pci, 0x118a, CHIP_GK104GL)
  CHECK_PCI(pci, 0x1189, CHIP_GK104)
  CHECK_PCI(pci, 0x1188, CHIP_GK104)
  CHECK_PCI(pci, 0x1187, CHIP_GK104)
  CHECK_PCI(pci, 0x1186, CHIP_GK104)
  CHECK_PCI(pci, 0x1185, CHIP_GK104)
  CHECK_PCI(pci, 0x1184, CHIP_GK104)
  CHECK_PCI(pci, 0x1183, CHIP_GK104)
  CHECK_PCI(pci, 0x1182, CHIP_GK104)
  CHECK_PCI(pci, 0x1180, CHIP_GK104)
  CHECK_PCI(pci, 0x1140, CHIP_GF117M)
  CHECK_PCI(pci, 0x10f9, CHIP_TU106)
  CHECK_PCI(pci, 0x10f8, CHIP_TU104)
  CHECK_PCI(pci, 0x10f7, CHIP_TU102)
  CHECK_PCI(pci, 0x10f1, CHIP_GP106)
  CHECK_PCI(pci, 0x10f0, CHIP_GP104)
  CHECK_PCI(pci, 0x10ef, CHIP_GP102)
  CHECK_PCI(pci, 0x10d8, CHIP_GT218)
  CHECK_PCI(pci, 0x10c5, CHIP_GT218)
  CHECK_PCI(pci, 0x10c3, CHIP_GT218)
  CHECK_PCI(pci, 0x10c0, CHIP_GT218)
  CHECK_PCI(pci, 0x109b, CHIP_GF100GL)
  CHECK_PCI(pci, 0x109a, CHIP_GF100GLM)
  CHECK_PCI(pci, 0x1096, CHIP_GF110GL)
  CHECK_PCI(pci, 0x1094, CHIP_GF110GL)
  CHECK_PCI(pci, 0x1091, CHIP_GF110GL)
  CHECK_PCI(pci, 0x108e, CHIP_GF110GL)
  CHECK_PCI(pci, 0x108b, CHIP_GF110)
  CHECK_PCI(pci, 0x1089, CHIP_GF110)
  CHECK_PCI(pci, 0x1088, CHIP_GF110)
  CHECK_PCI(pci, 0x1087, CHIP_GF110)
  CHECK_PCI(pci, 0x1086, CHIP_GF110)
  CHECK_PCI(pci, 0x1084, CHIP_GF110)
  CHECK_PCI(pci, 0x1082, CHIP_GF110)
  CHECK_PCI(pci, 0x1081, CHIP_GF110)
  CHECK_PCI(pci, 0x1080, CHIP_GF110)
  CHECK_PCI(pci, 0x107d, CHIP_GF119)
  CHECK_PCI(pci, 0x107c, CHIP_GF119)
  CHECK_PCI(pci, 0x105b, CHIP_GF119M)
  CHECK_PCI(pci, 0x105a, CHIP_GF119M)
  CHECK_PCI(pci, 0x1059, CHIP_GF119M)
  CHECK_PCI(pci, 0x1058, CHIP_GF119M)
  CHECK_PCI(pci, 0x1057, CHIP_GF119M)
  CHECK_PCI(pci, 0x1056, CHIP_GF119M)
  CHECK_PCI(pci, 0x1055, CHIP_GF119M)
  CHECK_PCI(pci, 0x1054, CHIP_GF119M)
  CHECK_PCI(pci, 0x1052, CHIP_GF119M)
  CHECK_PCI(pci, 0x1051, CHIP_GF119M)
  CHECK_PCI(pci, 0x1050, CHIP_GF119M)
  CHECK_PCI(pci, 0x104d, CHIP_GF119)
  CHECK_PCI(pci, 0x104c, CHIP_GF119)
  CHECK_PCI(pci, 0x104b, CHIP_GF119)
  CHECK_PCI(pci, 0x104a, CHIP_GF119)
  CHECK_PCI(pci, 0x1049, CHIP_GF119)
  CHECK_PCI(pci, 0x1048, CHIP_GF119)
  CHECK_PCI(pci, 0x1045, CHIP_GF119)
  CHECK_PCI(pci, 0x1042, CHIP_GF119)
  CHECK_PCI(pci, 0x1040, CHIP_GF119)
  CHECK_PCI(pci, 0x103f, CHIP_GK110BGL)
  CHECK_PCI(pci, 0x103c, CHIP_GK110GL)
  CHECK_PCI(pci, 0x103a, CHIP_GK110GL)
  CHECK_PCI(pci, 0x102f, CHIP_GK110BGL)
  CHECK_PCI(pci, 0x102e, CHIP_GK110BGL)
  CHECK_PCI(pci, 0x102d, CHIP_GK210GL)
  CHECK_PCI(pci, 0x102a, CHIP_GK110BGL)
  CHECK_PCI(pci, 0x1029, CHIP_GK110BGL)
  CHECK_PCI(pci, 0x1028, CHIP_GK110GL)
  CHECK_PCI(pci, 0x1027, CHIP_GK110BGL)
  CHECK_PCI(pci, 0x1026, CHIP_GK110GL)
  CHECK_PCI(pci, 0x1023, CHIP_GK110BGL)
  CHECK_PCI(pci, 0x1022, CHIP_GK110GL)
  CHECK_PCI(pci, 0x1021, CHIP_GK110GL)
  CHECK_PCI(pci, 0x1020, CHIP_GK110GL)
  CHECK_PCI(pci, 0x101f, CHIP_GK110GL)
  CHECK_PCI(pci, 0x101e, CHIP_GK110GL)
  CHECK_PCI(pci, 0x100c, CHIP_GK110B)
  CHECK_PCI(pci, 0x100a, CHIP_GK110B)
  CHECK_PCI(pci, 0x1008, CHIP_GK110)
  CHECK_PCI(pci, 0x1007, CHIP_GK110)
  CHECK_PCI(pci, 0x1005, CHIP_GK110)
  CHECK_PCI(pci, 0x1004, CHIP_GK110)
  CHECK_PCI(pci, 0x1003, CHIP_GK110)
  CHECK_PCI(pci, 0x1001, CHIP_GK110B)
  CHECK_PCI(pci, 0x0fff, CHIP_GK107GL)
  CHECK_PCI(pci, 0x0ffe, CHIP_GK107GL)
  CHECK_PCI(pci, 0x0ffd, CHIP_GK107)
  CHECK_PCI(pci, 0x0ffc, CHIP_GK107GLM)
  CHECK_PCI(pci, 0x0ffb, CHIP_GK107GLM)
  CHECK_PCI(pci, 0x0ffa, CHIP_GK107GL)
  CHECK_PCI(pci, 0x0ff9, CHIP_GK107GL)
  CHECK_PCI(pci, 0x0ff8, CHIP_GK107GLM)
  CHECK_PCI(pci, 0x0ff7, CHIP_GK107GL)
  CHECK_PCI(pci, 0x0ff6, CHIP_GK107GLM)
  CHECK_PCI(pci, 0x0ff5, CHIP_GK107GL)
  CHECK_PCI(pci, 0x0ff3, CHIP_GK107GL)
  CHECK_PCI(pci, 0x0ff2, CHIP_GK107GL)
  CHECK_PCI(pci, 0x0ff1, CHIP_GK107)
  CHECK_PCI(pci, 0x0fef, CHIP_GK107GL)
  CHECK_PCI(pci, 0x0fee, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fed, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fec, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fea, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fe9, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fe8, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fe7, CHIP_GK107GL)
  CHECK_PCI(pci, 0x0fe6, CHIP_GK107)
  CHECK_PCI(pci, 0x0fe5, CHIP_GK107)
  CHECK_PCI(pci, 0x0fe4, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fe3, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fe2, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fe1, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fe0, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fdf, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fdb, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fd9, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fd8, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fd6, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fd5, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fd4, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fd3, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fd2, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fd1, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fce, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fcd, CHIP_GK107M)
  CHECK_PCI(pci, 0x0fc9, CHIP_GK107)
  CHECK_PCI(pci, 0x0fc8, CHIP_GK107)
  CHECK_PCI(pci, 0x0fc6, CHIP_GK107)
  CHECK_PCI(pci, 0x0fc5, CHIP_GK107)
  CHECK_PCI(pci, 0x0fc2, CHIP_GK107)
  CHECK_PCI(pci, 0x0fc1, CHIP_GK107)
  CHECK_PCI(pci, 0x0fc0, CHIP_GK107)
  CHECK_PCI(pci, 0x0fbc, CHIP_GM107)
  CHECK_PCI(pci, 0x0fbb, CHIP_GM204)
  CHECK_PCI(pci, 0x0fba, CHIP_GM206)
  CHECK_PCI(pci, 0x0fb9, CHIP_GP107GL)
  CHECK_PCI(pci, 0x0fb8, CHIP_GP108)
  CHECK_PCI(pci, 0x0fb0, CHIP_GM200)
  CHECK_PCI(pci, 0x0f06, CHIP_GF108)
  CHECK_PCI(pci, 0x0f03, CHIP_GF108)
  CHECK_PCI(pci, 0x0f02, CHIP_GF108)
  CHECK_PCI(pci, 0x0f01, CHIP_GF108)
  CHECK_PCI(pci, 0x0f00, CHIP_GF108)
  CHECK_PCI(pci, 0x0e3b, CHIP_GF104GLM)
  CHECK_PCI(pci, 0x0e3a, CHIP_GF104GLM)
  CHECK_PCI(pci, 0x0e31, CHIP_GF104M)
  CHECK_PCI(pci, 0x0e30, CHIP_GF104M)
  CHECK_PCI(pci, 0x0e24, CHIP_GF104)
  CHECK_PCI(pci, 0x0e23, CHIP_GF104)
  CHECK_PCI(pci, 0x0e22, CHIP_GF104)
  CHECK_PCI(pci, 0x0e1b, CHIP_GK107)
  CHECK_PCI(pci, 0x0e1a, CHIP_GK110)
  CHECK_PCI(pci, 0x0e0f, CHIP_GK208)
  CHECK_PCI(pci, 0x0e0c, CHIP_GF114)
  CHECK_PCI(pci, 0x0e0b, CHIP_GK106)
  CHECK_PCI(pci, 0x0e0a, CHIP_GK104)
  CHECK_PCI(pci, 0x0e09, CHIP_GF110)
  CHECK_PCI(pci, 0x0e08, CHIP_GF119)
  CHECK_PCI(pci, 0x0dfc, CHIP_GF108GLM)
  CHECK_PCI(pci, 0x0dfa, CHIP_GF108GLM)
  CHECK_PCI(pci, 0x0df9, CHIP_GF108GLM)
  CHECK_PCI(pci, 0x0df8, CHIP_GF108GL)
  CHECK_PCI(pci, 0x0df7, CHIP_GF108M)
  CHECK_PCI(pci, 0x0df6, CHIP_GF108M)
  CHECK_PCI(pci, 0x0df5, CHIP_GF108M)
  CHECK_PCI(pci, 0x0df4, CHIP_GF108M)
  CHECK_PCI(pci, 0x0df3, CHIP_GF108M)
  CHECK_PCI(pci, 0x0df2, CHIP_GF108M)
  CHECK_PCI(pci, 0x0df1, CHIP_GF108M)
  CHECK_PCI(pci, 0x0df0, CHIP_GF108M)
  CHECK_PCI(pci, 0x0def, CHIP_GF108M)
  CHECK_PCI(pci, 0x0dee, CHIP_GF108M)
  CHECK_PCI(pci, 0x0ded, CHIP_GF108M)
  CHECK_PCI(pci, 0x0dec, CHIP_GF108M)
  CHECK_PCI(pci, 0x0deb, CHIP_GF108M)
  CHECK_PCI(pci, 0x0dea, CHIP_GF108M)
  CHECK_PCI(pci, 0x0de9, CHIP_GF108M)
  CHECK_PCI(pci, 0x0de8, CHIP_GF108M)
  CHECK_PCI(pci, 0x0de7, CHIP_GF108)
  CHECK_PCI(pci, 0x0de5, CHIP_GF108)
  CHECK_PCI(pci, 0x0de4, CHIP_GF108)
  CHECK_PCI(pci, 0x0de3, CHIP_GF108M)
  CHECK_PCI(pci, 0x0de2, CHIP_GF108)
  CHECK_PCI(pci, 0x0de1, CHIP_GF108)
  CHECK_PCI(pci, 0x0de0, CHIP_GF108)
  CHECK_PCI(pci, 0x0dda, CHIP_GF106GLM)
  CHECK_PCI(pci, 0x0dd8, CHIP_GF106GL)
  CHECK_PCI(pci, 0x0dd6, CHIP_GF106M)
  CHECK_PCI(pci, 0x0dd3, CHIP_GF106M)
  CHECK_PCI(pci, 0x0dd2, CHIP_GF106M)
  CHECK_PCI(pci, 0x0dd1, CHIP_GF106M)
  CHECK_PCI(pci, 0x0dce, CHIP_GF106M)
  CHECK_PCI(pci, 0x0dcd, CHIP_GF106M)
  CHECK_PCI(pci, 0x0dc6, CHIP_GF106)
  CHECK_PCI(pci, 0x0dc5, CHIP_GF106)
  CHECK_PCI(pci, 0x0dc4, CHIP_GF106)
  CHECK_PCI(pci, 0x0dc0, CHIP_GF106)
  CHECK_PCI(pci, 0x0cbc, CHIP_GT215GLM)
  CHECK_PCI(pci, 0x0cb1, CHIP_GT215M)
  CHECK_PCI(pci, 0x0cb0, CHIP_GT215M)
  CHECK_PCI(pci, 0x0caf, CHIP_GT215M)
  CHECK_PCI(pci, 0x0cac, CHIP_GT215)
  CHECK_PCI(pci, 0x0ca9, CHIP_GT215M)
  CHECK_PCI(pci, 0x0ca8, CHIP_GT215M)
  CHECK_PCI(pci, 0x0ca7, CHIP_GT215)
  CHECK_PCI(pci, 0x0ca5, CHIP_GT215)
  CHECK_PCI(pci, 0x0ca4, CHIP_GT215)
  CHECK_PCI(pci, 0x0ca3, CHIP_GT215)
  CHECK_PCI(pci, 0x0ca2, CHIP_GT215)
  CHECK_PCI(pci, 0x0ca0, CHIP_GT215)
  CHECK_PCI(pci, 0x0bee, CHIP_GF116)
  CHECK_PCI(pci, 0x0beb, CHIP_GF104)
  CHECK_PCI(pci, 0x0bea, CHIP_GF108)
  CHECK_PCI(pci, 0x0be9, CHIP_GF106)
  CHECK_PCI(pci, 0x0be5, CHIP_GF100)
  CHECK_PCI(pci, 0x0be2, CHIP_GT216)
  CHECK_PCI(pci, 0x0a7c, CHIP_GT218GLM)
  CHECK_PCI(pci, 0x0a7b, CHIP_GT218)
  CHECK_PCI(pci, 0x0a7a, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a78, CHIP_GT218GL)
  CHECK_PCI(pci, 0x0a76, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a75, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a74, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a73, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a72, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a71, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a70, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a6f, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a6e, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a6c, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a6a, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a69, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a68, CHIP_GT218M)
  CHECK_PCI(pci, 0x0a67, CHIP_GT218)
  CHECK_PCI(pci, 0x0a66, CHIP_GT218)
  CHECK_PCI(pci, 0x0a65, CHIP_GT218)
  CHECK_PCI(pci, 0x0a64, CHIP_GT218)
  CHECK_PCI(pci, 0x0a63, CHIP_GT218)
  CHECK_PCI(pci, 0x0a62, CHIP_GT218)
  CHECK_PCI(pci, 0x0a60, CHIP_GT218)
  CHECK_PCI(pci, 0x0a3c, CHIP_GT216GLM)
  CHECK_PCI(pci, 0x0a38, CHIP_GT216GL)
  CHECK_PCI(pci, 0x0a35, CHIP_GT216M)
  CHECK_PCI(pci, 0x0a34, CHIP_GT216M)
  CHECK_PCI(pci, 0x0a32, CHIP_GT216)
  CHECK_PCI(pci, 0x0a30, CHIP_GT216)
  CHECK_PCI(pci, 0x0a2d, CHIP_GT216M)
  CHECK_PCI(pci, 0x0a2c, CHIP_GT216M)
  CHECK_PCI(pci, 0x0a2b, CHIP_GT216M)
  CHECK_PCI(pci, 0x0a2a, CHIP_GT216M)
  CHECK_PCI(pci, 0x0a29, CHIP_GT216M)
  CHECK_PCI(pci, 0x0a28, CHIP_GT216M)
  CHECK_PCI(pci, 0x0a27, CHIP_GT216)
  CHECK_PCI(pci, 0x0a26, CHIP_GT216)
  CHECK_PCI(pci, 0x0a24, CHIP_GT216)
  CHECK_PCI(pci, 0x0a23, CHIP_GT216)
  CHECK_PCI(pci, 0x0a22, CHIP_GT216)
  CHECK_PCI(pci, 0x0a21, CHIP_GT216M)
  CHECK_PCI(pci, 0x0a20, CHIP_GT216)
  CHECK_PCI(pci, 0x06ff, CHIP_G98)
  CHECK_PCI(pci, 0x06fd, CHIP_G98)
  CHECK_PCI(pci, 0x06fb, CHIP_G98GLM)
  CHECK_PCI(pci, 0x06fa, CHIP_G98)
  CHECK_PCI(pci, 0x06f9, CHIP_G98GL)
  CHECK_PCI(pci, 0x06f8, CHIP_G98)
  CHECK_PCI(pci, 0x06f1, CHIP_G98M)
  CHECK_PCI(pci, 0x06ef, CHIP_G98M)
  CHECK_PCI(pci, 0x06ee, CHIP_G98)
  CHECK_PCI(pci, 0x06ed, CHIP_G98)
  CHECK_PCI(pci, 0x06ec, CHIP_G98M)
  CHECK_PCI(pci, 0x06eb, CHIP_G98M)
  CHECK_PCI(pci, 0x06ea, CHIP_G98M)
  CHECK_PCI(pci, 0x06e9, CHIP_G98M)
  CHECK_PCI(pci, 0x06e8, CHIP_G98M)
  CHECK_PCI(pci, 0x06e7, CHIP_G98)
  CHECK_PCI(pci, 0x06e6, CHIP_G98)
  CHECK_PCI(pci, 0x06e5, CHIP_G98M)
  CHECK_PCI(pci, 0x06e4, CHIP_G98)
  CHECK_PCI(pci, 0x06e3, CHIP_G98)
  CHECK_PCI(pci, 0x06e2, CHIP_G98)
  CHECK_PCI(pci, 0x06e1, CHIP_G98)
  CHECK_PCI(pci, 0x06e0, CHIP_G98)
  CHECK_PCI(pci, 0x06df, CHIP_GF100GL)
  CHECK_PCI(pci, 0x06de, CHIP_GF100GL)
  CHECK_PCI(pci, 0x06dd, CHIP_GF100GL)
  CHECK_PCI(pci, 0x06dc, CHIP_GF100GL)
  CHECK_PCI(pci, 0x06da, CHIP_GF100GLM)
  CHECK_PCI(pci, 0x06d9, CHIP_GF100GL)
  CHECK_PCI(pci, 0x06d8, CHIP_GF100GL)
  CHECK_PCI(pci, 0x06d2, CHIP_GF100GL)
  CHECK_PCI(pci, 0x06d1, CHIP_GF100GL)
  CHECK_PCI(pci, 0x06d0, CHIP_GF100GL)
  CHECK_PCI(pci, 0x06cd, CHIP_GF100)
  CHECK_PCI(pci, 0x06cb, CHIP_GF100)
  CHECK_PCI(pci, 0x06ca, CHIP_GF100M)
  CHECK_PCI(pci, 0x06c4, CHIP_GF100)
  CHECK_PCI(pci, 0x06c0, CHIP_GF100)
  CHECK_PCI(pci, 0x065f, CHIP_G96C)
  CHECK_PCI(pci, 0x065d, CHIP_G96)
  CHECK_PCI(pci, 0x065c, CHIP_G96GLM)
  CHECK_PCI(pci, 0x065b, CHIP_G96C)
  CHECK_PCI(pci, 0x065a, CHIP_G96GLM)
  CHECK_PCI(pci, 0x0659, CHIP_G96CGL)
  CHECK_PCI(pci, 0x0658, CHIP_G96GL)
  CHECK_PCI(pci, 0x0656, CHIP_G96)
  CHECK_PCI(pci, 0x0655, CHIP_G96)
  CHECK_PCI(pci, 0x0654, CHIP_G96CM)
  CHECK_PCI(pci, 0x0653, CHIP_G96CM)
  CHECK_PCI(pci, 0x0652, CHIP_G96CM)
  CHECK_PCI(pci, 0x0651, CHIP_G96CM)
  CHECK_PCI(pci, 0x064e, CHIP_G96C)
  CHECK_PCI(pci, 0x064c, CHIP_G96CM)
  CHECK_PCI(pci, 0x064b, CHIP_G96M)
  CHECK_PCI(pci, 0x064a, CHIP_G96M)
  CHECK_PCI(pci, 0x0649, CHIP_G96CM)
  CHECK_PCI(pci, 0x0648, CHIP_G96CM)
  CHECK_PCI(pci, 0x0647, CHIP_G96CM)
  CHECK_PCI(pci, 0x0646, CHIP_G96C)
  CHECK_PCI(pci, 0x0645, CHIP_G96C)
  CHECK_PCI(pci, 0x0644, CHIP_G96)
  CHECK_PCI(pci, 0x0643, CHIP_G96)
  CHECK_PCI(pci, 0x0642, CHIP_G96)
  CHECK_PCI(pci, 0x0641, CHIP_G96C)
  CHECK_PCI(pci, 0x0640, CHIP_G96C)
  CHECK_PCI(pci, 0x063f, CHIP_G94)
  CHECK_PCI(pci, 0x063a, CHIP_G94GLM)
  CHECK_PCI(pci, 0x0638, CHIP_G94GL)
  CHECK_PCI(pci, 0x0637, CHIP_G94)
  CHECK_PCI(pci, 0x0635, CHIP_G94)
  CHECK_PCI(pci, 0x0633, CHIP_G94)
  CHECK_PCI(pci, 0x0632, CHIP_G94M)
  CHECK_PCI(pci, 0x0631, CHIP_G94M)
  CHECK_PCI(pci, 0x0630, CHIP_G94)
  CHECK_PCI(pci, 0x062f, CHIP_G94)
  CHECK_PCI(pci, 0x062e, CHIP_G94)
  CHECK_PCI(pci, 0x062d, CHIP_G94)
  CHECK_PCI(pci, 0x062c, CHIP_G94M)
  CHECK_PCI(pci, 0x062b, CHIP_G94M)
  CHECK_PCI(pci, 0x062a, CHIP_G94M)
  CHECK_PCI(pci, 0x0628, CHIP_G94M)
  CHECK_PCI(pci, 0x0627, CHIP_G94)
  CHECK_PCI(pci, 0x0626, CHIP_G94)
  CHECK_PCI(pci, 0x0625, CHIP_G94)
  CHECK_PCI(pci, 0x0624, CHIP_G94)
  CHECK_PCI(pci, 0x0623, CHIP_G94)
  CHECK_PCI(pci, 0x0622, CHIP_G94)
  CHECK_PCI(pci, 0x0621, CHIP_G94)
  CHECK_PCI(pci, 0x0620, CHIP_G94)
  CHECK_PCI(pci, 0x061f, CHIP_G92GLM)
  CHECK_PCI(pci, 0x061e, CHIP_G92GLM)
  CHECK_PCI(pci, 0x061d, CHIP_G92GLM)
  CHECK_PCI(pci, 0x061c, CHIP_G92GLM)
  CHECK_PCI(pci, 0x061b, CHIP_G92GL)
  CHECK_PCI(pci, 0x061a, CHIP_G92GL)
  CHECK_PCI(pci, 0x0619, CHIP_G92GL)
  CHECK_PCI(pci, 0x0618, CHIP_G92M)
  CHECK_PCI(pci, 0x0617, CHIP_G92M)
  CHECK_PCI(pci, 0x0615, CHIP_G92)
  CHECK_PCI(pci, 0x0614, CHIP_G92)
  CHECK_PCI(pci, 0x0613, CHIP_G92)
  CHECK_PCI(pci, 0x0612, CHIP_G92)
  CHECK_PCI(pci, 0x0611, CHIP_G92)
  CHECK_PCI(pci, 0x0610, CHIP_G92)
  CHECK_PCI(pci, 0x060f, CHIP_G92M)
  CHECK_PCI(pci, 0x060d, CHIP_G92)
  CHECK_PCI(pci, 0x060c, CHIP_G92M)
  CHECK_PCI(pci, 0x060b, CHIP_G92M)
  CHECK_PCI(pci, 0x060a, CHIP_G92M)
  CHECK_PCI(pci, 0x0609, CHIP_G92M)
  CHECK_PCI(pci, 0x0608, CHIP_G92M)
  CHECK_PCI(pci, 0x0607, CHIP_G92)
  CHECK_PCI(pci, 0x0606, CHIP_G92)
  CHECK_PCI(pci, 0x0605, CHIP_G92)
  CHECK_PCI(pci, 0x0604, CHIP_G92)
  CHECK_PCI(pci, 0x0603, CHIP_G92)
  CHECK_PCI(pci, 0x0602, CHIP_G92)
  CHECK_PCI(pci, 0x0601, CHIP_G92)
  CHECK_PCI(pci, 0x0600, CHIP_G92)
  CHECK_PCI(pci, 0x05ff, CHIP_GT200GL)
  CHECK_PCI(pci, 0x05fe, CHIP_GT200GL)
  CHECK_PCI(pci, 0x05fd, CHIP_GT200GL)
  CHECK_PCI(pci, 0x05f9, CHIP_GT200GL)
  CHECK_PCI(pci, 0x05f8, CHIP_GT200GL)
  CHECK_PCI(pci, 0x05f2, CHIP_GT200)
  CHECK_PCI(pci, 0x05f1, CHIP_GT200)
  CHECK_PCI(pci, 0x05ed, CHIP_GT200GL)
  CHECK_PCI(pci, 0x05eb, CHIP_GT200)
  CHECK_PCI(pci, 0x05ea, CHIP_GT200)
  CHECK_PCI(pci, 0x05e7, CHIP_GT200GL)
  CHECK_PCI(pci, 0x05e6, CHIP_GT200B)
  CHECK_PCI(pci, 0x05e3, CHIP_GT200B)
  CHECK_PCI(pci, 0x05e2, CHIP_GT200)
  CHECK_PCI(pci, 0x05e1, CHIP_GT200)
  CHECK_PCI(pci, 0x05e0, CHIP_GT200B)
  CHECK_PCI(pci, 0x042f, CHIP_G86)
  CHECK_PCI(pci, 0x042e, CHIP_G86M)
  CHECK_PCI(pci, 0x042d, CHIP_G86GLM)
  CHECK_PCI(pci, 0x042c, CHIP_G86)
  CHECK_PCI(pci, 0x042b, CHIP_G86M)
  CHECK_PCI(pci, 0x042a, CHIP_G86M)
  CHECK_PCI(pci, 0x0429, CHIP_G86M)
  CHECK_PCI(pci, 0x0428, CHIP_G86M)
  CHECK_PCI(pci, 0x0427, CHIP_G86M)
  CHECK_PCI(pci, 0x0426, CHIP_G86M)
  CHECK_PCI(pci, 0x0425, CHIP_G86M)
  CHECK_PCI(pci, 0x0424, CHIP_G86)
  CHECK_PCI(pci, 0x0423, CHIP_G86)
  CHECK_PCI(pci, 0x0422, CHIP_G86)
  CHECK_PCI(pci, 0x0421, CHIP_G86)
  CHECK_PCI(pci, 0x0420, CHIP_G86)
  CHECK_PCI(pci, 0x0418, CHIP_G92)
  CHECK_PCI(pci, 0x0414, CHIP_G92)
  CHECK_PCI(pci, 0x0410, CHIP_G92)
  CHECK_PCI(pci, 0x040f, CHIP_G84GL)
  CHECK_PCI(pci, 0x040e, CHIP_G84GL)
  CHECK_PCI(pci, 0x040d, CHIP_G84GLM)
  CHECK_PCI(pci, 0x040c, CHIP_G84GLM)
  CHECK_PCI(pci, 0x040b, CHIP_G84GLM)
  CHECK_PCI(pci, 0x040a, CHIP_G84GL)
  CHECK_PCI(pci, 0x0409, CHIP_G84M)
  CHECK_PCI(pci, 0x0408, CHIP_G84M)
  CHECK_PCI(pci, 0x0407, CHIP_G84M)
  CHECK_PCI(pci, 0x0406, CHIP_G84)
  CHECK_PCI(pci, 0x0405, CHIP_G84M)
  CHECK_PCI(pci, 0x0404, CHIP_G84)
  CHECK_PCI(pci, 0x0403, CHIP_G84)
  CHECK_PCI(pci, 0x0402, CHIP_G84)
  CHECK_PCI(pci, 0x0401, CHIP_G84)
  CHECK_PCI(pci, 0x0400, CHIP_G84)
  CHECK_PCI(pci, 0x019e, CHIP_G80GL)
  CHECK_PCI(pci, 0x019d, CHIP_G80GL)
  CHECK_PCI(pci, 0x0197, CHIP_G80GL)
  CHECK_PCI(pci, 0x0194, CHIP_G80)
  CHECK_PCI(pci, 0x0193, CHIP_G80)
  CHECK_PCI(pci, 0x0192, CHIP_G80)
  CHECK_PCI(pci, 0x0191, CHIP_G80)
  CHECK_PCI(pci, 0x0190, CHIP_G80)
  CHECK_PCI_END
}
