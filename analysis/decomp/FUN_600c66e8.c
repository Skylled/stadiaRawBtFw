// 600c66e8  FUN_600c66e8  size=186 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
// --- callees ---
//   600951ec FUN_600951ec
//   60094d24 FUN_60094d24
//   600d9250 FUN_600d9250
//   600d9230 FUN_600d9230
//   6006ddd8 FUN_6006ddd8


void FUN_600c66e8(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  byte local_e;
  int local_c;
  
  iVar2 = FUN_600951ec(param_2 + 8);
  local_c = DAT_600c67a4;
  bVar1 = false;
  if (iVar2 != 0) {
    if ((*(char *)(iVar2 + 7) != '\0') && (*(char *)(iVar2 + 0x27) != '\0')) {
      for (local_e = 0; local_e < 6; local_e = local_e + 1) {
        if ((*(char *)(local_c + 0x1b) != '\0') && (iVar2 == *(int *)(local_c + 0x10))) {
          bVar1 = true;
          break;
        }
        local_c = local_c + 0x20;
      }
      if (bVar1) {
        FUN_60094d24(local_c,0x1d0e,0);
        return;
      }
    }
    if (*(int *)(iVar2 + 0xc) != 0) {
      while (*(int *)(iVar2 + 0x14) != 0) {
        uVar3 = FUN_600d9250(iVar2 + 0x14);
        FUN_6006ddd8(uVar3,DAT_600c67a8,0x700,uVar3,param_2,param_1);
      }
      *(undefined4 *)(iVar2 + 0xc) = 0;
    }
  }
  FUN_600d9230(param_2 + 8);
  return;
}


