// 600c4674  FUN_600c4674  size=224 bytes
// --- callers ---
// --- callees ---
//   600efcc6 FUN_600efcc6
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f0836 FUN_600f0836
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4
FUN_600c4674(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined1 auStack_130 [274];
  undefined1 local_1e;
  undefined1 uStack_1d;
  undefined1 auStack_1c [4];
  undefined1 *local_18;
  undefined1 local_11;
  
  thunk_EXT_FUN_0000b5ba(auStack_130,0,0x118);
  local_11 = 3;
  local_18 = auStack_130;
  FUN_600efcc6(local_18,param_1);
  thunk_EXT_FUN_0000b572(local_18 + 6,param_3,0xf8);
  local_18[0xfe] = 0;
  local_18[0xff] = 1;
  local_18[0x110] = param_5;
  local_18[0x111] = 1;
  thunk_EXT_FUN_0000b572(local_18 + 0x100,param_4,0x10);
  local_1e = 0;
  FUN_600f0836(param_1,auStack_1c,&uStack_1d);
  if (*(int *)(DAT_600c4754 + 0xe8) != 0) {
    (**(code **)(DAT_600c4754 + 0xe8))(local_11,auStack_130);
  }
  return 1;
}


