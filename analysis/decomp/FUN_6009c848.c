// 6009c848  FUN_6009c848  size=196 bytes
// --- callers ---
//   600b076c FUN_600b076c
// --- callees ---
//   6009e84c FUN_6009e84c
//   6009e8fc FUN_6009e8fc
//   6009cad8 FUN_6009cad8
//   600b09f8 FUN_600b09f8


undefined4 FUN_6009c848(char param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  undefined4 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  char local_1d;
  int local_1c;
  
  local_1c = DAT_6009c90c;
  local_1e = 0;
  local_24 = 0;
  local_20 = 0;
  local_1d = *(char *)(DAT_6009c90c + 0x12);
  if ((*(byte *)(DAT_6009c910 + 0x81b) & 2) == 0) {
    uVar3 = 0;
  }
  else {
    if (param_1 != *(char *)(DAT_6009c90c + 0xe)) {
      *(char *)(DAT_6009c90c + 0xe) = param_1;
      FUN_6009e8fc();
      uVar1 = FUN_6009cad8(local_1c,&local_24,&local_1e,local_1c + 0x10);
      *(undefined1 *)(local_1c + 0x11) = uVar1;
      if (*(short *)(local_1c + 10) == 0) {
        uVar2 = 0x800;
      }
      else {
        uVar2 = *(undefined2 *)(local_1c + 10);
      }
      if (*(short *)(local_1c + 0xc) == 0) {
        uVar4 = 0x800;
      }
      else {
        uVar4 = *(undefined2 *)(local_1c + 0xc);
      }
      FUN_600b09f8(uVar2,uVar4,*(undefined1 *)(local_1c + 0x11),*(undefined1 *)(local_1c + 0x10),
                   local_1e,&local_24,*(undefined1 *)(local_1c + 0xa4),
                   *(undefined1 *)(local_1c + 0xe));
      if (local_1d == '\x01') {
        FUN_6009e84c();
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}


