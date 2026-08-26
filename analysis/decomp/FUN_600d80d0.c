// 600d80d0  FUN_600d80d0  size=36 bytes
// --- callers ---
//   60067f5c mimxrt10xx_flash_memory__60067f5c
//   60068024 mimxrt10xx_flash_memory__60068024
//   600d80f4 FUN_600d80f4
// --- callees ---
//   600d800e FUN_600d800e


undefined4 FUN_600d80d0(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint local_14;
  undefined4 uStack_10;
  
  if ((param_2 & 0xf) == 0) {
    local_14 = param_2 >> 4;
    uStack_10 = param_3;
    uVar1 = FUN_600d800e(&local_14);
    *param_1 = uVar1;
    uVar1 = 0;
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}


