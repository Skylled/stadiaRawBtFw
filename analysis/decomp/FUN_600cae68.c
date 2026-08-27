// 600cae68  FUN_600cae68  size=70 bytes
// --- callers ---
//   6006bc20 FUN_6006bc20
//   600caf64 FUN_600caf64
// --- callees ---
//   601024a4 FUN_601024a4


void FUN_600cae68(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = DAT_600caeb8;
  uVar2 = DAT_600caeb4;
  iVar1 = DAT_600caeb0;
  iVar4 = DAT_600caeb0 + 7;
  *(undefined4 *)(DAT_600caeb0 + 0x18) = DAT_600caeb4;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  *(undefined4 *)(iVar1 + 0x14) = 1;
  *(undefined4 *)(iVar1 + 0x1c) = DAT_600caebc;
  *(undefined4 *)(iVar1 + 0x20) = 0x400;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0x30) = uVar2;
  uVar2 = DAT_600caec0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x34) = uVar2;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x40) = 0;
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x38) = 0x10;
  FUN_601024a4(iVar4,uVar3);
  FUN_601024a4(iVar1,DAT_600caec4);
  *(undefined1 *)(iVar1 + 6) = 0x20;
  return;
}


