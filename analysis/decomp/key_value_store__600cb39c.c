// 600cb39c  key_value_store__600cb39c  size=126 bytes
// src: key_value_store.cc
// --- callers ---
//   60100ffc FUN_60100ffc
//   600cb6fc key_value_store__600cb6fc
// --- callees ---
//   60100b38 FUN_60100b38
//   60100f90 FUN_60100f90
//   60100bb0 FUN_60100bb0
//   6010165c FUN_6010165c


/* src: key_value_store.cc */

uint key_value_store__600cb39c
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_60100b38(*param_1);
  if ((iVar2 != 1) && (iVar2 = FUN_60100bb0(param_1,0xffffffff), iVar2 == 0)) {
    FUN_6010165c(0x14,DAT_600cb420,0x173,DAT_600cb41c,param_4);
    uVar3 = FUN_60100f90(param_1,1);
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    iVar2 = FUN_60100bb0(param_1,0xffffffff);
    if (iVar2 == 0) {
      FUN_6010165c(0x14,DAT_600cb420,0x179,DAT_600cb424);
      bVar1 = FUN_60100f90(param_1,0,1);
      if (bVar1 != 0) {
        return (uint)bVar1;
      }
      iVar2 = FUN_60100bb0(param_1,0xffffffff);
      if (iVar2 != 0) {
        return 0;
      }
      return 8;
    }
  }
  return 0;
}


