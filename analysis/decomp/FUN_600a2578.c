// 600a2578  FUN_600a2578  size=120 bytes
// --- callers ---
//   600a2300 FUN_600a2300
//   600a2338 FUN_600a2338
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


void FUN_600a2578(int param_1)

{
  int iVar1;
  undefined2 local_e;
  undefined4 local_c;
  
  local_c = DAT_600a25f0 + 0x68;
  for (local_e = 0; local_e < 0x1e; local_e = local_e + 1) {
    if ((*(char *)(local_c + 0x2e) != '\0') &&
       (((param_1 == 0 || (iVar1 = thunk_EXT_FUN_0000b554(local_c + 10,param_1,6), iVar1 == 0)) &&
        (*(undefined1 *)(local_c + 0x2e) = 0, *(int *)(DAT_600a25f4 + 0xb34) != 0)))) {
      (**(code **)(DAT_600a25f4 + 0xb34))(local_c + 8,0);
    }
    local_c = local_c + 0x30;
  }
  return;
}


