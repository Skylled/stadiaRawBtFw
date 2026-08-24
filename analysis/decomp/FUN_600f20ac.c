// 600f20ac  FUN_600f20ac  size=74 bytes
// --- callers ---
//   600f6042 FUN_600f6042
//   600f5e3c FUN_600f5e3c
//   600f5bfc FUN_600f5bfc
//   600f5ede FUN_600f5ede
//   600f5fb4 FUN_600f5fb4
// --- callees ---
//   6009ff18 FUN_6009ff18


undefined1 FUN_600f20ac(undefined4 param_1)

{
  int iVar1;
  undefined1 local_9;
  
  iVar1 = FUN_6009ff18(param_1);
  local_9 = 0;
  if ((iVar1 != 0) &&
     (((*(char *)(iVar1 + 0x7b) != '\0' && ((*(ushort *)(iVar1 + 0x2a) & 0x1000) != 0)) ||
      ((*(ushort *)(iVar1 + 0x2a) & 0x10) != 0)))) {
    local_9 = 1;
  }
  return local_9;
}


