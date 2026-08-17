// 600b542c  FUN_600b542c  size=162 bytes
// --- callers ---
//   600fcf26 FUN_600fcf26
//   600f592e FUN_600f592e
// --- callees ---
//   600bb6dc FUN_600bb6dc
//   600bc00c FUN_600bc00c


undefined4 FUN_600b542c(ushort param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_9;
  
  local_9 = 1;
  if (((param_1 < 4) || (7 < param_1)) ||
     (*(int *)((param_1 - 4) * 0x1c + DAT_600b54d0 + 0xed4) == 0)) {
    uVar2 = 0;
  }
  else {
    if ((3 < param_1) && (param_1 < 7)) {
      local_9 = 2;
    }
    iVar1 = FUN_600bb6dc(param_2,local_9);
    if ((iVar1 == 0) || (*(int *)(iVar1 + (param_1 + 0x20) * 4) == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + (param_1 + 0x20) * 4);
      *(undefined4 *)(iVar1 + (param_1 + 0x20) * 4) = 0;
      *(undefined2 *)(iVar1 + 0x30) = 0x16;
      FUN_600bc00c(uVar2);
      uVar2 = 1;
    }
  }
  return uVar2;
}


