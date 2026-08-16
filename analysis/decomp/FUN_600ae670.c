// 600ae670  FUN_600ae670  size=378 bytes
// --- callers ---
//   600f6516 FUN_600f6516
// --- callees ---
//   600ff9fe FUN_600ff9fe
//   6006dbac FUN_6006dbac
//   600f6be6 FUN_600f6be6
//   600f6410 FUN_600f6410
//   600ae2e8 FUN_600ae2e8
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6006ddd8 FUN_6006ddd8


void FUN_600ae670(int param_1,char param_2,undefined2 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_34;
  undefined2 local_30;
  char local_2d;
  int local_2c;
  short local_26;
  ushort local_24;
  ushort local_22;
  int local_20;
  undefined1 *local_1c;
  int local_18;
  undefined4 *local_14;
  int local_10;
  char local_9;
  
  local_9 = 4;
  local_22 = 0;
  local_24 = 0;
  local_10 = 0;
  local_18 = DAT_600ae7ec;
  local_14 = (undefined4 *)0x0;
  local_34 = param_4;
  local_30 = param_3;
  local_2d = param_2;
  local_2c = param_1;
  local_9 = FUN_600f6410(param_2,&local_30,&local_34,0,&local_22,&local_24);
  if (local_9 == '\0') {
    local_26 = *(short *)(local_2c + 0x1a) + 0x15;
    local_10 = FUN_6006dbac(local_26,DAT_600ae7f0,0x338);
    if (local_10 == 0) {
      local_9 = -0x80;
    }
    else {
      local_9 = '\n';
      thunk_EXT_FUN_0000b5ba(local_10,0,local_26);
      local_1c = (undefined1 *)(local_10 + 0x16);
      *(char *)(local_10 + 0x15) = local_2d + '\x01';
      *(undefined2 *)(local_10 + 2) = 2;
      local_26 = *(short *)(local_2c + 0x1a) + -2;
      for (local_14 = *(undefined4 **)(local_18 + 4); local_14 != (undefined4 *)0x0;
          local_14 = (undefined4 *)*local_14) {
        iVar1 = (uint)*(byte *)((int)local_14 + 10) * 0x28 + DAT_600ae7f4;
        local_20 = iVar1 + 0xa84;
        if (((*(char *)(iVar1 + 0xaa9) != '\0') && (*(ushort *)(iVar1 + 0xaa4) <= local_24)) &&
           (local_22 <= *(ushort *)(iVar1 + 0xaa6))) {
          local_9 = FUN_600ae2e8(local_20,local_10,&local_26,local_22,local_24);
          if (local_9 == -0x80) {
            local_9 = '\0';
            break;
          }
        }
      }
      *local_1c = (char)*(undefined2 *)(local_10 + 4);
      *(undefined2 *)(local_10 + 4) = 0xd;
    }
  }
  if (local_9 == '\0') {
    FUN_600ff9fe(local_2c,local_10);
  }
  else {
    if (local_10 != 0) {
      FUN_6006ddd8(local_10,DAT_600ae7f0,0x362);
    }
    FUN_600f6be6(local_2c,local_9,local_2d,local_22,0);
  }
  return;
}


