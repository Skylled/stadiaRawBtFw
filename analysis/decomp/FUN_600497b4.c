// 600497b4  FUN_600497b4  size=76 bytes
// --- callers ---
// --- callees ---
//   600437c8 FUN_600437c8


void FUN_600497b4(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_158 [324];
  
  iVar1 = *(int *)*param_2;
  iVar2 = ((int *)*param_2)[1] - iVar1 >> 2;
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  FUN_600437c8(iVar1,iVar2,auStack_158);
  if (*(char *)(param_1 + 0x1b9) == '\0') {
    func_0x6004495c(*(undefined4 *)(param_1 + 0x254),auStack_158,0xa0,param_3,0x1e0);
  }
  return;
}


