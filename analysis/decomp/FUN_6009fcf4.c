// 6009fcf4  FUN_6009fcf4  size=318 bytes
// --- callers ---
//   600a6d70 FUN_600a6d70
//   600a5540 FUN_600a5540
//   600f1746 FUN_600f1746
//   6009b290 FUN_6009b290
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a21e4 FUN_600a21e4
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f048a FUN_600f048a
//   6009ffa0 FUN_6009ffa0


int * FUN_6009fcf4(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int local_10;
  int *local_c;
  
  local_c = (int *)0x0;
  local_10 = 0;
  do {
    if (7 < local_10) {
LAB_6009fd52:
      if (local_c == (int *)0x0) {
        local_c = (int *)FUN_6009ffa0();
      }
      thunk_EXT_FUN_0000b5ba(local_c,0,0xfc);
      *(undefined2 *)((int)local_c + 0x2a) = 0x80;
      iVar2 = FUN_600a21e4(param_1);
      if (iVar2 == 0) {
        thunk_EXT_FUN_0000b5ba((int)local_c + 0xe6,0xff,8);
        iVar2 = thunk_EXT_FUN_0000b554(param_1,DAT_6009fe38,6);
        if (iVar2 == 0) {
          thunk_EXT_FUN_0000b572((int)local_c + 0x16,DAT_6009fe3c,3);
        }
      }
      else {
        thunk_EXT_FUN_0000b572((int)local_c + 0x16,iVar2 + 8,3);
        *(undefined1 *)(local_c + 0x39) = *(undefined1 *)(iVar2 + 0xf);
        *(undefined1 *)((int)local_c + 0x6a) = *(undefined1 *)(iVar2 + 0x11);
        thunk_EXT_FUN_0000b5ba((int)local_c + 0xe6,0xff,8);
      }
      thunk_EXT_FUN_0000b572(local_c + 4,param_1,6);
      uVar1 = FUN_600f048a(param_1,2);
      *(undefined2 *)((int)local_c + 0x5e) = uVar1;
      uVar1 = FUN_600f048a(param_1,1);
      *(undefined2 *)(local_c + 3) = uVar1;
      iVar2 = *(int *)(DAT_6009fe34 + 0x1170);
      *(int *)(DAT_6009fe34 + 0x1170) = iVar2 + 1;
      *local_c = iVar2;
      return local_c;
    }
    if ((*(ushort *)(DAT_6009fe34 + local_10 * 0xfc + 0x12f2) & 0x80) == 0) {
      local_c = (int *)(DAT_6009fe34 + local_10 * 0xfc + 0x12c8);
      thunk_EXT_FUN_0000b5ba(local_c,0,0xfc);
      goto LAB_6009fd52;
    }
    local_10 = local_10 + 1;
  } while( true );
}


