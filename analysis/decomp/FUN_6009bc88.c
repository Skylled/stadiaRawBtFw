// 6009bc88  FUN_6009bc88  size=76 bytes
// --- callers ---
//   6009bcd8 FUN_6009bcd8
// --- callees ---
//   6009bc34 FUN_6009bc34
//   6013d168 thunk_EXT_FUN_0000b554


undefined4 FUN_6009bc88(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  int local_c;
  
  local_c = DAT_6009bcd4;
  local_10 = *(undefined1 *)(DAT_6009bcd4 + 0xc);
  local_f = *(undefined1 *)(DAT_6009bcd4 + 0xb);
  local_e = *(undefined1 *)(DAT_6009bcd4 + 10);
  if ((param_1 == 0) || (iVar1 = thunk_EXT_FUN_0000b554(param_1 + 4,&local_10,3), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    FUN_6009bc34();
    uVar2 = 1;
  }
  return uVar2;
}


