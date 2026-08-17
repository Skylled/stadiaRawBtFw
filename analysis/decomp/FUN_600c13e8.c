// 600c13e8  FUN_600c13e8  size=168 bytes
// --- callers ---
//   600fce8c FUN_600fce8c
// --- callees ---
//   600c1494 FUN_600c1494
//   600fc602 FUN_600fc602


undefined4
FUN_600c13e8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_28;
  undefined1 local_27;
  undefined4 local_24;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 auStack_18 [16];
  
  local_1c[0] = 0;
  local_20[0] = 1;
  local_24 = *DAT_600c1490;
  local_28 = 0;
  local_27 = 1;
  iVar1 = FUN_600c1494(param_1,auStack_18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_600fc602(auStack_18,local_1c,&local_24,param_2,param_3,param_4,param_5,&local_28,
                         param_6);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_600fc602(auStack_18,local_20,&local_24,param_2,param_3,param_4,param_5,&local_28,
                           param_7);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


