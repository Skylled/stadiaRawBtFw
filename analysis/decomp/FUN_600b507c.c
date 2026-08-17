// 600b507c  FUN_600b507c  size=78 bytes
// --- callers ---
//   600c1738 FUN_600c1738
// --- callees ---


undefined4 FUN_600b507c(ushort param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((param_1 < 4) || (7 < param_1)) {
    uVar2 = 0;
  }
  else {
    iVar3 = (param_1 - 4) * 0x1c + DAT_600b50cc;
    uVar2 = param_2[1];
    uVar1 = param_2[2];
    uVar4 = param_2[3];
    *(undefined4 *)(iVar3 + 0xed0) = *param_2;
    *(undefined4 *)(iVar3 + 0xed4) = uVar2;
    *(undefined4 *)(iVar3 + 0xed8) = uVar1;
    *(undefined4 *)(iVar3 + 0xedc) = uVar4;
    uVar2 = param_2[5];
    uVar1 = param_2[6];
    *(undefined4 *)(iVar3 + 0xee0) = param_2[4];
    *(undefined4 *)(iVar3 + 0xee4) = uVar2;
    *(undefined4 *)(iVar3 + 0xee8) = uVar1;
    uVar2 = 1;
  }
  return uVar2;
}


