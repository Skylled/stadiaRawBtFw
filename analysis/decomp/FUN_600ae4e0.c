// 600ae4e0  FUN_600ae4e0  size=396 bytes
// --- callers ---
//   600f6516 FUN_600f6516
// --- callees ---
//   600ff9fe FUN_600ff9fe
//   600f6410 FUN_600f6410
//   600ae0dc FUN_600ae0dc
//   600f68f0 FUN_600f68f0
//   6006ddd8 FUN_6006ddd8
//   600af9fc FUN_600af9fc
//   600f6be6 FUN_600f6be6
//   6006dbac FUN_6006dbac
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600ae4e0(int param_1,char param_2,undefined2 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_74;
  undefined2 local_70;
  char local_6d;
  int local_6c;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined2 local_26;
  undefined2 local_24;
  short local_22;
  int local_20;
  char local_19;
  
  local_19 = 4;
  local_24 = 0;
  local_26 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_64 = 2;
  local_60 = 0x2800;
  local_20 = 0;
  local_22 = *(short *)(param_1 + 0x1a) + 0x15;
  local_74 = param_4;
  local_70 = param_3;
  local_6d = param_2;
  local_6c = param_1;
  thunk_EXT_FUN_0000b5ba(&local_50,0,0x14);
  local_19 = FUN_600f6410(local_6d,&local_70,&local_74,&local_3c,&local_24,&local_26);
  if (local_19 == '\0') {
    iVar1 = FUN_600f68f0(local_3c,uStack_38,uStack_34,uStack_30,local_2c,local_64,local_60,local_5c,
                         local_58,local_54);
    if (iVar1 == 0) {
      if (local_6d == '\x10') {
        local_19 = '\x10';
      }
      else {
        local_19 = '\n';
      }
    }
    else {
      if ((local_6d == '\x06') && (iVar1 = FUN_600af9fc(&local_50,local_70,&local_74), iVar1 == 0))
      {
        local_19 = '\x04';
      }
      if (local_19 == '\0') {
        local_20 = FUN_6006dbac(local_22,DAT_600ae66c,0x2f9);
        if (local_20 == 0) {
          local_19 = -0x80;
        }
        else {
          thunk_EXT_FUN_0000b5ba(local_20,0,local_22);
          local_19 = FUN_600ae0dc(local_20,local_6c,local_6d,local_24,local_26,local_74,local_50,
                                  uStack_4c,uStack_48,uStack_44,local_40);
        }
      }
    }
  }
  if (local_19 == '\0') {
    FUN_600ff9fe(local_6c,local_20);
  }
  else {
    if (local_20 != 0) {
      FUN_6006ddd8(local_20,DAT_600ae66c,0x317);
    }
    FUN_600f6be6(local_6c,local_19,local_6d,local_24,0);
  }
  return;
}


