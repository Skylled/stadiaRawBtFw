// 600c07e4  FUN_600c07e4  size=218 bytes
// --- callers ---
//   600c09f0 FUN_600c09f0
// --- callees ---
//   600fbc02 FUN_600fbc02
//   600fc9fc FUN_600fc9fc
//   6013d3a0 thunk_EXT_FUN_0000b572


bool FUN_600c07e4(undefined4 param_1,undefined4 param_2,ushort param_3)

{
  int iVar1;
  bool bVar2;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [16];
  int local_10;
  char local_a;
  byte local_9;
  
  local_9 = 1;
  local_a = '\0';
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  do {
    if (*(ushort *)((int)DAT_600c08c0 + 6) < (ushort)local_9) {
LAB_600c088a:
      bVar2 = local_a == '\0';
      if (bVar2) {
        local_10 = (int)&local_10 - (uint)param_3;
        thunk_EXT_FUN_0000b572(param_2,local_10,param_3);
      }
      return bVar2;
    }
    FUN_600fc9fc(*DAT_600c08c0 + ((uint)*(ushort *)((int)DAT_600c08c0 + 6) - (uint)local_9) * 0x10,
                 &local_34);
    iVar1 = FUN_600fbc02(param_1,0x10,
                         ((uint)*(ushort *)((int)DAT_600c08c0 + 6) - (uint)local_9) * 0x10 +
                         *DAT_600c08c0,0x10,auStack_24);
    if (iVar1 == 0) {
      local_a = '\x01';
      goto LAB_600c088a;
    }
    thunk_EXT_FUN_0000b572(&local_34,auStack_20,0x10);
    local_9 = local_9 + 1;
  } while( true );
}


