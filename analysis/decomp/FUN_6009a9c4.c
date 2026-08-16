// 6009a9c4  FUN_6009a9c4  size=376 bytes
// --- callers ---
//   600fd252 FUN_600fd252
// --- callees ---
//   601024d8 FUN_601024d8
//   6009ff18 FUN_6009ff18
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f048a FUN_600f048a
//   600a21e4 FUN_600a21e4
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 FUN_6009a9c4(undefined4 param_1,char *param_2,byte param_3,undefined1 param_4)

{
  undefined2 uVar1;
  int iVar2;
  byte local_d;
  int local_c;
  
  local_c = FUN_6009ff18(param_1);
  if (local_c == 0) {
    for (local_d = 0; local_d < 8; local_d = local_d + 1) {
      if ((*(ushort *)(DAT_6009ab3c + (uint)local_d * 0xfc + 0x12f2) & 0x80) == 0) {
        local_c = DAT_6009ab3c + (uint)local_d * 0xfc + 0x12c8;
        thunk_EXT_FUN_0000b5ba(local_c,0,0xfc);
        *(undefined2 *)(local_c + 0x2a) = 0x80;
        thunk_EXT_FUN_0000b572(local_c + 0x10,param_1,6);
        uVar1 = FUN_600f048a(param_1,1);
        *(undefined2 *)(local_c + 0xc) = uVar1;
        uVar1 = FUN_600f048a(param_1,2);
        *(undefined2 *)(local_c + 0x5e) = uVar1;
        *(undefined2 *)(local_c + 0xea) = 0xffff;
        *(undefined2 *)(local_c + 0xec) = *(undefined2 *)(local_c + 0xea);
        *(undefined2 *)(local_c + 0xe8) = *(undefined2 *)(local_c + 0xec);
        *(undefined2 *)(local_c + 0xe6) = *(undefined2 *)(local_c + 0xe8);
        break;
      }
    }
    if (local_c == 0) {
      return 0;
    }
  }
  thunk_EXT_FUN_0000b5ba(local_c + 0x2c,0,0xb);
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    *(ushort *)(local_c + 0x2a) = *(ushort *)(local_c + 0x2a) | 8;
    FUN_601024d8(local_c + 0x2c,param_2,10);
  }
  *(byte *)(local_c + 0xe4) = param_3 | *(byte *)(local_c + 0xe4);
  *(undefined1 *)(local_c + 0x6a) = param_4;
  thunk_EXT_FUN_0000b572(local_c + 100,param_1,6);
  iVar2 = FUN_600a21e4(param_1);
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 0x11) = *(undefined1 *)(local_c + 0x6a);
    *(undefined1 *)(iVar2 + 0xf) = *(undefined1 *)(local_c + 0xe4);
  }
  return 1;
}


