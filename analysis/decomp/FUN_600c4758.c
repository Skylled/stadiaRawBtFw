// 600c4758  FUN_600c4758  size=170 bytes
// --- callers ---
// --- callees ---
//   600f0836 FUN_600f0836
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600efcc6 FUN_600efcc6


undefined4 FUN_600c4758(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 auStack_128 [6];
  undefined1 auStack_122 [248];
  undefined1 local_2a;
  undefined1 local_16;
  undefined1 uStack_15;
  undefined1 auStack_14 [8];
  
  if (param_4 != 0) {
    thunk_EXT_FUN_0000b5ba(auStack_128,0,0x118);
    FUN_600efcc6(auStack_128,param_1);
    thunk_EXT_FUN_0000b572(auStack_122,param_3,0xf8);
    local_2a = 0;
    FUN_600f0836(param_1,auStack_14,&uStack_15);
    local_16 = (undefined1)param_4;
    if (*(int *)(DAT_600c4804 + 0xe8) != 0) {
      (**(code **)(DAT_600c4804 + 0xe8))(3,auStack_128);
    }
  }
  return 0;
}


