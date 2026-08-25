// 600fc04a  FUN_600fc04a  size=198 bytes
// --- callers ---
//   600fc17a FUN_600fc17a
// --- callees ---
//   600f061a FUN_600f061a
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600fc04a(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 local_1d;
  undefined1 auStack_1c [8];
  undefined1 *local_14;
  
  local_1d = 0;
  local_14 = param_2;
  iVar1 = FUN_600f061a(param_1 + 0x1d,auStack_1c,&local_1d);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b5ba(local_14,0,0x10);
    if (*(char *)(param_1 + 0x26) == '\0') {
      for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
        *local_14 = auStack_1c[5 - iVar1];
        local_14 = local_14 + 1;
      }
      for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
        *local_14 = *(undefined1 *)((param_1 - iVar1) + 0x1f9);
        local_14 = local_14 + 1;
      }
    }
    else {
      for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
        *local_14 = *(undefined1 *)((param_1 - iVar1) + 0x1f9);
        local_14 = local_14 + 1;
      }
      for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
        *local_14 = auStack_1c[5 - iVar1];
        local_14 = local_14 + 1;
      }
    }
  }
  return;
}


