// 600bd65c  FUN_600bd65c  size=208 bytes
// --- callers ---
//   600f6c4c FUN_600f6c4c
//   600bd150 FUN_600bd150
// --- callees ---
//   600bd848 FUN_600bd848
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 FUN_600bd65c(void)

{
  undefined4 uVar1;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  int local_10;
  int local_c;
  
  local_10 = DAT_600bd72c;
  if (*(ushort *)(DAT_600bd72c + 6) < 8) {
    thunk_EXT_FUN_0000b5ba((uint)*(ushort *)(DAT_600bd72c + 6) * 0x1cc + 8 + DAT_600bd72c,0,0x1cc);
    if (*(short *)(local_10 + 6) == 0) {
      local_c = 0x10000;
    }
    else {
      local_c = *(int *)((*(ushort *)(local_10 + 6) - 1) * 0x1cc + local_10 + 8) + 1;
    }
    *(int *)((uint)*(ushort *)(local_10 + 6) * 0x1cc + local_10 + 8) = local_c;
    *(short *)(local_10 + 6) = *(short *)(local_10 + 6) + 1;
    local_14 = (undefined1)((uint)local_c >> 0x18);
    local_13 = (undefined1)((uint)local_c >> 0x10);
    local_12 = (undefined1)((uint)local_c >> 8);
    local_11 = (undefined1)local_c;
    FUN_600bd848(local_c,0,1,4,&local_14);
    uVar1 = *(undefined4 *)((*(ushort *)(local_10 + 6) - 1) * 0x1cc + local_10 + 8);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


