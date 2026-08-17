// 6009ce30  FUN_6009ce30  size=148 bytes
// --- callers ---
//   600fd3e0 FUN_600fd3e0
// --- callees ---
//   600b0bb0 FUN_600b0bb0
//   6009cf8c FUN_6009cf8c
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined1 FUN_6009ce30(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_34 [2];
  undefined1 *local_2c;
  undefined1 auStack_28 [31];
  undefined1 local_9;
  
  local_9 = 3;
  local_2c = auStack_28;
  if ((*(byte *)(DAT_6009cec4 + 0x81b) & 2) == 0) {
    local_9 = 5;
  }
  else {
    local_34[0] = param_1;
    thunk_EXT_FUN_0000b5ba(auStack_28,0,0x1f);
    FUN_6009cf8c(local_34,&local_2c,param_2);
    iVar1 = FUN_600b0bb0((int)local_2c - (int)auStack_28 & 0xff,auStack_28);
    if (iVar1 == 0) {
      local_9 = 5;
    }
    else {
      local_9 = 0;
      if (local_34[0] == 0) {
        *(undefined1 *)(DAT_6009cec4 + 0x994) = 0;
      }
      else {
        *(undefined1 *)(DAT_6009cec4 + 0x994) = 1;
      }
    }
  }
  return local_9;
}


