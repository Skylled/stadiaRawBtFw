// 6009fae0  FUN_6009fae0  size=526 bytes
// --- callers ---
//   600c2a28 FUN_600c2a28
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f048a FUN_600f048a
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   601024d8 FUN_601024d8
//   6009ff18 FUN_6009ff18


undefined4
FUN_6009fae0(undefined4 param_1,int param_2,char *param_3,int param_4,int param_5,int param_6,
            undefined1 param_7,undefined1 param_8)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  uint local_1c;
  int local_14;
  int local_10;
  int *local_c;
  
  bVar1 = false;
  local_c = (int *)FUN_6009ff18(param_1);
  if (local_c == (int *)0x0) {
    for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
      if ((*(ushort *)(DAT_6009fcf0 + local_10 * 0xfc + 0x12f2) & 0x80) == 0) {
        local_c = (int *)(DAT_6009fcf0 + local_10 * 0xfc + 0x12c8);
        thunk_EXT_FUN_0000b5ba(local_c,0,0xfc);
        *(undefined2 *)((int)local_c + 0x2a) = 0x80;
        thunk_EXT_FUN_0000b572(local_c + 4,param_1,6);
        uVar2 = FUN_600f048a(param_1,1);
        *(undefined2 *)(local_c + 3) = uVar2;
        thunk_EXT_FUN_0000b5ba((int)local_c + 0xe6,0xff,8);
        break;
      }
    }
    if (local_c == (int *)0x0) {
      return 0;
    }
  }
  iVar3 = *(int *)(DAT_6009fcf0 + 0x1170);
  *(int *)(DAT_6009fcf0 + 0x1170) = iVar3 + 1;
  *local_c = iVar3;
  if (param_2 != 0) {
    thunk_EXT_FUN_0000b572((int)local_c + 0x16,param_2,3);
  }
  thunk_EXT_FUN_0000b5ba(local_c + 0xb,0,0xb);
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    *(ushort *)((int)local_c + 0x2a) = *(ushort *)((int)local_c + 0x2a) | 8;
    FUN_601024d8(local_c + 0xb,param_3,10);
  }
  *(undefined1 *)((int)local_c + 0x4f) = 0;
  if (param_4 == 0) {
    thunk_EXT_FUN_0000b5ba((int)local_c + 0x37,0,0x18);
  }
  else {
    thunk_EXT_FUN_0000b572((int)local_c + 0x37,param_4,0x18);
    for (local_10 = 2; -1 < local_10; local_10 = local_10 + -1) {
      for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
        if (*(char *)((int)local_c + local_14 + local_10 * 8 + 0x37) != '\0') {
          bVar1 = true;
          break;
        }
      }
      if (bVar1) {
        *(char *)((int)local_c + 0x4f) = (char)local_10 + '\x01';
        break;
      }
    }
  }
  for (local_1c = 0; local_1c < 2; local_1c = local_1c + 1) {
    local_c[local_1c + 1] = *(int *)(param_5 + local_1c * 4);
  }
  if (param_6 != 0) {
    *(ushort *)((int)local_c + 0x2a) = *(ushort *)((int)local_c + 0x2a) | 0x10;
    thunk_EXT_FUN_0000b572((int)local_c + 0x19,param_6,0x10);
    *(undefined1 *)((int)local_c + 0x57) = param_7;
  }
  *(undefined1 *)((int)local_c + 0x5a) = param_8;
  *(byte *)(local_c + 0x39) = *(byte *)(local_c + 0x39) | 1;
  return 1;
}


