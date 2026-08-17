// 600bc1f8  FUN_600bc1f8  size=162 bytes
// --- callers ---
//   600b6900 FUN_600b6900
// --- callees ---


void FUN_600bc1f8(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((*(char *)(param_2 + 6) != '\0') && (*(char *)(param_1 + 0x12) != '\0')) {
    uVar1 = *(undefined4 *)(param_2 + 0xc);
    uVar2 = *(undefined4 *)(param_2 + 0x10);
    uVar3 = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)(param_1 + 0x18) = uVar1;
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    *(undefined4 *)(param_1 + 0x20) = uVar3;
    uVar1 = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0x18);
    *(undefined4 *)(param_1 + 0x28) = uVar1;
  }
  if (*(char *)(param_2 + 0x24) != '\0') {
    if (*(char *)(param_2 + 0x26) == '\x03') {
      *(undefined2 *)(param_1 + 0x82) = *(undefined2 *)(param_2 + 0x2a);
      *(undefined2 *)(param_1 + 0x84) = *(undefined2 *)(param_2 + 0x2c);
    }
    if (*(byte *)(param_2 + 0x27) < *(byte *)(param_1 + 0x33)) {
      *(char *)(param_1 + 0xb5) =
           (char)(uint)((ulonglong)DAT_600bc29c * (ulonglong)*(byte *)(param_2 + 0x27) >> 0x21);
    }
    else {
      *(char *)(param_1 + 0xb5) =
           (char)(uint)((ulonglong)DAT_600bc29c * (ulonglong)*(byte *)(param_1 + 0x33) >> 0x21);
    }
  }
  return;
}


