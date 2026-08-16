// 600a30f0  FUN_600a30f0  size=414 bytes
// --- callers ---
//   600a96d8 FUN_600a96d8
//   600a3294 FUN_600a3294
//   600f14f8 FUN_600f14f8
//   600f2202 FUN_600f2202
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   6009decc FUN_6009decc
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600aa3cc FUN_600aa3cc
//   600f0910 FUN_600f0910
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600a30f0(int param_1,undefined1 *param_2,ushort param_3,char param_4)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *local_130;
  undefined2 local_124;
  undefined1 auStack_122 [6];
  ushort local_11c;
  undefined1 local_11a [250];
  code *local_20;
  undefined4 *local_1c;
  ushort local_16;
  undefined1 *local_14;
  
  local_1c = DAT_600a3290;
  local_20 = (code *)*DAT_600a3290;
  if ((*(char *)((int)DAT_600a3290 + 0x32) == '\x01') &&
     (((param_1 != 0 && (iVar2 = thunk_EXT_FUN_0000b554(param_1,DAT_600a3290 + 0xb,6), iVar2 == 0))
      || (param_1 == 0)))) {
    iVar2 = FUN_600f0910(local_1c + 0xb);
    if ((iVar2 != 0) && (param_4 == '\x1f')) {
      FUN_6009decc(local_1c + 0xb);
    }
    FUN_600aa3cc(local_1c + 1);
    *(undefined1 *)((int)local_1c + 0x32) = 0;
    if (param_1 != 0) {
      thunk_EXT_FUN_0000b572(auStack_122,param_1,6);
    }
    if (param_4 == '\0') {
      local_14 = local_11a;
      if (0xf7 < param_3) {
        param_3 = 0xf8;
      }
      local_11a[param_3] = 0;
      local_124 = 0;
      local_130 = param_2;
      for (local_16 = param_3; local_16 != 0; local_16 = local_16 - 1) {
        puVar1 = local_14 + 1;
        *local_14 = *local_130;
        local_14 = puVar1;
        local_130 = local_130 + 1;
      }
      local_11a[param_3] = 0;
      local_11c = param_3;
    }
    else {
      local_124 = 9;
      local_11c = 0;
      local_11a[0] = 0;
    }
    thunk_EXT_FUN_0000b5ba(local_1c + 0xb,0,6);
    *local_1c = 0;
    if (local_20 != (code *)0x0) {
      (*local_20)(&local_124);
    }
  }
  return;
}


