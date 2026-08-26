// 600d47c4  FUN_600d47c4  size=140 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d168 thunk_EXT_FUN_0000b554


uint FUN_600d47c4(int *param_1,int param_2,uint param_3,undefined1 *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  
  if ((((param_4 == (undefined1 *)0x0) || (uVar1 = (uint)*(byte *)(param_1 + 3), 0x10 < uVar1)) ||
      (uVar1 * (0x10 / uVar1) != 0x10)) || (param_3 != uVar1 * (param_3 / uVar1))) {
    uVar1 = 3;
  }
  else {
    thunk_EXT_FUN_0000b5ba(auStack_30,(char)param_1[6]);
    *param_4 = 0;
    iVar4 = 0;
    for (; param_3 != 0; param_3 = param_3 - uVar1) {
      uVar1 = param_3;
      if (0xf < param_3) {
        uVar1 = 0x10;
      }
      uVar2 = (**(code **)(*param_1 + 0x14))(param_1,auStack_40,iVar4 + param_2,uVar1);
      if ((uVar2 & 0xff) != 0) {
        return uVar2;
      }
      iVar3 = thunk_EXT_FUN_0000b554(auStack_40,auStack_30,uVar1);
      if (iVar3 != 0) {
        return 0;
      }
      iVar4 = iVar4 + uVar1;
    }
    *param_4 = 1;
    uVar1 = 0;
  }
  return uVar1;
}


