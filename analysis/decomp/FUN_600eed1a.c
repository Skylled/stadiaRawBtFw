// 600eed1a  FUN_600eed1a  size=212 bytes
// --- callers ---
//   60094a3c FUN_60094a3c
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined1 FUN_600eed1a(int param_1,short param_2,undefined2 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 in_stack_00000010;
  undefined1 local_11;
  undefined4 local_4;
  
  local_11 = 0;
  if (*(int *)(param_1 + 0x28) == 0) {
    local_11 = 0x81;
  }
  else if (*(byte *)(param_1 + 0x2e) < 0x1e) {
    iVar1 = (uint)*(byte *)(param_1 + 0x2e) * 0x1c + *(int *)(param_1 + 0x28);
    *(char *)(param_1 + 0x30) = *(char *)(param_1 + 0x30) + '\x01';
    *(undefined2 *)(iVar1 + 0x14) = param_3;
    *(undefined1 *)(iVar1 + 0x1a) = in_stack_00000010;
    *(undefined2 *)(iVar1 + 0x16) =
         *(undefined2 *)((uint)*(byte *)(param_1 + 0x2c) * 0x1c + *(int *)(param_1 + 0x28) + 0x16);
    local_4 = param_4;
    thunk_EXT_FUN_0000b572(iVar1,&local_4,0x14);
    if (1 < *(byte *)(param_1 + 0x30)) {
      *(short *)(iVar1 + -6) = param_2 + -1;
    }
    *(char *)(param_1 + 0x2e) = *(char *)(param_1 + 0x2e) + '\x01';
  }
  else {
    local_11 = 0x83;
  }
  return local_11;
}


