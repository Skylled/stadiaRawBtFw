// 600a4b1c  FUN_600a4b1c  size=148 bytes
// --- callers ---
//   600a4bb8 FUN_600a4bb8
//   600a4c5c FUN_600a4c5c
//   600a51a8 FUN_600a51a8
// --- callees ---


undefined1 FUN_600a4b1c(int param_1,char param_2)

{
  ushort uVar1;
  undefined1 local_9;
  
  if (param_2 == '\0') {
    uVar1 = 0x1000;
  }
  else {
    uVar1 = 0x2000;
  }
  local_9 = 1;
  if (((((*(ushort *)(param_1 + 0x2a) & 0x10) != 0) &&
       (local_9 = 0, (uVar1 & *(ushort *)(param_1 + 0x54)) != 0)) &&
      ((*(char *)(param_1 + 0x57) == '\x04' || (*(char *)(param_1 + 0x57) == '\a')))) &&
     ((*(byte *)(param_1 + 0x5a) < 5 &&
      (*(char *)((uint)*(byte *)(param_1 + 0x5a) * 5 + DAT_600a4bb4 +
                (uint)*(byte *)(DAT_600a4bb0 + 0x882)) != '\0')))) {
    local_9 = 1;
  }
  return local_9;
}


