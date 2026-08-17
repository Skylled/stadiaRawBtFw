// 600a82a0  FUN_600a82a0  size=102 bytes
// --- callers ---
//   600a730c FUN_600a730c
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600d92fc FUN_600d92fc
//   600d92f8 FUN_600d92f8
//   600d9290 FUN_600d9290


void FUN_600a82a0(undefined4 param_1,char param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = DAT_600a8308;
  iVar2 = FUN_600d92f8(DAT_600a8308);
  if (iVar2 != 0) {
    iVar3 = thunk_EXT_FUN_0000b554(iVar2 + 1,param_1,6);
    if ((iVar3 == 0) && (param_2 == *(char *)(iVar2 + 0x1c))) {
      (**(code **)(iVar2 + 0xc))(param_1,param_2,*(undefined4 *)(iVar2 + 0x10),10);
      FUN_600d9290(uVar1,iVar2);
    }
    FUN_600d92fc(iVar2);
  }
  return;
}


