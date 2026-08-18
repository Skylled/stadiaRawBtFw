// 600d15e8  FUN_600d15e8  size=16 bytes
// --- callers ---
//   600555d4 FUN_600555d4
//   600550e4 FUN_600550e4
//   600d0724 FUN_600d0724
//   60054fb0 FUN_60054fb0
//   600d1662 FUN_600d1662
//   600557e8 FUN_600557e8
//   60055730 FUN_60055730
//   600d0590 FUN_600d0590
//   60054fec FUN_60054fec
//   60054f7c FUN_60054f7c
//   600d15f8 FUN_600d15f8
//   600d0f14 FUN_600d0f14
//   600d31e6 FUN_600d31e6
//   60055350 FUN_60055350
//   600d0624 FUN_600d0624
//   600d0790 FUN_600d0790
//   60057ee4 FUN_60057ee4
//   60055024 FUN_60055024
//   600d0ef2 FUN_600d0ef2
// --- callees ---
//   6013d000 thunk_EXT_FUN_00007dac


void FUN_600d15e8(undefined4 param_1)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getCurrentExceptionNumber();
    uVar2 = uVar2 & 0x1f;
  }
  if (uVar2 != 0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(param_1);
    }
    return;
  }
  thunk_EXT_FUN_00007dac();
  return;
}


