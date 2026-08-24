// 600f1ce4  FUN_600f1ce4  size=194 bytes
// --- callers ---
//   600a4820 FUN_600a4820
//   600a7268 FUN_600a7268
//   600a65f4 FUN_600a65f4
//   600a76cc FUN_600a76cc
//   600a4a20 FUN_600a4a20
//   600a67ec FUN_600a67ec
// --- callees ---
//   600b218c FUN_600b218c


undefined1 FUN_600f1ce4(int param_1,undefined1 param_2,short param_3)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 local_9;
  
  cVar1 = *(char *)(param_1 + 0x50);
  local_9 = 1;
  if (cVar1 == '\b') {
    if (param_3 == *(short *)(param_1 + 0x5e)) {
      return 1;
    }
    *(undefined1 *)(param_1 + 0x50) = 9;
  }
  else {
    if (cVar1 == '\t') {
      return 1;
    }
    if (cVar1 == '\x06') {
      if (param_3 == *(short *)(param_1 + 0xc)) {
        return 1;
      }
      *(undefined1 *)(param_1 + 0x50) = 9;
    }
    else {
      if (param_3 == *(short *)(param_1 + 0xc)) {
        uVar3 = 6;
      }
      else {
        uVar3 = 8;
      }
      *(undefined1 *)(param_1 + 0x50) = uVar3;
    }
  }
  if ((*(char *)(param_1 + 0xee) == '\x01') && (param_3 == *(short *)(param_1 + 0xc))) {
    *(undefined1 *)(param_1 + 0xee) = 2;
    local_9 = 0;
  }
  else {
    iVar2 = FUN_600b218c(param_3,param_2);
    if (iVar2 == 0) {
      *(char *)(param_1 + 0x50) = cVar1;
      local_9 = 3;
    }
  }
  return local_9;
}


