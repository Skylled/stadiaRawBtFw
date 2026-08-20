// 600ea820  FUN_600ea820  size=72 bytes
// --- callers ---
//   600eb47c FUN_600eb47c
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e7d98 FUN_600e7d98


undefined4 FUN_600ea820(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 auStack_5c [18];
  
  thunk_EXT_FUN_0000af90(auStack_5c,0,0x44);
  iVar1 = (**(code **)(*param_1 + 0xc))(param_1,param_3,auStack_5c,0);
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = param_1[3];
    if (iVar1 < 0x11) {
      uVar2 = auStack_5c[iVar1];
    }
    else {
      uVar2 = 0;
    }
    FUN_600e7d98(param_2,auStack_5c,uVar2,param_1[2],iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


