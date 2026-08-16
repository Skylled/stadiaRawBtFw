// 600ae90c  FUN_600ae90c  size=506 bytes
// --- callers ---
//   600f6516 FUN_600f6516
// --- callees ---
//   600f5130 FUN_600f5130
//   600ff9fe FUN_600ff9fe
//   6006dbac FUN_6006dbac
//   600f6be6 FUN_600f6be6
//   600f6410 FUN_600f6410
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f6b4a FUN_600f6b4a
//   6006ddd8 FUN_6006ddd8


void FUN_600ae90c(int param_1,char param_2,undefined2 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_64;
  undefined2 local_60;
  char local_5d;
  int local_5c;
  undefined1 local_56;
  undefined1 local_55;
  ushort local_54;
  ushort local_52;
  ushort local_50;
  short local_4e;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  char local_35;
  undefined4 *local_34;
  undefined1 *local_30;
  int local_2c;
  short local_26;
  undefined4 *local_24;
  char local_1d;
  int local_1c;
  
  local_26 = *(short *)(param_1 + 0x1a) + 0x15;
  local_54 = 0;
  local_1c = 0;
  local_2c = DAT_600aeb08;
  local_24 = (undefined4 *)0x0;
  local_64 = param_4;
  local_60 = param_3;
  local_5d = param_2;
  local_5c = param_1;
  local_1d = FUN_600f6410(param_2,&local_60,&local_64,&local_4c,&local_50,&local_52);
  if (local_1d == '\0') {
    local_1c = FUN_6006dbac(local_26,DAT_600aeb0c,0x3d1);
    if (local_1c == 0) {
      local_1d = -0x80;
    }
    else {
      thunk_EXT_FUN_0000b5ba(local_1c,0,local_26);
      local_30 = (undefined1 *)(local_1c + 0x16);
      *(char *)(local_1c + 0x15) = local_5d + '\x01';
      *(undefined2 *)(local_1c + 2) = 2;
      local_4e = *(short *)(local_5c + 0x1a) + -2;
      local_1d = '\n';
      for (local_24 = *(undefined4 **)(local_2c + 4); local_24 != (undefined4 *)0x0;
          local_24 = (undefined4 *)*local_24) {
        iVar1 = (uint)*(byte *)((int)local_24 + 10) * 0x28 + DAT_600aeb10;
        local_34 = (undefined4 *)(iVar1 + 0xa84);
        if (((*(char *)(iVar1 + 0xaa9) != '\0') && (*(ushort *)(iVar1 + 0xaa4) <= local_52)) &&
           (local_50 <= *(ushort *)(iVar1 + 0xaa6))) {
          FUN_600f6b4a(local_5c + 0xd,*(undefined1 *)(local_5c + 0x13),&local_55,&local_56);
          local_35 = FUN_600f5130(local_5c,*local_34,local_5d,local_1c,local_50,local_52,local_4c,
                                  uStack_48,uStack_44,uStack_40,local_3c,&local_4e,local_55,local_56
                                  ,0,&local_54);
          if ((local_35 != '\n') && (local_1d = local_35, local_35 == -0x80)) {
            local_1d = '\0';
          }
          if ((local_35 != '\0') && (local_35 != '\n')) {
            local_50 = local_54;
            break;
          }
        }
      }
      *local_30 = (char)*(undefined2 *)(local_1c + 4);
      *(undefined2 *)(local_1c + 4) = 0xd;
    }
  }
  if (local_1d == '\0') {
    FUN_600ff9fe(local_5c,local_1c);
  }
  else {
    if (local_1c != 0) {
      FUN_6006ddd8(local_1c,DAT_600aeb0c,0x413);
    }
    if ((local_1d != -0x78) && (local_1d != -0x7c)) {
      FUN_600f6be6(local_5c,local_1d,local_5d,local_50,0);
    }
  }
  return;
}


