// 600f0836  FUN_600f0836  size=218 bytes
// --- callers ---
//   600987dc FUN_600987dc
//   600c4758 FUN_600c4758
//   600c4674 FUN_600c4674
//   600f1148 FUN_600f1148
//   600f1ad4 FUN_600f1ad4
//   600f0910 FUN_600f0910
//   600bc480 FUN_600bc480
//   600c3f04 FUN_600c3f04
//   600c5908 FUN_600c5908
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600a21e4 FUN_600a21e4
//   6009ff18 FUN_6009ff18


void FUN_600f0836(undefined4 param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_6009ff18(param_1);
  iVar2 = FUN_600a21e4(param_1);
  *param_3 = 0;
  if (iVar1 == 0) {
    *param_2 = 1;
    if (iVar2 != 0) {
      *param_2 = *(undefined1 *)(iVar2 + 0xf);
      *param_3 = *(undefined1 *)(iVar2 + 0x11);
    }
  }
  else {
    if (iVar2 != 0) {
      *(undefined1 *)(iVar1 + 0xe4) = *(undefined1 *)(iVar2 + 0xf);
      *(undefined1 *)(iVar1 + 0x6a) = *(undefined1 *)(iVar2 + 0x11);
    }
    iVar2 = thunk_EXT_FUN_0000b554(iVar1 + 0x10,param_1,6);
    if ((iVar2 == 0) && (iVar2 = thunk_EXT_FUN_0000b554(iVar1 + 100,param_1,6), iVar2 == 0)) {
      *param_2 = *(undefined1 *)(iVar1 + 0xe4);
      *param_3 = *(undefined1 *)(iVar1 + 0x6a);
    }
    else {
      iVar2 = thunk_EXT_FUN_0000b554(iVar1 + 100,param_1,6);
      if (iVar2 == 0) {
        *param_2 = 2;
        *param_3 = *(undefined1 *)(iVar1 + 0x6a);
      }
      else {
        *param_2 = 1;
        *param_3 = 0;
      }
    }
  }
  return;
}


