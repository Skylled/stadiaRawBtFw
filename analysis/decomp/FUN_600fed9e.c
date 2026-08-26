// 600fed9e  FUN_600fed9e  size=162 bytes
// --- callers ---
//   600c69dc FUN_600c69dc
//   600fee40 FUN_600fee40
// --- callees ---
//   600950bc FUN_600950bc
//   60094d24 FUN_60094d24
//   600f3e6a FUN_600f3e6a
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600fed9e(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 local_132;
  undefined1 auStack_130 [6];
  undefined2 local_12a;
  undefined1 auStack_128 [6];
  undefined1 local_122;
  undefined1 local_121;
  undefined2 *local_c;
  
  local_c = (undefined2 *)0x0;
  iVar1 = FUN_600f3e6a(param_1,param_2,&local_132,2);
  if (iVar1 != 0) {
    local_c = (undefined2 *)FUN_600950bc(param_1,param_2,2);
    if (local_c != (undefined2 *)0x0) {
      *local_c = local_132;
      local_12a = *local_c;
      local_122 = param_1;
      thunk_EXT_FUN_0000b572(auStack_128,param_2,6);
      local_121 = 1;
      FUN_60094d24(local_c,0x1d00,auStack_130);
    }
  }
  return;
}


