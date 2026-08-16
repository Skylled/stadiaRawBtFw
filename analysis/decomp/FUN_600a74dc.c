// 600a74dc  FUN_600a74dc  size=336 bytes
// --- callers ---
//   600f2c24 FUN_600f2c24
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600f1746 FUN_600f1746
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a3294 FUN_600a3294
//   600a8108 FUN_600a8108
//   600a804c FUN_600a804c
//   600b27e8 FUN_600b27e8


void FUN_600a74dc(undefined4 param_1,undefined4 param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_600f1746(param_1);
  bVar1 = false;
  FUN_600a804c();
  if (*(char *)(DAT_600a762c + 0x806) == '\0') {
    *(undefined1 *)(iVar2 + 0x57) = 0xff;
  }
  if (param_3 != '\x06') {
    *(char *)(iVar2 + 0x57) = param_3;
  }
  *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) | 0x10;
  *(undefined1 *)(iVar2 + 0x60) = 0x10;
  thunk_EXT_FUN_0000b572(iVar2 + 0x19,param_2,0x10);
  if ((*(char *)(DAT_600a762c + 0x118c) != '\0') &&
     (iVar3 = thunk_EXT_FUN_0000b554(DAT_600a7630,param_1,6), iVar3 == 0)) {
    if ((*(byte *)(DAT_600a762c + 0x118d) & 1) == 0) {
      FUN_600a8108(0);
    }
    else {
      bVar1 = true;
    }
  }
  if (((*(ushort *)(iVar2 + 0x2a) & 8) == 0) && ((*(byte *)(iVar2 + 0x17) & 0x1f) != 5)) {
    *(undefined1 *)(iVar2 + 0x56) = 1;
    if ((bVar1) && (iVar2 = FUN_600b27e8(param_1,1,0,0), iVar2 == 0)) {
      FUN_600a3294();
    }
  }
  else {
    if (((*(ushort *)(iVar2 + 0x54) & 0x10) == 0) && (*(int *)(DAT_600a762c + 0x1128) != 0)) {
      (**(code **)(DAT_600a762c + 0x1128))(iVar2 + 0x10,iVar2 + 0x16,iVar2 + 0x2c,0);
    }
    if (*(int *)(DAT_600a762c + 0x1120) != 0) {
      (**(code **)(DAT_600a762c + 0x1120))
                (param_1,iVar2 + 0x16,iVar2 + 0x2c,param_2,*(undefined1 *)(iVar2 + 0x57));
    }
  }
  return;
}


