// 600a1560  FUN_600a1560  size=82 bytes
// --- callers ---
//   600f16ae FUN_600f16ae
//   600a44bc FUN_600a44bc
// --- callees ---
//   600b3418 FUN_600b3418


undefined4 FUN_600a1560(undefined1 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *local_14;
  undefined1 auStack_10 [7];
  undefined1 local_9;
  
  if (*(int *)(DAT_600a15b4 + 0x700) == 0) {
    local_9 = param_1 == (undefined1 *)0x0;
    local_14 = param_1;
    if ((bool)local_9) {
      local_14 = auStack_10;
    }
    *(undefined4 *)(DAT_600a15b4 + 0x700) = param_2;
    iVar1 = FUN_600b3418(local_14,local_9);
    if (iVar1 == 0) {
      uVar2 = 3;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


