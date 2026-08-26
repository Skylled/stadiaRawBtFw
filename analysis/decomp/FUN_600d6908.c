// 600d6908  FUN_600d6908  size=54 bytes
// --- callers ---
//   600d693e FUN_600d693e
// --- callees ---
//   600d68fe FUN_600d68fe


void FUN_600d6908(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 == 0) ||
     (iVar2 = *(int *)(param_1 + 0x78) + 1, *(int *)(param_1 + 0x78) = iVar2, 2 < iVar2)) {
    *(undefined4 *)(param_1 + 0x78) = 0;
    if ((param_2 == 0) || (param_3 == 0)) {
      if (*(char *)(param_1 + 0x7c) == '\0') {
        uVar1 = 1;
      }
      else {
        uVar1 = 2;
      }
    }
    else {
      uVar1 = 8;
    }
  }
  else {
    uVar1 = 7;
  }
  FUN_600d68fe(param_1,uVar1);
  return;
}


