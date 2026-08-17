// 600c0578  FUN_600c0578  size=104 bytes
// --- callers ---
//   600a44bc FUN_600a44bc
//   600f0bb8 FUN_600f0bb8
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600c1a34 FUN_600c1a34
//   600b50d0 FUN_600b50d0


undefined1 FUN_600c0578(undefined4 param_1)

{
  int iVar1;
  undefined1 local_d;
  int local_c;
  
  iVar1 = DAT_600c05e0;
  local_c = DAT_600c05e0;
  local_d = 0xf;
  if ((*(char *)(DAT_600c05e0 + 0x23) == '\0') && ((*(ushort *)(DAT_600c05e0 + 0x28) & 1) == 0)) {
    *(undefined2 *)(DAT_600c05e0 + 0x28) = 1;
    thunk_EXT_FUN_0000b572(iVar1 + 0x1d,param_1,6);
    iVar1 = FUN_600b50d0(6,param_1);
    if (iVar1 == 0) {
      FUN_600c1a34(local_c,0x17,&local_d);
    }
    else {
      local_d = 0x15;
    }
  }
  else {
    local_d = 0x13;
  }
  return local_d;
}


