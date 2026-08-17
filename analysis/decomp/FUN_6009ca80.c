// 6009ca80  FUN_6009ca80  size=84 bytes
// --- callers ---
//   600b05f0 FUN_600b05f0
//   600f735a FUN_600f735a
//   600f717c FUN_600f717c
// --- callees ---
//   6009c2c0 FUN_6009c2c0
//   6009c124 FUN_6009c124


undefined1 FUN_6009ca80(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_a;
  undefined1 local_9;
  
  local_9 = 0;
  local_a = 3;
  if ((*(byte *)(DAT_6009cad4 + 0x81b) & 2) == 0) {
    local_9 = 0;
  }
  else {
    iVar1 = FUN_6009c2c0(param_1,param_2,&local_a);
    if (iVar1 != 0) {
      local_9 = FUN_6009c124(param_1,param_2,local_a);
    }
  }
  return local_9;
}


