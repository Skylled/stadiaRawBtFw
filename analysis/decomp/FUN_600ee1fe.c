// 600ee1fe  FUN_600ee1fe  size=122 bytes
// --- callers ---
//   600928ac FUN_600928ac
// --- callees ---
//   600eff14 FUN_600eff14
//   600985f8 FUN_600985f8


undefined4 FUN_600ee1fe(short param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 6) {
    iVar1 = FUN_600eff14(param_2,*(undefined1 *)(param_2 + 6),(int)*(char *)(param_2 + 7),
                         (int)*(char *)(param_2 + 8),(int)*(char *)(param_2 + 9),
                         *(undefined4 *)(param_2 + 0xc));
    if (iVar1 == 3) {
      return 0;
    }
  }
  else {
    iVar1 = FUN_600985f8(*(undefined1 *)(param_2 + 6),(int)*(char *)(param_2 + 7),
                         (int)*(char *)(param_2 + 8),(int)*(char *)(param_2 + 9),
                         *(undefined4 *)(param_2 + 0xc));
    if (iVar1 == 3) {
      return 0;
    }
  }
  return 1;
}


