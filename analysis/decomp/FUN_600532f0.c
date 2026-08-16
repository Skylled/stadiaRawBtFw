// 600532f0  FUN_600532f0  size=278 bytes
// --- callers ---
//   6005fe04 io_pin__6005fe04
// --- callees ---
//   600cedd8 FUN_600cedd8


void FUN_600532f0(int param_1,uint param_2,char *param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else if (param_1 == DAT_6005338c) {
    iVar3 = 1;
  }
  else if (param_1 == DAT_6005338c + 0x4000) {
    iVar3 = 2;
  }
  else if (param_1 == DAT_6005338c + 0x8000) {
    iVar3 = 3;
  }
  else if (param_1 == DAT_6005338c + 0xc000) {
    iVar3 = 4;
  }
  else if (param_1 == DAT_6005338c + -0xf8000) {
    iVar3 = 5;
  }
  else {
    iVar3 = 6;
  }
  uVar4 = (uint)*(short *)(DAT_60053390 + iVar3 * 2);
  uVar2 = uVar4 >> 8;
  uVar6 = 1 << (param_2 & 0xff);
  *(uint *)(DAT_60053394 + uVar2 * 4) = 3 << (uVar4 & 0x1f) | *(uint *)(DAT_60053394 + uVar2 * 4);
  uVar2 = ~uVar6;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & uVar2;
  if (*param_3 == '\0') {
    *(uint *)(param_1 + 4) = uVar2 & *(uint *)(param_1 + 4);
  }
  else {
    FUN_600cedd8(param_1,param_2,param_3[1],uVar2,param_4);
    *(uint *)(param_1 + 4) = uVar6 | *(uint *)(param_1 + 4);
  }
  cVar1 = param_3[2];
  uVar4 = 1 << (param_2 & 0xff);
  uVar2 = param_2;
  if (0xf < param_2) {
    uVar2 = param_2 - 0x10;
  }
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & ~uVar4;
  if (param_2 < 0x10) {
    puVar5 = (uint *)(param_1 + 0xc);
  }
  else {
    puVar5 = (uint *)(param_1 + 0x10);
  }
  switch(cVar1) {
  case '\x01':
    uVar4 = *puVar5 & ~(3 << ((uVar2 & 0x7f) << 1));
    break;
  case '\x02':
    uVar4 = *puVar5 & ~(3 << ((uVar2 & 0x7f) << 1));
    iVar3 = 1;
    goto LAB_600cee40;
  case '\x03':
    uVar4 = *puVar5 & ~(3 << ((uVar2 & 0x7f) << 1));
    iVar3 = 2;
LAB_600cee40:
    uVar4 = iVar3 << ((uVar2 & 0x7f) << 1) | uVar4;
    break;
  case '\x04':
    uVar4 = 3 << ((uVar2 & 0x7f) << 1) | *puVar5;
    break;
  case '\x05':
    *(uint *)(param_1 + 0x1c) = uVar4 | *(uint *)(param_1 + 0x1c);
  default:
    goto switchD_600cee16_default;
  }
  *puVar5 = uVar4;
switchD_600cee16_default:
  return;
}


