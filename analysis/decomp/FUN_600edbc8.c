// 600edbc8  FUN_600edbc8  size=44 bytes
// --- callers ---
//   600edc0e FUN_600edc0e
// --- callees ---
//   600edb6e FUN_600edb6e


void FUN_600edbc8(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1[3] == 0) {
    uVar2 = param_1[2];
    if (*param_1 / uVar2 < 3) {
      if ((*param_1 / uVar2 == 0) && (0x10 < uVar2)) {
        uVar1 = uVar2 >> 1;
        if (uVar1 < 0x10) {
          uVar1 = 0x10;
        }
        goto LAB_600edbde;
      }
    }
    else {
      uVar1 = uVar2 << 1;
      if (uVar2 < uVar1) {
LAB_600edbde:
        FUN_600edb6e(param_1,uVar1);
        return;
      }
    }
  }
  return;
}


