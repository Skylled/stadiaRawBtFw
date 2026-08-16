// 6009cc7c  FUN_6009cc7c  size=268 bytes
// --- callers ---
//   600fd3be FUN_600fd3be
//   60069780 adapter__60069780
// --- callees ---
//   600b09f8 FUN_600b09f8
//   6009cad8 FUN_6009cad8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009e8fc FUN_6009e8fc
//   6009e84c FUN_6009e84c


undefined1 FUN_6009cc7c(ushort param_1,ushort param_2,int param_3,undefined1 param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 local_2a;
  undefined1 local_29;
  undefined4 local_28;
  undefined2 local_24;
  char local_22;
  undefined1 local_21;
  int local_20;
  undefined1 *local_1c;
  
  iVar1 = DAT_6009cd8c;
  local_1c = DAT_6009cd88;
  local_20 = DAT_6009cd8c;
  local_21 = 0;
  local_28 = 0;
  local_24 = 0;
  local_29 = 0;
  local_2a = *DAT_6009cd88;
  local_22 = *(char *)(DAT_6009cd8c + 0x12);
  if ((*(byte *)(DAT_6009cd90 + 0x81b) & 2) == 0) {
    local_21 = 5;
  }
  else if ((((param_1 < 0x20) || (0x4000 < param_1)) && (param_1 != 0xffff)) ||
          (((param_2 < 0x20 || (0x4000 < param_2)) && (param_2 != 0xffff)))) {
    local_21 = 5;
  }
  else {
    *(ushort *)(DAT_6009cd8c + 10) = param_1;
    *(ushort *)(iVar1 + 0xc) = param_2;
    *(undefined1 *)(iVar1 + 0xa4) = param_4;
    if (param_3 != 0) {
      thunk_EXT_FUN_0000b572(iVar1 + 0x13,param_3,7);
    }
    FUN_6009e8fc();
    uVar2 = FUN_6009cad8(local_20,&local_28,&local_29,&local_2a);
    *(undefined1 *)(local_20 + 0x11) = uVar2;
    FUN_600b09f8(*(undefined2 *)(local_20 + 10),*(undefined2 *)(local_20 + 0xc),
                 *(undefined1 *)(local_20 + 0x11),local_2a,local_29,&local_28,
                 *(undefined1 *)(local_20 + 0xa4),*(undefined1 *)(local_20 + 0xe));
    if (local_22 == '\x01') {
      FUN_6009e84c();
    }
  }
  return local_21;
}


