// 600fdbb8  FUN_600fdbb8  size=142 bytes
// --- callers ---
//   600fd8c4 FUN_600fd8c4
// --- callees ---
//   600952fc FUN_600952fc
//   60094f58 FUN_60094f58
//   600f3caa FUN_600f3caa


void FUN_600fdbb8(int param_1)

{
  int iVar1;
  undefined1 local_2bc [688];
  int *local_c;
  
  local_2bc[0] = 0x85;
  iVar1 = FUN_600952fc(*(undefined1 *)(param_1 + 0xe),param_1 + 8,0,0);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_600f3caa(*(undefined1 *)(param_1 + 0xe),param_1 + 8,0), iVar1 != 0)) {
    local_2bc[0] = 0;
  }
  local_c = (int *)FUN_60094f58(*(undefined1 *)(param_1 + 0xe));
  if ((local_c != (int *)0x0) && (*local_c != 0)) {
    (*(code *)*local_c)(0xe,local_2bc);
  }
  return;
}


