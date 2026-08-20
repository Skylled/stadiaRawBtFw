// 600eb4b0  FUN_600eb4b0  size=178 bytes
// --- callers ---
// --- callees ---
//   600e93ca FUN_600e93ca
//   600eadd0 FUN_600eadd0
//   600e7588 FUN_600e7588
//   600eb47c FUN_600eb47c
//   600e972c FUN_600e972c
//   600eb1d4 FUN_600eb1d4
//   6013cf28 thunk_EXT_FUN_0000af88
//   600e7a32 FUN_600e7a32


uint FUN_600eb4b0(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_dc [68];
  undefined1 auStack_98 [68];
  undefined1 auStack_54 [68];
  
  if ((*(int *)(param_1 + 0xc4) == 0) || (*(int *)(param_1 + 0x28) != *(int *)(param_1 + 0xc))) {
    uVar1 = FUN_600eb47c(param_1,param_2,param_3);
  }
  else {
    iVar2 = FUN_600eb1d4();
    if (iVar2 == 0) {
      FUN_600e972c(param_1,auStack_98,param_2 + 0x88);
      thunk_EXT_FUN_0000af88(auStack_dc,param_3,*(int *)(param_1 + 0x28) << 2);
      FUN_600e972c(param_1,auStack_dc,auStack_dc,auStack_98);
      FUN_600e93ca(auStack_54,param_2,*(undefined4 *)(param_1 + 0x28),
                   *(undefined4 *)(param_1 + 0x110));
      iVar2 = FUN_600eadd0(param_1,auStack_dc,auStack_54);
      if (iVar2 == 0) {
        uVar3 = *(undefined4 *)(param_1 + 0x28);
        iVar2 = FUN_600e7588(param_3,param_1 + 200,uVar3);
        uVar1 = 0;
        if (iVar2 != 0) {
          FUN_600e7a32(auStack_dc,param_3,*(undefined4 *)(param_1 + 8),uVar3);
          FUN_600e972c(param_1,auStack_dc,auStack_dc,auStack_98);
          iVar2 = FUN_600eadd0(param_1,auStack_dc,auStack_54);
          uVar1 = (uint)(iVar2 != 0);
        }
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


