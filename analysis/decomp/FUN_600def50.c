// 600def50  FUN_600def50  size=48 bytes
// --- callers ---
//   6007ffd0 battery_service__6007ffd0
// --- callees ---
//   6007ff34 FUN_6007ff34
//   600def14 FUN_600def14


undefined4 FUN_600def50(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  iVar1 = FUN_600def14();
  if (*(int *)(param_1 + 0x188) == iVar1) {
    uVar2 = 0;
  }
  else {
    *(int *)(param_1 + 0x188) = iVar1;
    if (iVar1 == 1) {
      local_14 = 3;
      FUN_6007ff34(param_1,&local_14);
    }
    uVar2 = 1;
  }
  return uVar2;
}


