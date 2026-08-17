// 6009a154  FUN_6009a154  size=128 bytes
// --- callers ---
//   600f23ec FUN_600f23ec
//   600a96d8 FUN_600a96d8
// --- callees ---
//   600aa3cc FUN_600aa3cc
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_6009a154(undefined1 param_1,undefined2 param_2,undefined1 *param_3)

{
  undefined1 local_28;
  undefined1 local_27;
  undefined4 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 local_10;
  undefined1 local_e;
  code *local_c;
  
  local_c = *(code **)(DAT_6009a1d4 + 0x7c4);
  FUN_600aa3cc(DAT_6009a1d8);
  *(undefined4 *)(DAT_6009a1d4 + 0x7c4) = 0;
  if (local_c != (code *)0x0) {
    thunk_EXT_FUN_0000b5ba(&local_28,0,0x1c);
    if (param_3 != (undefined1 *)0x0) {
      local_28 = *param_3;
      local_27 = param_3[1];
      local_24 = *(undefined4 *)(param_3 + 4);
      local_1c = *(undefined4 *)(param_3 + 0xc);
      local_18 = *(undefined4 *)(param_3 + 0x10);
      local_14 = *(undefined4 *)(param_3 + 0x14);
    }
    local_10 = param_2;
    local_e = param_1;
    (*local_c)(&local_28);
  }
  return;
}


