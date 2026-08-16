// 6008506c  evp__6008506c  size=70 bytes
// src: evp.c
// --- callers ---
//   600e06ee FUN_600e06ee
// --- callees ---
//   60084fc0 FUN_60084fc0
//   600e0680 FUN_600e0680
//   600e0552 FUN_600e0552
//   600e064c FUN_600e064c


/* src: evp.c */

undefined4 evp__6008506c(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = param_2;
  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {
    FUN_600e0680();
  }
  puVar1 = (undefined4 *)FUN_60084fc0(param_2);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_600e0552(6,0,0x80,DAT_600850b4,0x147,uVar2);
    FUN_600e064c(DAT_600850b8,param_2);
    uVar2 = 0;
  }
  else {
    if (param_1 != 0) {
      uVar2 = *puVar1;
      *(undefined4 **)(param_1 + 0xc) = puVar1;
      *(undefined4 *)(param_1 + 4) = uVar2;
    }
    uVar2 = 1;
  }
  return uVar2;
}


