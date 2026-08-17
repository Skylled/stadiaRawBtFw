// 6009dfd8  FUN_6009dfd8  size=188 bytes
// --- callers ---
//   6009e1b4 FUN_6009e1b4
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_6009dfd8(undefined4 param_1,char param_2,byte *param_3,char param_4)

{
  int iVar1;
  byte local_d;
  int local_c;
  
  iVar1 = DAT_6009e094;
  if (param_4 != '\x04') {
    *(undefined1 *)(DAT_6009e094 + 0x34) = 0;
    thunk_EXT_FUN_0000b5ba(iVar1 + 0x35,0,0x3e);
  }
  if (param_2 != '\0') {
    local_c = (uint)*(byte *)(iVar1 + 0x34) + iVar1 + 0x35;
    local_d = *param_3;
    while ((local_d != 0 && ((uint)local_d + (uint)*(byte *)(iVar1 + 0x34) + 1 < 0x3f))) {
      thunk_EXT_FUN_0000b572(local_c,param_3,local_d + 1);
      local_c = local_d + 1 + local_c;
      *(byte *)(iVar1 + 0x34) = local_d + *(char *)(iVar1 + 0x34) + '\x01';
      param_3 = param_3 + local_d + 1;
      local_d = *param_3;
    }
  }
  return;
}


