// 600ef900  FUN_600ef900  size=116 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
// --- callees ---
//   6009547c FUN_6009547c
//   600ef8a0 FUN_600ef8a0
//   60094ffc FUN_60094ffc
//   600950bc FUN_600950bc


int FUN_600ef900(int param_1)

{
  int iVar1;
  undefined4 local_c;
  
  if (*(char *)(param_1 + 0xf) == '\x01') {
    FUN_600ef8a0(param_1 + 8);
  }
  local_c = FUN_60094ffc(*(undefined1 *)(param_1 + 0xe),param_1 + 8,*(undefined1 *)(param_1 + 0x10))
  ;
  if ((local_c == 0) &&
     (iVar1 = FUN_6009547c(*(undefined1 *)(param_1 + 0xe),param_1 + 8,*(undefined1 *)(param_1 + 0xf)
                          ), iVar1 != 0)) {
    local_c = FUN_600950bc(*(undefined1 *)(param_1 + 0xe),param_1 + 8,
                           *(undefined1 *)(param_1 + 0x10));
  }
  return local_c;
}


