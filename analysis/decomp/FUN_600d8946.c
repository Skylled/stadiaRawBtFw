// 600d8946  FUN_600d8946  size=42 bytes
// --- callers ---
//   60069c58 adapter__60069c58
//   600d8970 FUN_600d8970
//   60069a38 adapter__60069a38
// --- callees ---


short * FUN_600d8946(undefined4 *param_1,short param_2)

{
  short *psVar1;
  short *psVar2;
  
  psVar1 = (short *)*param_1;
  do {
    psVar2 = psVar1;
    if (psVar2 == (short *)*param_1 + param_1[1] * 0xcca) {
      return (short *)0x0;
    }
    psVar1 = psVar2 + 0xcca;
  } while (*psVar2 != param_2);
  return psVar2;
}


