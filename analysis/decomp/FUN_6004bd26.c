// 6004bd26  FUN_6004bd26  size=32 bytes
// --- callers ---
// --- callees ---
//   6004bd8e FUN_6004bd8e


undefined1 FUN_6004bd26(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  iVar3 = param_1[2];
  uVar1 = func_0x6004bcf8(param_1,param_3);
  FUN_6004bd8e(iVar3 + iVar2,param_2,uVar1);
  return *(undefined1 *)((int)param_1 + 0xd);
}


