// 600e7718  FUN_600e7718  size=78 bytes
// --- callers ---
//   6008b79c bcm__6008b79c
//   6008e264 bcm__6008e264
//   6008c5fc bcm__6008c5fc
//   600e7efe FUN_600e7efe
//   6008bbdc bcm__6008bbdc
//   6008e700 bcm__6008e700
//   6008c0d8 bcm__6008c0d8
//   6008e910 bcm__6008e910
//   600e7e0e FUN_600e7e0e
//   600e98c6 FUN_600e98c6
//   600e932c FUN_600e932c
//   600e984a FUN_600e984a
//   6008ba20 bcm__6008ba20
//   6008d120 bcm__6008d120
//   600e99a2 FUN_600e99a2
//   600e89f8 FUN_600e89f8
//   6008bf44 bcm__6008bf44
//   600e957c FUN_600e957c
//   600e94ca FUN_600e94ca
// --- callees ---
//   600e093e FUN_600e093e


void FUN_600e7718(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (*(char *)(param_1 + 0x14) != '\0') {
    return;
  }
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 == *(uint *)(param_1 + 0xc)) {
    if (uVar2 == 0) {
      uVar3 = 0x20;
LAB_600e773c:
      iVar1 = FUN_600e093e(*(undefined4 *)(param_1 + 4),uVar3 << 2);
      if (iVar1 != 0) {
        *(int *)(param_1 + 4) = iVar1;
        *(uint *)(param_1 + 0xc) = uVar3;
        goto LAB_600e774a;
      }
    }
    else {
      uVar3 = uVar2 * 3 >> 1;
      if ((uVar2 < uVar3) && (uVar3 < 0x40000000)) goto LAB_600e773c;
    }
    *(undefined2 *)(param_1 + 0x14) = 0x101;
  }
  else {
LAB_600e774a:
    *(undefined4 *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8) * 4) = uVar4;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  return;
}


