// 600c43c4  FUN_600c43c4  size=176 bytes
// --- callers ---
// --- callees ---
//   601024d8 FUN_601024d8
//   600efcc6 FUN_600efcc6


undefined4
FUN_600c43c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            byte param_5)

{
  undefined4 uVar1;
  undefined4 local_134 [2];
  undefined1 auStack_12c [6];
  undefined1 auStack_126 [248];
  undefined1 local_2e;
  byte local_2d;
  byte local_11;
  
  local_11 = 1;
  local_134[0] = param_1;
  FUN_600efcc6(auStack_12c,param_1,auStack_12c,local_134,param_4);
  FUN_601024d8(auStack_126,param_3,0xf8);
  local_2e = 0;
  do {
    if (0x1e < local_11) {
LAB_600c4442:
      if ((*(int *)(DAT_600c4478 + 0xe8) == 0) || (0x1e < local_11)) {
        uVar1 = 0xb;
      }
      else {
        (**(code **)(DAT_600c4478 + 0xe8))(4,auStack_12c);
        uVar1 = 1;
      }
      return uVar1;
    }
    if (*(uint *)(DAT_600c4474 + (uint)local_11 * 4) == (uint)param_5) {
      local_2d = local_11;
      goto LAB_600c4442;
    }
    local_11 = local_11 + 1;
  } while( true );
}


