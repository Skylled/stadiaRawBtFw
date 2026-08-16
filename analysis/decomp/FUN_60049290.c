// 60049290  FUN_60049290  size=42 bytes
// --- callers ---
// --- callees ---


void FUN_60049290(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar3 = 1;
  do {
    if (((uVar3 & param_3) != 0) &&
       (iVar1 = *(int *)(param_1 + param_2 * 0x80 + -0x7c + iVar2 * 4), iVar1 != 0)) {
      (**(code **)(iVar1 + 4))(*(undefined4 *)(iVar1 + 8));
    }
    iVar2 = iVar2 + 1;
    uVar3 = uVar3 << 1;
  } while (iVar2 != 0x20);
  return;
}


