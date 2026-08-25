// 600fa018  FUN_600fa018  size=76 bytes
// --- callers ---
//   600b6900 FUN_600b6900
// --- callees ---
//   600f85f8 FUN_600f85f8


void FUN_600fa018(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((*(char *)(param_2 + 6) == '\0') || (*(char *)(param_1 + 0x5e) == '\0')) {
    *(undefined1 *)(param_2 + 6) = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 0xc);
    uVar2 = *(undefined4 *)(param_2 + 0x10);
    uVar3 = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)(param_1 + 100) = uVar1;
    *(undefined4 *)(param_1 + 0x68) = uVar2;
    *(undefined4 *)(param_1 + 0x6c) = uVar3;
    uVar1 = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_2 + 0x18);
    *(undefined4 *)(param_1 + 0x74) = uVar1;
  }
  FUN_600f85f8(param_1,param_2);
  return;
}


