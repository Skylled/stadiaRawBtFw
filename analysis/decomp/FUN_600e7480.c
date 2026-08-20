// 600e7480  FUN_600e7480  size=16 bytes
// --- callers ---
//   6008b970 bcm__6008b970
//   6008bae0 bcm__6008bae0
//   600e9a16 FUN_600e9a16
//   600e7b82 FUN_600e7b82
//   6008bbdc bcm__6008bbdc
//   600e94b6 FUN_600e94b6
//   6008d120 bcm__6008d120
//   600e7ccc FUN_600e7ccc
//   6008bb90 bcm__6008bb90
//   600e966c FUN_600e966c
// --- callees ---
//   600e7434 FUN_600e7434


void FUN_600e7480(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_600e7434();
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


