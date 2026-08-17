// 6009e6c0  FUN_6009e6c0  size=72 bytes
// --- callers ---
//   6009f57c FUN_6009f57c
//   6009dd74 FUN_6009dd74
//   6009c59c FUN_6009c59c
// --- callees ---
//   6009ebd8 FUN_6009ebd8
//   600b0da8 FUN_600b0da8


undefined1 FUN_6009e6c0(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_9;
  
  iVar1 = DAT_6009e708;
  local_9 = 1;
  iVar2 = FUN_600b0da8(1,*(undefined1 *)(DAT_6009e708 + 9));
  if (iVar2 == 0) {
    local_9 = 3;
  }
  else if (*(char *)(iVar1 + 8) == '\x01') {
    FUN_6009ebd8(0x100);
  }
  else {
    FUN_6009ebd8(0x80);
  }
  return local_9;
}


