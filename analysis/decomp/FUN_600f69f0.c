// 600f69f0  FUN_600f69f0  size=154 bytes
// --- callers ---
//   600ae0dc FUN_600ae0dc
//   600c79e4 FUN_600c79e4
//   600f4f02 FUN_600f4f02
//   600c7aac FUN_600c7aac
// --- callees ---
//   600af9a0 FUN_600af9a0


undefined1 FUN_600f69f0(undefined4 *param_1,short param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_25;
  undefined1 *local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  local_8 = param_3;
  uStack_4 = param_4;
  local_24 = (undefined1 *)*param_1;
  local_25 = 0;
  if (param_2 == 2) {
    puVar1 = local_24 + 1;
    *local_24 = (char)param_3;
    local_24 = local_24 + 2;
    *puVar1 = (char)((uint)param_3 >> 8);
    local_25 = 2;
  }
  else if (param_2 == 4) {
    FUN_600af9a0(local_24,param_3);
    local_24 = local_24 + 0x10;
    local_25 = 0x10;
  }
  else if (param_2 == 0x10) {
    for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
      *local_24 = *(undefined1 *)((int)&local_8 + iVar2);
      local_24 = local_24 + 1;
    }
    local_25 = 0x10;
  }
  *param_1 = local_24;
  return local_25;
}


