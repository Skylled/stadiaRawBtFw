// 600aae30  FUN_600aae30  size=182 bytes
// --- callers ---
//   600f34ac FUN_600f34ac
//   600f34ca FUN_600f34ca
// --- callees ---
//   600f3c42 FUN_600f3c42
//   600aa6f0 FUN_600aa6f0
//   600aa7a0 FUN_600aa7a0
//   600aa858 FUN_600aa858
//   600f322e FUN_600f322e
//   600f3e6a FUN_600f3e6a


undefined1 FUN_600aae30(undefined4 param_1,short param_2,int param_3)

{
  int iVar1;
  undefined1 local_d;
  int local_c;
  
  if ((param_3 == 0) && (param_2 != 0x2a04)) {
    local_d = 0;
  }
  else {
    local_c = FUN_600aa6f0(param_1);
    if ((local_c == 0) && (local_c = FUN_600aa7a0(param_1), local_c == 0)) {
      local_d = 0;
    }
    else {
      iVar1 = FUN_600f3e6a(*(undefined1 *)(DAT_600aaee8 + 0x140),param_1,local_c + 0xc,2);
      if (iVar1 != 0) {
        *(undefined1 *)(local_c + 0x11) = 1;
      }
      iVar1 = FUN_600f3c42(*(undefined1 *)(DAT_600aaee8 + 0x140),local_c,1,2);
      if (iVar1 == 0) {
        local_d = 0;
      }
      else {
        FUN_600aa858(local_c,param_2,param_3);
        if ((*(char *)(local_c + 0x11) == '\0') || (*(short *)(local_c + 0xe) != 0)) {
          local_d = 1;
        }
        else {
          local_d = FUN_600f322e(local_c);
        }
      }
    }
  }
  return local_d;
}


