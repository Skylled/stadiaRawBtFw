// 600c4808  FUN_600c4808  size=698 bytes
// --- callers ---
// --- callees ---
//   600d918c thunk_FUN_6006c4bc
//   601024d8 FUN_601024d8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d9186 FUN_600d9186
//   600d9176 FUN_600d9176
//   600f1800 FUN_600f1800
//   600efcc6 FUN_600efcc6


undefined1 FUN_600c4808(undefined1 param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_12c [6];
  undefined1 local_126;
  undefined1 local_125;
  undefined1 local_124;
  undefined1 auStack_123 [248];
  undefined1 local_2b;
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_12;
  undefined1 local_11;
  
  local_11 = 1;
  local_12 = 0xb;
  if (*(int *)(DAT_600c4aec + 0xe8) == 0) {
    return 0xb;
  }
  switch(param_1) {
  case 0:
    FUN_600d9176(param_2,param_2 + 6,param_2 + 7,param_2 + 8,*(undefined1 *)(param_2 + 9));
    local_11 = 0;
    break;
  case 1:
    FUN_600d9186(param_2,*(undefined1 *)(param_2 + 6),*(undefined1 *)(param_2 + 7),
                 *(undefined1 *)(param_2 + 8));
    break;
  case 2:
    local_12 = 10;
    local_24 = *(undefined1 *)(param_2 + 0x18);
    *(undefined1 *)(DAT_600c4aec + 0x284) = local_24;
    local_23 = *(undefined1 *)(param_2 + 0x19);
    local_22 = *(undefined1 *)(param_2 + 0x1a);
  case 3:
    local_28 = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(DAT_600c4aec + 0x280) = local_28;
    if (*(char *)(param_2 + 9) == '\0') {
      *(undefined1 *)(DAT_600c4aec + 0x27d) = local_12;
      FUN_600efcc6(DAT_600c4af0,param_2);
      *(undefined1 *)(DAT_600c4aec + 0x27a) = *(undefined1 *)(param_2 + 6);
      *(undefined1 *)(DAT_600c4aec + 0x27b) = *(undefined1 *)(param_2 + 7);
      *(undefined1 *)(DAT_600c4aec + 0x27c) = *(undefined1 *)(param_2 + 8);
      iVar1 = FUN_600f1800(param_2,DAT_600c4af4,1);
      if (iVar1 == 1) {
        return 1;
      }
    }
    FUN_600efcc6(auStack_12c,param_2);
    local_126 = *(undefined1 *)(param_2 + 6);
    local_125 = *(undefined1 *)(param_2 + 7);
    local_124 = *(undefined1 *)(param_2 + 8);
    FUN_601024d8(auStack_123,param_2 + 9,0xf8);
    local_2b = 0;
    (**(code **)(DAT_600c4aec + 0xe8))(local_12,auStack_12c);
    break;
  case 4:
    local_12 = 0x1a;
    if (*(char *)(param_2 + 9) == '\0') {
      *(undefined1 *)(DAT_600c4aec + 0x27d) = 0x1a;
      FUN_600efcc6(DAT_600c4af0,param_2);
      *(undefined1 *)(DAT_600c4aec + 0x27a) = *(undefined1 *)(param_2 + 6);
      *(undefined1 *)(DAT_600c4aec + 0x27b) = *(undefined1 *)(param_2 + 7);
      *(undefined1 *)(DAT_600c4aec + 0x27c) = *(undefined1 *)(param_2 + 8);
      iVar1 = FUN_600f1800(param_2,DAT_600c4af4,1);
      if (iVar1 == 1) {
        return 1;
      }
    }
    FUN_600efcc6(auStack_12c,param_2);
    local_126 = *(undefined1 *)(param_2 + 6);
    local_125 = *(undefined1 *)(param_2 + 7);
    local_124 = *(undefined1 *)(param_2 + 8);
    FUN_601024d8(auStack_123,param_2 + 9,0xf8);
    local_2b = 0;
    (**(code **)(DAT_600c4aec + 0xe8))(local_12,auStack_12c);
    break;
  case 5:
    thunk_EXT_FUN_0000b572(auStack_12c,param_2,7);
    (**(code **)(DAT_600c4aec + 0xe8))(0xd,auStack_12c);
    break;
  default:
    local_11 = 0xb;
    break;
  case 8:
    break;
  case 9:
    thunk_FUN_6006c4bc(param_2,param_2 + 6);
  }
  return local_11;
}


