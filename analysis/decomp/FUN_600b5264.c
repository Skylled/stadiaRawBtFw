// 600b5264  FUN_600b5264  size=446 bytes
// --- callers ---
//   600c1b20 FUN_600c1b20
//   600ff986 FUN_600ff986
// --- callees ---
//   600bc880 FUN_600bc880
//   600a01a0 FUN_600a01a0
//   6006ddd8 FUN_6006ddd8
//   600b720c FUN_600b720c
//   600b9408 FUN_600b9408
//   600bb6dc FUN_600bb6dc
//   600fa0d6 FUN_600fa0d6


undefined4 FUN_600b5264(ushort param_1,undefined4 param_2,undefined2 *param_3)

{
  int iVar1;
  char *pcVar2;
  byte local_a;
  char local_9;
  
  local_9 = '\x01';
  if ((3 < param_1) && (param_1 < 7)) {
    local_9 = '\x02';
  }
  if (((param_1 < 4) || (7 < param_1)) ||
     (*(int *)((param_1 - 4) * 0x1c + DAT_600b5424 + 0xed4) == 0)) {
    FUN_6006ddd8(param_3,DAT_600b5428,0x5f6);
    return 0;
  }
  iVar1 = FUN_600a01a0();
  if (iVar1 == 0) {
    FUN_6006ddd8(param_3,DAT_600b5428,0x5fe);
    return 0;
  }
  pcVar2 = (char *)FUN_600bb6dc(param_2,local_9);
  if ((pcVar2 == (char *)0x0) || (pcVar2[1] == '\x05')) {
    FUN_6006ddd8(param_3,DAT_600b5428,0x608);
    return 0;
  }
  local_a = pcVar2[0x24];
  if (local_9 == '\x02') {
    local_a = *(byte *)(DAT_600b5424 + 0xf4e);
  }
  if (((int)(uint)local_a >> (param_1 & 0xff) & 1U) == 0) {
    FUN_6006ddd8(param_3,DAT_600b5428,0x616);
    return 0;
  }
  *param_3 = 0;
  param_3[3] = 0;
  if ((*(int *)(pcVar2 + (param_1 + 0x20) * 4) == 0) &&
     (iVar1 = FUN_600bc880(pcVar2,param_1,(param_1 - 4) * 0x1c + DAT_600b5424 + 0xedc), iVar1 == 0))
  {
    FUN_6006ddd8(param_3,DAT_600b5428,0x623);
    return 0;
  }
  if (*(char *)(*(int *)(pcVar2 + (param_1 + 0x20) * 4) + 0xa0) != '\0') {
    FUN_6006ddd8(param_3,DAT_600b5428,0x631);
    return 0;
  }
  FUN_600b720c(*(undefined4 *)(pcVar2 + (param_1 + 0x20) * 4),param_3);
  FUN_600b9408(pcVar2,0,0);
  if (((*pcVar2 != '\0') && (pcVar2[1] == '\x04')) && (*(int *)(pcVar2 + 0x5c) == 0)) {
    FUN_600fa0d6(pcVar2);
  }
  if (((*pcVar2 != '\0') && (*(int *)(pcVar2 + (param_1 + 0x20) * 4) != 0)) &&
     (*(char *)(*(int *)(pcVar2 + (param_1 + 0x20) * 4) + 0xa0) != '\0')) {
    return 2;
  }
  return 1;
}


