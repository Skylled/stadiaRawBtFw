// 600e0680  FUN_600e0680  size=22 bytes
// --- callers ---
//   6008506c evp__6008506c
//   600e0696 FUN_600e0696
// --- callees ---


void FUN_600e0680(int param_1)

{
  code *pcVar1;
  
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (pcVar1 = *(code **)(*(int *)(param_1 + 0xc) + 0x4c), pcVar1 != (code *)0x0)) {
    (*pcVar1)();
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


