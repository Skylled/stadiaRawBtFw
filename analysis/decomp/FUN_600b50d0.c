// 600b50d0  FUN_600b50d0  size=398 bytes
// --- callers ---
//   600f58c8 FUN_600f58c8
//   600f131c FUN_600f131c
//   600c0578 FUN_600c0578
// --- callees ---
//   600a01a0 FUN_600a01a0
//   600bb534 FUN_600bb534
//   600bc480 FUN_600bc480
//   600bc880 FUN_600bc880
//   600bb44c FUN_600bb44c
//   600bb6dc FUN_600bb6dc


undefined4 FUN_600b50d0(ushort param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  byte local_12;
  char local_11;
  
  local_11 = '\x01';
  if (((param_1 < 4) || (7 < param_1)) ||
     (*(int *)((param_1 - 4) * 0x1c + DAT_600b5260 + 0xed4) == 0)) {
    return 0;
  }
  iVar1 = FUN_600a01a0();
  if (iVar1 == 0) {
    return 0;
  }
  if ((3 < param_1) && (param_1 < 7)) {
    local_11 = '\x02';
  }
  iVar1 = FUN_600bb6dc(param_2,local_11);
  if (iVar1 == 0) {
    iVar1 = FUN_600bb44c(param_2,0,local_11);
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = FUN_600bc880(iVar1,param_1,(param_1 - 4) * 0x1c + DAT_600b5260 + 0xedc);
    if (iVar2 == 0) {
      *(undefined2 *)(iVar1 + 0x30) = 4;
      FUN_600bb534(iVar1);
      return 0;
    }
    iVar2 = FUN_600bc480(iVar1,local_11);
    if (iVar2 == 0) {
      FUN_600bb534(iVar1);
      return 0;
    }
    return 1;
  }
  if ((*(char *)(iVar1 + 1) == '\x04') || (*(char *)(iVar1 + 1) == '\x05')) {
    local_12 = *(byte *)(iVar1 + 0x24);
    if (local_11 == '\x02') {
      local_12 = *(byte *)(DAT_600b5260 + 0xf4e);
    }
    if (((int)(uint)local_12 >> (param_1 & 0xff) & 1U) == 0) {
      return 0;
    }
  }
  iVar2 = FUN_600bc880(iVar1,param_1,(param_1 - 4) * 0x1c + DAT_600b5260 + 0xedc);
  if (iVar2 == 0) {
    return 0;
  }
  if (*(char *)(iVar1 + 1) == '\x05') {
    *(undefined4 *)(iVar1 + 100) = *(undefined4 *)(iVar1 + (param_1 + 0x20) * 4);
    return 1;
  }
  if (*(char *)(iVar1 + 1) == '\x04') {
    (**(code **)((param_1 - 4) * 0x1c + DAT_600b5260 + 0xed0))
              (iVar1 + 4,1,0,*(undefined1 *)(iVar1 + 0x32));
  }
  return 1;
}


