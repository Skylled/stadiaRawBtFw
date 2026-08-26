// 6010138c  FUN_6010138c  size=68 bytes
// --- callers ---
//   600593f4 FUN_600593f4
//   6005e670 FUN_6005e670
//   60059280 FUN_60059280
//   60051b50 stats__60051b50
//   600d38c8 FUN_600d38c8
//   6005842c FUN_6005842c
//   60083900 FUN_60083900
//   6005dcc0 FUN_6005dcc0
//   6005edb8 FUN_6005edb8
//   6005ebe0 FUN_6005ebe0
//   6005e810 FUN_6005e810
//   600d45ba FUN_600d45ba
//   60059360 FUN_60059360
//   6005eaf8 FUN_6005eaf8
//   6007f7a0 FUN_6007f7a0
//   6005e904 FUN_6005e904
//   6007fe74 FUN_6007fe74
//   600dfe6e FUN_600dfe6e
//   60051890 FUN_60051890
//   6005e8d8 FUN_6005e8d8
//   600dfe3e FUN_600dfe3e
//   6005b4f4 FUN_6005b4f4
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600cbb7c FUN_600cbb7c
//   60101302 FUN_60101302


undefined4
FUN_6010138c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1[6];
  if (iVar2 == 0) {
    uVar1 = 0xe;
  }
  else {
    uVar1 = *(undefined4 *)*param_1;
    thunk_EXT_FUN_0000b4c2(iVar2);
    FUN_600cbb7c(iVar2 + 100,uVar1,0,param_2,param_4);
    uVar1 = FUN_60101302(iVar2,iVar2 + 100,*(int *)(iVar2 + 0x26c) + 4,0x32);
    thunk_EXT_FUN_00007d10(iVar2);
  }
  return uVar1;
}


