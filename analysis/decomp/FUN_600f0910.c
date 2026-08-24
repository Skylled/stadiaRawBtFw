// 600f0910  FUN_600f0910  size=90 bytes
// --- callers ---
//   600a30f0 FUN_600a30f0
//   600f1b34 FUN_600f1b34
//   600a2180 FUN_600a2180
// --- callees ---
//   60098ec8 FUN_60098ec8
//   600f0836 FUN_600f0836


undefined1 FUN_600f0910(undefined4 param_1)

{
  int iVar1;
  undefined1 uStack_b;
  char local_a;
  undefined1 local_9;
  
  local_9 = 0;
  iVar1 = FUN_60098ec8(param_1,1);
  if (iVar1 == 0) {
    iVar1 = FUN_60098ec8(param_1,2);
    if (iVar1 == 0) {
      FUN_600f0836(param_1,&local_a,&uStack_b);
      local_9 = local_a == '\x02';
    }
    else {
      local_9 = 1;
    }
  }
  return local_9;
}


