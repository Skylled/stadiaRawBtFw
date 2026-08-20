// 600e77c0  FUN_600e77c0  size=20 bytes
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


void FUN_600e77c0(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x14) == '\0') {
    iVar1 = *(int *)(param_1 + 8) + -1;
    *(int *)(param_1 + 8) = iVar1;
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 4) + iVar1 * 4);
  }
  return;
}


