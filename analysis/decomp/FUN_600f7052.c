// 600f7052  FUN_600f7052  size=98 bytes
// --- callers ---
//   600f3caa FUN_600f3caa
// --- callees ---
//   600f6132 FUN_600f6132
//   600af814 FUN_600af814
//   600f6dc6 FUN_600f6dc6
//   600f592e FUN_600f592e
//   600f5a98 FUN_600f5a98


undefined1 FUN_600f7052(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_9;
  
  local_9 = 1;
  iVar1 = FUN_600af814(param_2,2);
  if (iVar1 != 0) {
    iVar2 = FUN_600f6132(iVar1);
    if (iVar2 == 4) {
      local_9 = 0;
    }
    else {
      FUN_600f5a98(param_1,iVar1,0,0);
      iVar2 = FUN_600f6dc6(iVar1);
      if (iVar2 == 0) {
        local_9 = FUN_600f592e(iVar1);
      }
    }
  }
  return local_9;
}


