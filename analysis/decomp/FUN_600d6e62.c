// 600d6e62  FUN_600d6e62  size=24 bytes
// --- callers ---
//   600662e0 dynamic_buffer__600662e0
// --- callees ---
//   60101fc6 FUN_60101fc6


void FUN_600d6e62(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int extraout_r2;
  int iVar2;
  undefined4 local_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = param_1;
  local_c = param_2;
  uStack_8 = param_3;
  if (iVar1 == 0) {
    param_1 = FUN_60101fc6();
    iVar1 = extraout_r2;
  }
  (**(code **)(param_1 + 0xc))(param_1,&local_c,iVar1,*(code **)(param_1 + 0xc),iVar2);
  return;
}


