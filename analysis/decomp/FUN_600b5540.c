// 600b5540  FUN_600b5540  size=364 bytes
// --- callers ---
//   600f7cea FUN_600f7cea
// --- callees ---
//   600f1746 FUN_600f1746
//   600bc880 FUN_600bc880
//   600aa3cc FUN_600aa3cc
//   600a7268 FUN_600a7268
//   600bb44c FUN_600bb44c
//   600bb6dc FUN_600bb6dc


void FUN_600b5540(undefined2 param_1,undefined4 param_2,undefined4 param_3,ushort param_4,
                 ushort param_5,ushort param_6)

{
  int iVar1;
  int iVar2;
  int local_14;
  
  iVar1 = FUN_600f1746(param_2);
  *(undefined1 *)(DAT_600b5718 + 0xf42) = 0;
  local_14 = FUN_600bb6dc(param_2,2);
  if (local_14 == 0) {
    local_14 = FUN_600bb44c(param_2,0,2);
    if (local_14 == 0) {
      FUN_600a7268(param_1,2);
      return;
    }
    iVar2 = FUN_600bc880(local_14,4,DAT_600b571c);
    if (iVar2 == 0) {
      FUN_600a7268(param_1,2);
      return;
    }
  }
  else if (*(char *)(local_14 + 1) != '\x03') {
    return;
  }
  FUN_600aa3cc(local_14 + 0x44);
  *(undefined2 *)(local_14 + 2) = param_1;
  *(undefined1 *)(local_14 + 10) = 0;
  *(undefined1 *)(local_14 + 0x32) = 2;
  *(ushort *)(local_14 + 0x3c) = param_4;
  *(undefined2 *)(local_14 + 0x3a) = *(undefined2 *)(local_14 + 0x3c);
  *(ushort *)(local_14 + 0x40) = param_6;
  *(ushort *)(local_14 + 0x3e) = param_5;
  *(undefined1 *)(local_14 + 0x38) = 8;
  if ((((((5 < *(ushort *)(iVar1 + 0xe6)) && (*(ushort *)(iVar1 + 0xe6) < 0xc81)) &&
        (5 < *(ushort *)(iVar1 + 0xe8))) &&
       ((*(ushort *)(iVar1 + 0xe8) < 0xc81 && (*(ushort *)(iVar1 + 0xea) < 0x1f5)))) &&
      ((9 < *(ushort *)(iVar1 + 0xec) && (*(ushort *)(iVar1 + 0xec) < 0xc81)))) &&
     ((((param_4 < *(ushort *)(iVar1 + 0xe6) && (*(short *)(iVar1 + 0xe6) != -1)) ||
       (*(ushort *)(iVar1 + 0xe8) < param_4)) ||
      ((*(ushort *)(iVar1 + 0xea) < param_5 || (*(ushort *)(iVar1 + 0xec) < param_6)))))) {
    *(undefined2 *)(local_14 + 0x3a) = *(undefined2 *)(iVar1 + 0xe6);
    *(undefined2 *)(local_14 + 0x3c) = *(undefined2 *)(iVar1 + 0xe8);
    *(undefined2 *)(local_14 + 0x40) = *(undefined2 *)(iVar1 + 0xec);
    *(undefined2 *)(local_14 + 0x3e) = *(undefined2 *)(iVar1 + 0xea);
    FUN_600b1124(param_1,*(undefined2 *)(iVar1 + 0xe6),*(undefined2 *)(iVar1 + 0xe8),
                 *(undefined2 *)(iVar1 + 0xea),*(undefined2 *)(iVar1 + 0xec),0,0);
  }
  FUN_60098f88(param_2,0,iVar1 + 0x2c,param_1,*(undefined1 *)(local_14 + 10),2);
  FUN_6009c790(0);
  FUN_6009f644(1,1);
  return;
}


