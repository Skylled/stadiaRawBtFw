// 6005ded8  FUN_6005ded8  size=114 bytes
// --- callers ---
// --- callees ---
//   60065eb8 keys__60065eb8
//   60065df0 keys__60065df0
//   600822e8 FUN_600822e8
//   600dfa42 FUN_600dfa42


uint FUN_6005ded8(void)

{
  uint uVar1;
  int iVar2;
  ushort local_12e;
  undefined1 auStack_12c [16];
  undefined1 auStack_11c [4];
  undefined1 local_118;
  undefined1 local_114;
  undefined1 local_110;
  undefined1 auStack_108 [256];
  
  local_12e = 0;
  uVar1 = keys__60065df0(0x3c,&local_12e);
  if ((uVar1 & 0xff) == 0) {
    if (local_12e < 0x101) {
      uVar1 = keys__60065eb8(0x3c,auStack_108,0x100);
      if ((uVar1 & 0xff) == 0) {
        FUN_600822e8(auStack_12c,auStack_108,local_12e);
        iVar2 = FUN_600dfa42(auStack_12c,DAT_6005df4c,auStack_11c);
        if (iVar2 == 0) {
          uVar1 = 0xd;
        }
        else {
          *DAT_6005df50 = local_118;
          *DAT_6005df54 = local_114;
          *DAT_6005df58 = local_110;
          uVar1 = 0;
        }
      }
    }
    else {
      uVar1 = 0xf;
    }
  }
  return uVar1;
}


