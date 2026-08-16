// 600c64c8  FUN_600c64c8  size=226 bytes
// --- callers ---
// --- callees ---
//   600fe500 FUN_600fe500
//   600fe7a6 FUN_600fe7a6
//   600fe66a FUN_600fe66a
//   600fe7fe FUN_600fe7fe
//   60094d24 FUN_60094d24


void FUN_600c64c8(int param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_2 + 8);
  if ((((bVar1 != 7) && (bVar1 != 6)) && (1 < bVar1)) &&
     ((*(int *)(param_1 + 0x14) != 0 &&
      (**(short **)(param_1 + 0x14) == *(short *)(DAT_600c65ac + (bVar1 - 2) * 2))))) {
    if ((*(char *)(param_1 + 0x19) == '\x01') &&
       (*(char *)(*(int *)(param_1 + 0x10) + 0x31) != '\0')) {
      *(undefined1 *)(param_2 + 9) = 0x85;
    }
    if (bVar1 == 2) {
      FUN_600fe500(param_1,param_2);
    }
    else if (bVar1 == 3) {
      FUN_600fe66a(param_1,param_2);
    }
    else if (bVar1 == 4) {
      FUN_600fe7a6(param_1,param_2);
    }
    else if (bVar1 == 5) {
      FUN_600fe7fe(param_1,param_2);
    }
    if (*(char *)(param_1 + 0x19) == '\x01') {
      *(undefined1 *)(param_1 + 0x19) = 0x10;
      FUN_60094d24(param_1,0x1d0e,0);
    }
  }
  return;
}


